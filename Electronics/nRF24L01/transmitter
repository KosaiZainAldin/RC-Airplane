#include <SPI.h>
#include <RF24.h>

RF24 radio(2, 3);

byte address[6] = "22030";

void setup() {
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);    
  radio.stopListening();

}

void loop() {
  int signal = analogRead(A1);
  radio.write(&signal, sizeof(signal));
  

}
