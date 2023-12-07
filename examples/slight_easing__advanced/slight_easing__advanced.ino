/******************************************

    slight_easing__advanced.ino
        minimal example for library usage.
        debugport: serial interface 115200baud

    hardware:
        Arduino board of any type.

    libraries used:
        ~ slight_easing

    written by Stefan Krüger (s-light),
        git@s-light.eu, http://s-light.eu, https://github.com/s-light/

    This Example Sketch is released as CC0
******************************************/

#include <slight_easing.h>

void setup() {
    delay(1000);
    Serial.begin(115200);
    delay(500);
    Serial.println();

    Serial.println(F("slight_easing__advanced.ino sketch."));
    Serial.println(F("advanced example for library usage."));

    // TODO: write example for easing usage..
}

void printEasingFunction(tEasingFunction easingFN) {
    float y = 0.0;
    for (float x = 0.0; x < 1.0; x = x + 0.05) {
        Serial.print(x, 3);
        Serial.print("=");
        float y = easingFN(x);
        Serial.print(y, 3);
    }
}

void loop() {
    printEasingFunction(easeBezierBlend);
    delay(2 * 1000);
    printEasingFunction(easeCubicIn);
    delay(2 * 1000);
    printEasingFunction(easeCubicInOut);
    delay(2 * 1000);
    
    delay(10 * 1000);
}
