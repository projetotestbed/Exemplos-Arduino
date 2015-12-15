/* 23/09/2015
	Controlando um servo com um potenci�metro
	Autor: Arthur Almeida
	O circuito pode ser visto em: http://imgur.com/FaALvki
*/
#include <Servo.h>

Servo myservo;  // declarando o objeto servo

int potpin = 0;  // pino analogico em que se conecta o potenciometro
int val;    // variavel que guarda o valor do pino analogico

void setup()
{
  myservo.attach(13);  // conecta o servo ao pino 13
  
}

void loop() 
{ 
  
  
  val = analogRead(potpin);            // l� o valor do potenciometro (valor entre 0 e 1023) 
  val = map(val, 0, 1023, 0, 180);     // escala esse valor para usar com a angulacao do servo (valor entre 0 e 180) 
  
 
  myservo.write(val);                  // move o servo de acordo com o valor da variavel val
  delay(15);                           // espera o servo chegar no valor definido
} 
