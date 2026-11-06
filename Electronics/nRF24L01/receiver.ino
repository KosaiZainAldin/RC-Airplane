#include <SPI.h>
#include <RF24.h>

RF24 radio(2, 3);
byte address[6] = "22030";

void setup() {
  pinMode(8, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  int signal;
  if (radio.available()) {
        radio.read(&signal, sizeof(signal));
        if (signal == 1023){
      digitalWrite(8, HIGH);
  } else {
      digitalWrite(8, LOW);
    }
  if (signal == 1023){
      digitalWrite(8, HIGH);
      delay(100);

  } else {
      digitalWrite(8, LOW);
    }

}
