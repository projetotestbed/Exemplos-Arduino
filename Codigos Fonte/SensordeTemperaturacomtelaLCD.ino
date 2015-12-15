//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Sensor de Temperatura com tela LCD
// 
// Made by Renan Colman
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1012346-sensor-de-temperatura-com-tela-lcd

/*
	Alerta de temperatura com visor
	Verde: x <= 50ºC    Azul: x > 50ºC  x < 150ºC     Vermelho: x >= 150ºC
    Autor:Renan Colman
    O circuito pode ser visto em:
*/

//Importa a biblioteca do display
#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 10, 4, 3, 2); //Pinos utilizados para ligação do display

float sensorTemp = A1;     //Pino analógico em que o sensor de temperatura está conectado

const int verdeLedPin = 7;  //Pino analógico em que o Led Vermelho está conectado
const int azulLedPin = 6;      //Pino analógico em que o Led Azul está conectado
const int vermelhoLedPin = 5;      //Pino analógico em que o Led Verde está conectado



void setup() {
  
  lcd.begin(16,2);
  pinMode (verdeLedPin, OUTPUT);
  pinMode (azulLedPin, OUTPUT);
  pinMode (vermelhoLedPin, OUTPUT);

  analogWrite(verdeLedPin, 0);
  analogWrite(azulLedPin, 0);
  analogWrite(vermelhoLedPin, 0);
  
}

void loop() {
	
  // Variável com o valor da temperatura
  int valorSensorTemp = analogRead(sensorTemp)-20; 
  
  
  //Temperatura baixa menor que 50ºC
  if (valorSensorTemp <= 50){
    analogWrite (verdeLedPin, 225);
    analogWrite (vermelhoLedPin, 0);
    analogWrite (azulLedPin, 0);
    lcd.print("Temperatura");
    lcd.setCursor(0,1);
    lcd.print("Baixa ");
    lcd.print(valorSensorTemp);
  	lcd.print(" C");
  }
  //Temperatura média entre 50 e 150ºC
  if(valorSensorTemp >50 && valorSensorTemp < 150){
    analogWrite (verdeLedPin, 0);
    analogWrite (vermelhoLedPin, 0);
    analogWrite (azulLedPin, 225);
    lcd.print("Temperatura");
    lcd.setCursor(0,1);
    lcd.print("Moderada ");
    lcd.print(valorSensorTemp);
  	lcd.print(" C");
  }
  //Temperatura alta maior que 150ºC
  if (valorSensorTemp >= 150){
    analogWrite (verdeLedPin, 0);
    analogWrite (vermelhoLedPin, 225);
    analogWrite (azulLedPin, 0);
    
    lcd.print("Temperatura");
    lcd.setCursor(0,1);
    lcd.print("Elevada ");
    lcd.print(valorSensorTemp);
  	lcd.print(" C");
  }
  
  
  
  Serial.print(valorSensorTemp);
  Serial.print("\n");
  
  delay(500);
  lcd.clear();
  
 
}
