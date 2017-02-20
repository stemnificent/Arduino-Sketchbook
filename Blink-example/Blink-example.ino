/**@file*/
/**
 * @file Blink-example.ino
 * @author Coach J
 * @date Feb 19, 2017
 * @brief Arduino code exmaple of blinking the onboard LED.
 *
 * Blink
 *  Turns on an LED on for one second, then off for one second, repeatedly.
 *
 *  Most Arduinos have an on-board LED you can control. On the Uno and
 *  Leonardo, it is attached to digital pin 13. If you're unsure what
 *  pin the on-board LED is connected to on your Arduino model, check
 *  the documentation at http://www.arduino.cc
 *
 *  This example code is in the public domain.
 *
 *  modified 8 May 2014
 * by Scott Fitzgerald
 */

/* add comment to see if the right account appears in github desktop */

/**
 * @function the setup function runs once when you press reset or power the board
 *
 * Detailed explanation.
 */
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

/**
 * @function the loop function runs over and over again forever
 *
 * Detailed explanation.
 */

void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
