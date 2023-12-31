/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Scott Shawcroft for Adafruit Industries
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

#ifndef MICROPY_INCLUDED_SHARED_BINDINGS_AUDIOMIXER_MIXER_H
#define MICROPY_INCLUDED_SHARED_BINDINGS_AUDIOMIXER_MIXER_H

#include "shared-module/audiomixer/Mixer.h"

extern const mp_obj_type_t audiomixer_mixer_type;
extern const mp_obj_type_t audiomixer_mixervoice_type;

void common_hal_audiomixer_mixer_construct(audiomixer_mixer_obj_t *self,
    uint8_t voice_count,
    uint32_t buffer_size,
    uint8_t bits_per_sample,
    bool samples_signed,
    uint8_t channel_count,
    uint32_t sample_rate);

void common_hal_audiomixer_mixer_deinit(audiomixer_mixer_obj_t *self);
bool common_hal_audiomixer_mixer_deinited(audiomixer_mixer_obj_t *self);

bool common_hal_audiomixer_mixer_get_playing(audiomixer_mixer_obj_t *self);
uint32_t common_hal_audiomixer_mixer_get_sample_rate(audiomixer_mixer_obj_t *self);
uint8_t common_hal_audiomixer_mixer_get_channel_count(audiomixer_mixer_obj_t *self);
uint8_t common_hal_audiomixer_mixer_get_bits_per_sample(audiomixer_mixer_obj_t *self);

#endif // MICROPY_INCLUDED_SHARED_BINDINGS_AUDIOMIXER_MIXER_H
