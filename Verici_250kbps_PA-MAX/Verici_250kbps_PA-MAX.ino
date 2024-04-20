#include  <SPI.h> 
#include "nRF24L01.h"
#include "RF24.h"    


int mesaj [2];  
    
RF24 verici(9,8);   

const int kanal = 112; 

   
void setup()
{
  verici.begin(); 
  verici.openWritingPipe(kanal);
  verici.setDataRate(RF24_250KBPS);
  verici.setPALevel(RF24_PA_MAX);
  verici.stopListening();
}


void loop()
{
  mesaj[0] = 323;
  mesaj[1] = 112;
  verici.write(mesaj, sizeof(mesaj));
  delay(1000);

}
