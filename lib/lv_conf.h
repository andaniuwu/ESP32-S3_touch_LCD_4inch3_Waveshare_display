#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/* Match the original project setup closely enough for display and touch polling. */
#define LV_COLOR_DEPTH 16

#define LV_MEM_CUSTOM 1
#if LV_MEM_CUSTOM
    #define LV_MEM_CUSTOM_INCLUDE <stdlib.h>
    #define LV_MEM_CUSTOM_ALLOC   malloc
    #define LV_MEM_CUSTOM_FREE    free
    #define LV_MEM_CUSTOM_REALLOC realloc
#endif

#define LV_MEMCPY_MEMSET_STD 1

#define LV_DISP_DEF_REFR_PERIOD 16
#define LV_INDEV_DEF_READ_PERIOD 16

#define LV_TICK_CUSTOM 1
#if LV_TICK_CUSTOM
    #define LV_TICK_CUSTOM_INCLUDE "Arduino.h"
    #define LV_TICK_CUSTOM_SYS_TIME_EXPR (millis())
#endif

#define LV_DPI_DEF 130

#define LV_USE_LOG 0

#define LV_USE_ASSERT_NULL 1
#define LV_USE_ASSERT_MALLOC 1
#define LV_USE_ASSERT_STYLE 0
#define LV_USE_ASSERT_MEM_INTEGRITY 0
#define LV_USE_ASSERT_OBJ 0

#define LV_ASSERT_HANDLER_INCLUDE <stdint.h>
#define LV_ASSERT_HANDLER while(1);

#define LV_SPRINTF_CUSTOM 0
#if !LV_SPRINTF_CUSTOM
    #define LV_SPRINTF_USE_FLOAT 0
#endif

#define LV_USE_USER_DATA 1

#define LV_ATTRIBUTE_FAST_MEM IRAM_ATTR

#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_30 1
#define LV_FONT_DEFAULT &lv_font_montserrat_14

#define LV_TXT_ENC LV_TXT_ENC_UTF8

#endif