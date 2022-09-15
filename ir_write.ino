
#include <IRremote.h>

IRsend irsend(5);

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 1) {
    char inChar = Serial.read();

    Serial.println("I received: ");
    //incomingByte = 0;

    if(inChar == 's')
    {
      irsend.sendNEC(0x0, 0x19, 5);
      Serial.println("start/stop");
    }

    if(inChar == 'p')
    {
      irsend.sendNEC(0x0, 0x15, 5);
    }

    if(inChar == 'm')
    {
      irsend.sendNEC(0x0, 0x18, 5);
    }     
  }
}
