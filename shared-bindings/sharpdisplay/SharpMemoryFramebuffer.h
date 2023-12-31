/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Jeff Epler for Adafruit Industries
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

#pragma once

#include "py/objtype.h"

#include "shared-module/sharpdisplay/SharpMemoryFramebuffer.h"

extern const mp_obj_type_t sharpdisplay_framebuffer_type;

void common_hal_sharpdisplay_framebuffer_construct(sharpdisplay_framebuffer_obj_t *self, busio_spi_obj_t *spi, const mcu_pin_obj_t *chip_select, int baudrate, int width, int height, bool jdi_display);
void common_hal_sharpdisplay_framebuffer_swap_buffers(sharpdisplay_framebuffer_obj_t *self, uint8_t *dirty_row_bitmask);
void common_hal_sharpdisplay_framebuffer_deinit(sharpdisplay_framebuffer_obj_t *self);
void common_hal_sharpdisplay_framebuffer_get_bufinfo(sharpdisplay_framebuffer_obj_t *self, mp_buffer_info_t *bufinfo);
int common_hal_sharpdisplay_framebuffer_get_height(sharpdisplay_framebuffer_obj_t *self);
int common_hal_sharpdisplay_framebuffer_get_width(sharpdisplay_framebuffer_obj_t *self);
void common_hal_sharpdisplay_framebuffer_swap_buffers(sharpdisplay_framebuffer_obj_t *self, uint8_t *dirty_row_bitmask);
void common_hal_sharpdisplay_framebuffer_reset(sharpdisplay_framebuffer_obj_t *self);
void common_hal_sharpdisplay_framebuffer_reconstruct(sharpdisplay_framebuffer_obj_t *self);
