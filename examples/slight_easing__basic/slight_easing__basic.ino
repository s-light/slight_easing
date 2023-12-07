/******************************************

    slight_easing__minimal.ino
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

    Serial.println(F("slight_easing__minimal.ino sketch."));
    Serial.println(F("minimal example for library usage."));
}

void printEasingFunction() {
    float y = 0.0;
    for (float x = 0.0; x < 1.0; x = x + 0.05) {
        Serial.print(x, 3);
        Serial.print("; ");
        float y = easeBezierBlend(x);
        Serial.print(y, 3);
        Serial.println();
    }
}

void loop() {
    printEasingFunction();
    delay(10 * 1000);
}
