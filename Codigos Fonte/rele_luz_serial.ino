/*
 Controlando interruptor de luz do Testbed Ceu na Terra via Serial e verificando a luminosidade da sala.
 Autores: Andressa Kappaun, Arthur Almeida e Renan Colman
 O circuito pode ser visto em: http://imgur.com/XBLOT5U
 */

const int relay = 8; // Pino que o rele esta conectado
int incomingByte;      // Variavel para ler o que o usuario escreve na entrada Serial

void setup() {
  
  Serial.begin(9600);
  
  // Inicializa o rele como saida
  pinMode(relay, OUTPUT);
}

void loop() {
  
  int LDR = analogRead(A0); //Sensor de luminosidade para verificar o estado da lampada. Quando acesa, mesmo com a luz externa, ocorre uma pequena variacao detectavel.
    Serial.print("Luminosidade da Sala: ");
    Serial.println(LDR);
    
  // Verifica se algo foi digitado
  if (Serial.available() > 0) {
    // Lê o último caracter que foi digitado
    incomingByte = Serial.read();
    // Se for a letra H ou (ASCII 72), liga o LED
    if (incomingByte == 'H' || incomingByte == 'h') {
      digitalWrite(relay, HIGH);
      Serial.println("Lampada ligada.");
    }
    // Se for a letra L ou (ASCII 76) desliga o LED:
    if (incomingByte == 'L' || incomingByte == 'l') {
      digitalWrite(relay, LOW);
      Serial.println("Lampada desligada.");
    }
    
    delay(100);  

    
  }
}
