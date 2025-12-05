#include "AudioEffectHello.h"

void AudioEffectHello::update(void)
{
    audio_block_t *in = receiveReadOnly(0);
    if (!in) return;

    audio_block_t *out = allocate();
    if (!out) {
        release(in);
        return;
    }

    // Hard-coded: double speed (pitch up 1 octave)
    float readIndex = 0.0f;
    float pitch = 2.0f;  // 2.0 = double speed

    for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {

        int idx = (int)readIndex;
        float frac = readIndex - idx;

        // clamp index to avoid overflow
        int idx1 = (idx < AUDIO_BLOCK_SAMPLES - 1) ? idx + 1 : idx;

        // linear interpolation
        float sample = (1.0f - frac) * in->data[idx] + frac * in->data[idx1];

        out->data[i] = (int16_t)sample;

        readIndex += pitch;

        // wrap around so we stay within block
        if (readIndex >= AUDIO_BLOCK_SAMPLES) {
            readIndex -= AUDIO_BLOCK_SAMPLES;
        }
    }

    transmit(out);
    release(out);
    release(in);
}
