// Autor: Felipe Tomazelli
// imagem http://i.imgur.com/HaDOVN2.png

const int ledY = 13; // the pin that the LED is attached to
const int ledG = 12;
int incomingByte;      // a variable to read incoming serial data into
int incomingLetter;
int i = -1;
int j = -1;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void switchState(int led){

  // se estiver apagado, acenda
  if (digitalRead(led)==LOW)
	digitalWrite(led, HIGH);

  // se estiver aceso, apague
  else if (digitalRead(led)==HIGH)
  	digitalWrite(led, LOW);

  delay(1); //delay para evitar bugs
}
 // função que pisca os leds
void pisca(int led, int n) {
    // se for um numero
    if(n>48 && n < 58){
      //pisca de acordo com o numero que foi entrado
    	while (i<(n-48)*2){
      		switchState(led);
      		delay(500);
      		i++;
    	}
        i=0;
    }
    
   else{
      	Serial.print("O caractere digitado nao esta entre os numeros 1 e 9\n");
    }
    delay(1);
  
}

void loop() {
  if (i==-1){
  	Serial.print ("Entre com \"Y\" para o led amarelo ou \"G\" para o led verde, seguido do numero de vezes que o led piscara (sem espaco, maximo de 9 vezes, Ex. \"Y9\")\n");
    i=0;
  }
  if (Serial.available() > 0) {
    incomingLetter = Serial.read();
    delay(100);
    if(incomingLetter==89||incomingLetter=='y'){
      incomingByte = Serial.read();
      pisca(ledY,incomingByte);
      delay(1);
    }
    else if(incomingLetter==71||incomingLetter=='g'){
      incomingByte = Serial.read();
      pisca(ledG,incomingByte);
      delay(1);
    }
    else{
      Serial.print("O caractere digitado nao corresponde a nenhum dos leds\n");
      delay(1);
    }
    delay(1);
  }
  
}
