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

#ifndef MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_SERVICE_H
#define MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_SERVICE_H

#include "py/objlist.h"
#include "common-hal/_bleio/UUID.h"

#define MAX_NUMBER_SERVICE 64

typedef struct bleio_service_obj
{
    mp_obj_base_t base;
    // Handle for the local service.
    uint32_t handle;
    // True if created during discovery.
    bool is_remote;
    bool is_secondary;
    bleio_uuid_obj_t *uuid;
    // The connection object is set only when this is a remote service.
    // A local service doesn't know the connection.
    mp_obj_t connection;
    mp_obj_list_t *characteristic_list;
    // Range of attribute handles of this remote service.
    uint16_t start_handle;
    uint16_t end_handle;
} bleio_service_obj_t;

typedef struct
{
    bleio_service_obj_t *data[MAX_NUMBER_SERVICE];
    uint8_t len;
} bleio_service_obj_list;

void bleio_service_from_connection(bleio_service_obj_t *self,
    mp_obj_t connection);
uint16_t get_characteristic_handle(bleio_uuid_obj_t *uuid);
extern void reset_dynamic_service();
#endif // MICROPY_INCLUDED_EFR_COMMON_HAL_BLEIO_SERVICE_H
