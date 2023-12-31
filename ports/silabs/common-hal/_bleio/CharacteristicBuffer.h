/*
 * This file is part of Adafruit for EFR32 project
 *
 * The MIT License (MIT)
 *
 * Copyright 2023 Silicon Laboratories Inc. www.silabs.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_CHARACTERISTICBUFFER_H
#define MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_CHARACTERISTICBUFFER_H

#include "py/ringbuf.h"
#include "shared-bindings/_bleio/Characteristic.h"

#define MAX_NUMBER_CHARACTERISTIC_BUFFER 64
#define GET_CHARACTERISTIC_TIMEOUT_MS 1000
typedef struct {
    mp_obj_base_t base;
    bleio_characteristic_obj_t *characteristic;
    uint32_t timeout_ms;
    // Ring buffer storing consecutive incoming values
    ringbuf_t ringbuf;
    bool watch_for_interrupt_char;
} bleio_characteristic_buffer_obj_t;

typedef struct
{
    bleio_characteristic_buffer_obj_t *data[MAX_NUMBER_CHARACTERISTIC_BUFFER];
    uint8_t len;
} bleio_characteristic_buffer_obj_list_t;

extern bleio_characteristic_buffer_obj_list_t bleio_characteristic_buffer_list;
extern bool characteristic_buffer_on_ble_evt(uint16_t attribute,
    uint8_t *data,
    uint16_t len);
extern void reset_characteristic_buffer_list();
#endif // MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_CHARACTERISTICBUFFER_H
