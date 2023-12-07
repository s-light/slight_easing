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

#include "slight_easing.h"

#include <math.h>

// template <typename T> const T &easeInCubic(const T &x) { return x * x * x; }

// https://stackoverflow.com/a/25730573/574981
float easeBezierBlend(float x) { return x * x * (3.0f - 2.0f * x); }

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// from here on source
// https://github.com/warrenm/AHEasing/blob/master/AHEasing/easing.c

// Modeled after the line y = x
float easeLinear(float p) { return p; }

// Modeled after the parabola y = x^2
float easeQuadraticIn(float p) { return p * p; }

// Modeled after the parabola y = -x^2 + 2x
float easeQuadraticOut(float p) { return -(p * (p - 2)); }

// Modeled after the piecewise quadratic
// y = (1/2)((2x)^2)             ; [0, 0.5)
// y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
float easeQuadraticInOut(float p) {
    if (p < 0.5) {
        return 2 * p * p;
    } else {
        return (-2 * p * p) + (4 * p) - 1;
    }
}

// Modeled after the cubic y = x^3
float easeCubicIn(float p) { return p * p * p; }

// Modeled after the cubic y = (x - 1)^3 + 1
float easeCubicOut(float p) {
    float f = (p - 1);
    return f * f * f + 1;
}

// Modeled after the piecewise cubic
// y = (1/2)((2x)^3)       ; [0, 0.5)
// y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
float easeCubicInOut(float p) {
    if (p < 0.5) {
        return 4 * p * p * p;
    } else {
        float f = ((2 * p) - 2);
        return 0.5 * f * f * f + 1;
    }
}

// Modeled after the quartic x^4
float easeQuarticIn(float p) { return p * p * p * p; }

// Modeled after the quartic y = 1 - (x - 1)^4
float easeQuarticOut(float p) {
    float f = (p - 1);
    return f * f * f * (1 - p) + 1;
}

// Modeled after the piecewise quartic
// y = (1/2)((2x)^4)        ; [0, 0.5)
// y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
float easeQuarticInOut(float p) {
    if (p < 0.5) {
        return 8 * p * p * p * p;
    } else {
        float f = (p - 1);
        return -8 * f * f * f * f + 1;
    }
}

// Modeled after the quintic y = x^5
float easeQuinticIn(float p) { return p * p * p * p * p; }

// Modeled after the quintic y = (x - 1)^5 + 1
float easeQuinticOut(float p) {
    float f = (p - 1);
    return f * f * f * f * f + 1;
}

// Modeled after the piecewise quintic
// y = (1/2)((2x)^5)       ; [0, 0.5)
// y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
float easeQuinticInOut(float p) {
    if (p < 0.5) {
        return 16 * p * p * p * p * p;
    } else {
        float f = ((2 * p) - 2);
        return 0.5 * f * f * f * f * f + 1;
    }
}

// Modeled after quarter-cycle of sine wave
float easeSineIn(float p) { return sin((p - 1) * M_PI_2) + 1; }

// Modeled after quarter-cycle of sine wave (different phase)
float easeSineOut(float p) { return sin(p * M_PI_2); }

// Modeled after half sine wave
float easeSineInOut(float p) { return 0.5 * (1 - cos(p * M_PI)); }

// Modeled after shifted quadrant IV of unit circle
float easeCircularIn(float p) { return 1 - sqrt(1 - (p * p)); }

// Modeled after shifted quadrant II of unit circle
float easeCircularOut(float p) { return sqrt((2 - p) * p); }

// Modeled after the piecewise circular function
// y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
// y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
float easeCircularInOut(float p) {
    if (p < 0.5) {
        return 0.5 * (1 - sqrt(1 - 4 * (p * p)));
    } else {
        return 0.5 * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
    }
}

// Modeled after the exponential function y = 2^(10(x - 1))
float easeExponentialIn(float p) {
    return (p == 0.0) ? p : pow(2, 10 * (p - 1));
}

// Modeled after the exponential function y = -2^(-10x) + 1
float easeExponentialOut(float p) {
    return (p == 1.0) ? p : 1 - pow(2, -10 * p);
}

// Modeled after the piecewise exponential
// y = (1/2)2^(10(2x - 1))         ; [0,0.5)
// y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
float easeExponentialInOut(float p) {
    if (p == 0.0 || p == 1.0)
        return p;

    if (p < 0.5) {
        return 0.5 * pow(2, (20 * p) - 10);
    } else {
        return -0.5 * pow(2, (-20 * p) + 10) + 1;
    }
}
