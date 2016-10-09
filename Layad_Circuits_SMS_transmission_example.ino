/*
 * Copyright 2016 (C) layadcircuits.com
 * Project: 
 * Example code for sending an SMS using the SIM900 or SIM800 based boards from Layad Circuits
 * Author: Chris Malecdan / chris@layadcircuits.com
 * For Questions/Comments: chris@layadcircuits.com
 * Revision History:
 * 1.0 - initial commit / 09 Oct 2016
 * 
 * Connections:
 * GSM TX pin = Arduino UNO pin 2 (apply voltage divider if your board has a 3.3V logic, 4.7k in series and 10k to ground)
 * GSM RX pin = Arduino UNO pin 3
 * GSM GND = Arduino UNO GND
 * Power Rating = Voltage is dependent on your board while current must be 2Amps or higher
 */


#include <SoftwareSerial.h>
SoftwareSerial LC_GSM(2, 3);
#define PHONE "09164428565"

void setup() {
  pinMode(8,INPUT_PULLUP);
  Serial.begin(9600);
  LC_GSM.begin(9600);
  Serial.println("Please wait for 10 seconds...");
  delay(9000);
  LC_GSM.println("AT+CMGF=1");
  delay(1000);
  Serial.println("Momentarily connect pin D8 to ground to send a test SMS");
}
void loop() {
    if(digitalRead(8) == LOW)
    {
      Serial.print("Sensing SMS...");
      LC_GSM.print("AT+CMGS=\"");
      LC_GSM.print(PHONE);
      LC_GSM.println("\"");
      delay(1000);
      LC_GSM.print("Layad Circuits' Example code for sending an SMS\x1A");
      delay(5000);
      Serial.println("Done!");
    }    
}



