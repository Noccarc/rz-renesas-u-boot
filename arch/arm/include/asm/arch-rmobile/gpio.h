#ifndef __ASM_ARCH_GPIO_H
#define __ASM_ARCH_GPIO_H

#if defined(CONFIG_SH73A0)
#include "sh73a0-gpio.h"
void sh73a0_pinmux_init(void);
#elif defined(CONFIG_R8A7740)
#include "r8a7740-gpio.h"
void r8a7740_pinmux_init(void);
#elif defined(CONFIG_R8A7790)
#include "r8a7790-gpio.h"
void r8a7790_pinmux_init(void);
#elif defined(CONFIG_R8A7791)
#include "r8a7791-gpio.h"
void r8a7791_pinmux_init(void);
#elif defined(CONFIG_IWG20M)
#include "iwg20m-gpio.h"
void iwg20m_pinmux_init(void);
#elif defined(CONFIG_IWG22M)
#include "iwg22m-gpio.h"
void iwg22m_pinmux_init(void);
#elif defined(CONFIG_R8A7793)
#include "r8a7793-gpio.h"
void r8a7793_pinmux_init(void);
#elif defined(CONFIG_R8A7794)
#include "r8a7794-gpio.h"
void r8a7794_pinmux_init(void);
#elif defined(CONFIG_R8A7742)
#include "r8a7742-gpio.h"
void r8a7742_pinmux_init(void);
#elif defined(CONFIG_IWG21M)
#include "iwg21m-gpio.h"
void iwg21m_pinmux_init(void);
#elif defined(CONFIG_R8A7743)
#include "r8a7743-gpio.h"
void r8a7743_pinmux_init(void);
#elif defined(CONFIG_R8A7745)
#include "r8a7745-gpio.h"
void r8a7745_pinmux_init(void);
#elif defined(CONFIG_R8A7747X)
#include "r8a7747x-gpio.h"
void r8a7747x_pinmux_init(void);
#endif

#endif /* __ASM_ARCH_GPIO_H */