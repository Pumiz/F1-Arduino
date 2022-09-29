/*
 * Conexiones 
 * Arduino HC-05
 * 11 Pin   RX 
 * 10 Pin   TX 
 * 9 Pin    EN 
 * 8 Pin    VCC 
 * GND      GND    
*/
#include <SoftwareSerial.h>

// Definimos el objeto para la comunicación serie
SoftwareSerial BT(10, 11); // 10 RX, 11 TX.

int VCC = 8; // Pin digital para alimentar el módulo Bluetooth HC-05
int EN = 9; // Pin digital para la habilitación del módulo Bluetooth HC-05


void setup()
{
  pinMode(VCC, OUTPUT); // Pin digital 8 como salida
  pinMode(EN, OUTPUT); // Pin digital 9 como salida

  digitalWrite(EN, HIGH);  // Habilitamos el módulo Bluetooth HC-05
  delay(500); // Esperamos 500 ms
  digitalWrite (VCC, HIGH); // Encendemos el módulo Bluetooth HC-05

  Serial.begin(9600); // Comienzo la comunicación con el monitor serie
  BT.begin(38400); // Comienzo de la comunicación con el módulo Bluetooth HC-05 (por defecto)

  Serial.println("Esperando comandos AT ... ");
}

void loop()
{
  // Si hay datos disponibles en el monitor serie
  if (Serial.available())
  {
    // Escribimos los valores en el módulo bluetooth HC-05
    BT.write(Serial.read());
  }
  // Si hay datos disponibles en el módulo bluetooth HC-05
  if (BT.available())
  {
    // Mostramos los valores en el monitor serie
    Serial.write(BT.read());
  }
}
