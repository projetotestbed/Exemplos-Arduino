//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// LED Gradual
// 
// Made by Renan Colman
// License: CC-BY-SA 3.0
// Downloaded from: https://123d.circuits.io/circuits/1042935-led-gradual

/* 
	Programa para fazer os leds apagarem gradativamente um por um nos pinos digitais 2 ao 13.
	Autor: Renan Colman
	O circuito pode ser visto em: 
*/
// Constantes que não mudam. São usadas para dar nomes aos pinos usados.

const int lowestPin = 2;
const int highestPin = 13;

void setup() {
  // Botando todos os pinos usados como saídas:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {
  // Interação entre os pinos:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    // Acende pino atual:
    for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    // Apaga pino atual:
    for (int brightness = 255; brightness >= 0; brightness--) {
      analogWrite(thisPin, brightness);
      delay(2);
    }
    
    // Pausa entre os LEDs:
    delay(100);
  }
}
