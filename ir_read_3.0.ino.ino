#include <IRremote.hpp>

void setup()
{
  IrReceiver.begin(9, true); // Start the receiver
  Serial.begin(9600);

}

void loop() {
  if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
      IrReceiver.printIRResultShort(&Serial); // optional use new print version
      IrReceiver.resume(); // Enable receiving of the next value
  }
}
