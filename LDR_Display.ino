/* 11/09/2015
	Sensor LDR imprimindo valores em um display LCD
	Autor: Arthur Almeida
	O circuito pode ser visto em: http://imgur.com/cSQ0duI
*/

//Importa a biblioteca do display

#include <LiquidCrystal.h>

//Define os pinos que ser?o utilizados para ligacao ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Sensor de luminosidade LDR
int sensorLum = A1;            //Pino analogico em que o sensor de luminosidade esta conectado.

//Variaveis
int i = 0;
float media = 0; 

//Funcao setup, executado uma vez ao ligar o Arduino.
void setup(){
  //Ativando o serial monitor que exibira os valores lidos no sensor.
  Serial.begin(115200);
  lcd.begin(16,2);

}

//Funcao loop, executado enquanto o Arduino estiver ligado.
void loop(){
  
  float valorSensorLum = analogRead(sensorLum); //valor da luminosidade.
  lcd.clear();
  media += valorSensorLum; //soma da media
  lcd.print("Val");
  lcd.print(i);
  lcd.print(": ");
  lcd.print(valorSensorLum);
  i++;
  
  if (i==3){ //verificacao pra retornar o valor da media a cada 3 leituras
     media = media/3;
     lcd.setCursor(0,1); 
     lcd.print("Media: "); 
     lcd.setCursor(7,1); 
     lcd.print(media); 
     media=0;
     i=0;
     }

  delay(1000);  //Espera 1 seg para realizar a proxima leitura 
}