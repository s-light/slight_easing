/******************************************************************************

    very simple easing functions

    written by Stefan Krüger (s-light),
        github@s-light.eu, http://s-light.eu, https://github.com/s-light/

    these functions are based these sources
    - https://github.com/warrenm/AHEasing/blob/master/AHEasing/easing.c
    - https://easings.net
    - and others (link at function)

******************************************************************************/
/******************************************************************************
The MIT License (MIT)

Copyright (c) 2023 Stefan Krüger

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef slight_easing_H_
#define slight_easing_H_

// include Core Arduino functionality
#include <Arduino.h>

// call back functions
#if defined(ARDUINO_ARCH_AVR)
using tEasingFunction = float (*)(float p);
#elif defined(ARDUINO_ARCH_SAMD) || defined(ARDUINO_ARCH_ESP32)
using tEasingFunction = std::function<float(float p)>;
#else
    #error Architecture Not implemented yet. please create a pull-request :-)
#endif

// template <typename T> const T &easeInCubic(const T &x) { return x * x * x; }

// https://stackoverflow.com/a/25730573/574981
float easeBezierBlend(float x);

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// from here on source
// https://github.com/warrenm/AHEasing/blob/master/AHEasing/easing.c

float easeLinear(float p);

float easeQuadraticIn(float p);
float easeQuadraticOut(float p);
float easeQuadraticInOut(float p);

float easeCubicIn(float p);
float easeCubicOut(float p);
float easeCubicInOut(float p);

float easeQuarticIn(float p);
float easeQuarticOut(float p);
float easeQuarticInOut(float p);

float easeQuinticIn(float p);
float easeQuinticOut(float p);
float easeQuinticInOut(float p);

float easeSineIn(float p);
float easeSineOut(float p);
float easeSineInOut(float p);

float easeCircularIn(float p);
float easeCircularOut(float p);
float easeCircularInOut(float p);

float easeExponentialIn(float p);
float easeExponentialOut(float p);
float easeExponentialInOut(float p);

#endif // slight_easing_H_
