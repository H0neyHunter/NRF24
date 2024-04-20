#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int mesaj[2];

RF24 alici(9,8);

const int kanal = 112;

void setup(){
  Serial.begin(9600);
  alici.begin();
  alici.openReadingPipe(1,kanal);
  alici.setDataRate(RF24_250KBPS);
  alici.setPALevel(RF24_PA_MAX);
  alici.startListening();
}

void loop(){
  
  if (alici.available())
  {
    alici.read( mesaj, sizeof(mesaj) ); 
    Serial.println("available 1.index = " + String(mesaj[0]));
    Serial.println("available 2.index = " + String(mesaj[1]));
  }
}
