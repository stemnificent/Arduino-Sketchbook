/**@file*/
/* note the line above is required for doxygen to look at this file */
/**
 * @file Voltage_Flip1
 * @author Coach J
 * @date March 11, 2017
 * @brief Used for basic resistor soil moisture sensor.
 * @details Passes voltage back and forth between two resistors. With two galvanized
 * metal rods between them it creates an AC current that tests for moisture. A zero
 * indicates the probes are in water. 900 or more indicates soil is moist. Got the
 * how to from http://gardenbot.org/howTo/soilMoisture/#The_local_circuit_-_simple_voltage
**/

// ATMEL ATTINY841 / ARDUINO
//
//                                 +-\/-+
//                           VCC  1|    |14  GND
//  ADC11            (D  0)  PB0  2|    |13  AREF (D 10)              ADC0
//  ADC10      _____ (D  1)  PB1  3|    |12  PA1  (D  9)  TX0         ADC1
//  ADC9       RESET (D 11)  PB3  4|    |11  PA2  (D  8)  RX0         ADC2
//  ADC8  PWM  INT0  (D  2)  PB2  5|    |10  PA3  (D  7)        PWM   ADC3
//  ADC7  PWM        (D  3)  PA7  6|    |9   PA4  (D  6)  RX1   PWM   ADC4
//  ADC6  PWM        (D  4)  PA6  7|    |8   PA5  (D  5)  TX1   PWM   ADC5
//                                 +----+
//

//#define voltageFlipPin1 2
//#define voltageFlipPin2 3
//#define LED 0
//#define sensorPin 1

const int sensorPin = A0;
const int voltageFlipPin1 = A3; // A3 = D7
const int voltageFlipPin2 = A4; // A4 = D6
const int LED = A1;


int flipTimer = 1000;

void setup(){
  pinMode(voltageFlipPin1, OUTPUT);
  pinMode(voltageFlipPin2, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(sensorPin, INPUT);
}

// creates AC current - right to left and left to right
void setSensorPolarity(boolean flip){
  if(flip) {
    digitalWrite(voltageFlipPin1, HIGH);
    digitalWrite(voltageFlipPin2, LOW);
  } else {
   digitalWrite(voltageFlipPin1, LOW);
   digitalWrite(voltageFlipPin2, HIGH);
  }
}


void loop(){
  setSensorPolarity(true);
  delay(flipTimer);
  
  int val1 = analogRead(sensorPin);
  delay(flipTimer);  
  setSensorPolarity(false);
  delay(flipTimer);

  // invert the reading
  int val2 = 1023 - analogRead(sensorPin);

  //
  reportLevels(val1,val2);
}


void reportLevels(int val1,int val2) {

  int avg = (val1 + val2) / 2;

  int brightnessLED = map(avg,0,1000, 0, 256);

  analogWrite(LED, brightnessLED);  
}

