//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Apagando e acendendo LED via teclado
// 
// Made by Renan Colman
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1046093-apagando-e-acendendo-led-via-teclado

/*		
	LED RGB variando cores de acordo com valores de um potenciometro
	Autor: Renan Colman
	O circuito pode ser visto em: 
*/
const int ledPin = 13; // Pino que o Led está conectado
int incomingByte;      // Variavel para ler o que o usuário escreve no serial monitor

void setup() {
  
  Serial.begin(9600);
  // Inicializa o LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Verifica se algo foi digitado
  if (Serial.available() > 0) {
    // Lê o último caracter que foi digitado
    incomingByte = Serial.read();
    // Se for a letra H ou (ASCII 72), liga o LED
    if (incomingByte == 'H' || incomingByte == 'h') {
      digitalWrite(ledPin, HIGH);
    }
    // Se for a letra L ou (ASCII 76) desliga o LED:
    if (incomingByte == 'L' || incomingByte == 'l') {
      digitalWrite(ledPin, LOW);
    }
  }
}
