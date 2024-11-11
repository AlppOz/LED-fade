/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int led = 3;         // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is at the start
int fadeAmount = 100;  // how many points to fade the LED on each loop until the maximum 255. Lower values give more gradual fades whereas higher values result in blinking-like flashes
int wavelength = 50; // the waittime in miliseconds per each voltage ('wave') and thus dim. Lower values increase the frequency of the changing dimming effect and higher values make dimming slower

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever where on each loop a new brightness will be defined:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for some milliseconds to see the dimming effect
  delay(wavelength);
}