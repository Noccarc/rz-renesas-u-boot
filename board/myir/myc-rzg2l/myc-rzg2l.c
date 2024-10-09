#include <common.h>
#include <cpu_func.h>
#include <image.h>
#include <init.h>
#include <malloc.h>
#include <netdev.h>
#include <dm.h>
#include <dm/platform_data/serial_sh.h>
#include <asm/processor.h>
#include <asm/mach-types.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <linux/errno.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <asm/arch/rmobile.h>
#include <asm/arch/rcar-mstp.h>
#include <asm/arch/sh_sdhi.h>
#include <i2c.h>
#include <mmc.h>
#include <linux/delay.h>

/* WDT */
#define WDT_INDEX               0

DECLARE_GLOBAL_DATA_PTR;

#define PFC_BASE	0x11030000

/* I2C */

#define I2C_CH1         (PFC_BASE + 0x1870)

/* CPG */
#define CPG_BASE					0x11010000
#define CPG_CLKON_BASE				(CPG_BASE + 0x500)
#define CPG_RESET_BASE				(CPG_BASE + 0x800)
#define CPG_RESET_ETH				(CPG_RESET_BASE + 0x7C)
#define CPG_RESET_I2C                           (CPG_RESET_BASE + 0x80)
#define CPG_PL2_SDHI_DSEL                           (CPG_BASE + 0x218)
#define CPG_CLK_STATUS                           (CPG_BASE + 0x280)

/* PFC */
#define PFC_P37						(PFC_BASE + 0x037)
#define PFC_PM37					(PFC_BASE + 0x16E)
#define PFC_PMC37					(PFC_BASE + 0x237)


#define PFC_P37                               (PFC_BASE + 0x037)
#define PFC_PM37                              (PFC_BASE + 0x16E)
#define PFC_PMC37                             (PFC_BASE + 0x237)

/*P44_3*/
#define PFC_P3C                               (PFC_BASE + 0x03C)
#define PFC_PM3C                              (PFC_BASE + 0x178)
#define PFC_PMC3C                             (PFC_BASE + 0x23C)
/*P43_3*/
#define PFC_P3B                               (PFC_BASE + 0x03B)
#define PFC_PM3B                              (PFC_BASE + 0x176)
#define PFC_PMC3B                             (PFC_BASE + 0x23B)

void s_init(void)
{
	/* SD1 power control: P39_1 = 0; P39_2 = 1; */
	*(volatile u32 *)(PFC_PMC37) &= 0xFFFFFFF9; /* Port func mode 0b00 */
	*(volatile u32 *)(PFC_PM37) = (*(volatile u32 *)(PFC_PM37) & 0xFFFFFFC3) | 0x28; /* Port output mode 0b1010 */
//#if CONFIG_TARGET_SMARC_RZG2L
#if CONFIG_TARGET_MYC_RZG2L
	*(volatile u32 *)(PFC_P37) = (*(volatile u32 *)(PFC_P37) & 0xFFFFFFF9) | 0x6;	/* Port 39[2:1] output value 0b11*/
#else

	*(volatile u32 *)(PFC_P37) = (*(volatile u32 *)(PFC_P37) & 0xFFFFFFF9) | 0x4;	/* Port 39[2:1] output value 0b10*/
#endif

	
	/* I2C CLK */
	*(volatile u32 *)(CPG_RESET_I2C) = 0xF000F;
	/* I2C pin non GPIO enable */
	*(volatile u32 *)(I2C_CH1) = 0x01010101;
	/* SD CLK */
	*(volatile u32 *)(CPG_PL2_SDHI_DSEL) = 0x00110011;
	while (*(volatile u32 *)(CPG_CLK_STATUS) != 0)
		;
}

int board_early_init_f(void)
{

	return 0;
}

int board_init(void)
{
	/* adress of boot parameters */
	gd->bd->bi_boot_params = CONFIG_SYS_TEXT_BASE + 0x50000;

	mdelay(140);

	if (CONFIG_IS_ENABLED(LED))
		led_default_state();

	return 0;
}


void reset_cpu(void)
{

   #ifdef CONFIG_RENESAS_RZG2LWDT
	struct udevice *wdt_dev;
	if (uclass_get_device(UCLASS_WDT, WDT_INDEX, &wdt_dev) < 0) {
		printf("failed to get wdt device. cannot reset\n");
		return;
	}
	if (wdt_expire_now(wdt_dev, 0) < 0) {
		printf("failed to expire_now wdt\n");
	}
   #endif // CONFIG_RENESAS_RZG2LWDT
}
