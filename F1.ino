// TODOS LOS VALORES DE LOS PINES ESTÀN A MODO DE EJEMPLOS.
// ELIMINAR ESTO CUANDO SEAN LOS CORRECTOS.


//-------------------MOTORES---------------------
#define MOTOR_DER_1 8
#define MOTOR_DER_2 7
#define MOTOR_IZQ_1 9
#define MOTOR_IZQ_2 10
#define PWM_MOTOR_DER 3
#define PWM_MOTOR_IZQ 11

//---------------------BLUTUCH-----------------------
char caracter;
caracter = Serial.read();

//----------------Servo Direccional------------------
#include <Servo.h>
Servo direccionservo;
int ang = 65;  //Grados iniciales

//----------------------Luces------------------------
#define LED_FRONT_DER 1
#define LED_FRONT_IZQ 2
#define LED_ATRAS_DER 3
#define LED_ATRAS_IZQ 4

//----------------------SETUP------------------------
void setup() {
  pinMode(MOTOR_DER_1, OUTPUT);
  pinMode(MOTOR_DER_2, OUTPUT);
  pinMode(MOTOR_IZQ_1, OUTPUT);
  pinMode(MOTOR_IZQ_2, OUTPUT);
  pinMode(LED_FRONT_DER, OUTPUT);
  pinMode(LED_FRONT_IZQ, OUTPUT); 
  pinMode(LED_ATRAS_DER, OUTPUT); 
  pinMode(LED_ATRAS_IZQ, OUTPUT); 
}

//----------------------LOOP-----------------------
void loop() {
  caracter = Serial.read(); // Se lee el caracter del celular
  ang = constrain(ang,20,105); //Se limita los valores del angulo
  direccionservo.write(ang);
  
//MAQUINA DE ESTADO CON LAS POCICIONES.

}