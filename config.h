// Copyright 2024 Vito (@VitoBarra)
// SPDX-License-Identifier: MIT

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */


#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

#define MOUSEKEY_TIME_TO_MAX 0
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 60000
#endif

#ifdef TAP_DANCE_ENABLE
#   define TAPPING_TERM 175
#endif

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
