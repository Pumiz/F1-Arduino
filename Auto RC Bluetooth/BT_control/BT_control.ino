#include <SoftwareSerial.h>
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;

String DatoBT;
int GradoServo =0;
char boton, StatusBoton ='0';
float tiempoServo =0;



SoftwareSerial BT1(2, 3); // RX | TX
void setup()
  {
    Serial.begin(9600);
    BT1.begin(9600); 

    pinMode(12, OUTPUT); // indicador RX BT
    pinMode(13, OUTPUT);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    servoMotor.attach(10);
    servoMotor.write(GradoServo); // angulo cero
    delay(1000);
  }
 
void loop()
  {  
    BTfuncion();
  }


// funcion de lectura Bluetooth

void BTfuncion (){
  if (BT1.available()>0){
           digitalWrite(12, HIGH);
           DatoBT= BT1.readStringUntil('#');
           Serial.println(DatoBT);
           digitalWrite(12, LOW);
           ControlServo();
           Serial.write(BT1.read());
     }
           
     if (Serial.available()){
        BT1.write(Serial.read());
     }
}

// funcion para controlar posicion del servo

void ControlServo(){
  
  String Grados = DatoBT.substring(0,3);
  boton = DatoBT.charAt(6); 
  Serial.println(Grados);
  Serial.println(boton);


  switch (boton){
    case '1': 
      GradoServo = 180;
     break;
    case '4': 
      GradoServo = 90;
     break;  
    case '3': 
      GradoServo = 0;
     break;   
    case '2': 
      if (StatusBoton== '0'){
        digitalWrite(13, HIGH);
        StatusBoton= '1';
      } else {
          digitalWrite(13, LOW);
          StatusBoton= '0';
      } 
     delay(25);
     break;   
     case '0': 
      GradoServo = Grados.toInt();
     break;     
  }

  
  if (millis() - tiempoServo > 25){ 
  servoMotor.write(GradoServo);
  tiempoServo = millis(); }  
}
  
