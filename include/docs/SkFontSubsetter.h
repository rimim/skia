/*
 * Copyright 2020 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkFontSubsetter_DEFINED
#define SkFontSubsetter_DEFINED

#include "include/core/SkTypes.h"
#include "include/core/SkFlattenable.h"

#include <vector>

class SkData;

/**
 *  Base-class for font subsetters.
 */
class SK_API SkFontSubsetter : public SkFlattenable {
public:
    bool prepare(sk_sp<SkData> fontData, const char* fontName, int ttcIndex) {
        return onPrepare(fontData, fontName, ttcIndex);
    }

    bool add(SkUnichar codepoint) {
        return add(&codepoint, 1);
    }
    
    bool add(SkUnichar* codepoints, size_t count);
    
    sk_sp<SkData> complete() {
        return onComplete();
    }

protected:
    SkFontSubsetter();

    virtual bool onPrepare(sk_sp<SkData> fontData, const char* fontName, int ttcIndex) = 0;
    virtual bool onAdd(SkUnichar* codepoints, size_t count) = 0;
    virtual sk_sp<SkData> onComplete() = 0;
};

#endif
