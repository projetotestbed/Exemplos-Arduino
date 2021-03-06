//Autor: Felipe Tomazelli
// imagem: http://i.imgur.com/IWdfvUt.png
//definindo sinonimos para facilitar o código.
#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define led7 7
#define led8 6
#define led9 5

//esta variavel sera utilizada para armazenar o tempo
unsigned long previousMillis = 0;

void setup() {
  // inicializando os leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);

  // garantindo que todos os leds comecem apagados
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
}

// função para trocar o estado do led
void switchState(int led){

  // se estiver apagado, ascenda
  if (digitalRead(led)==LOW)
	digitalWrite(led, HIGH);

  // se estiver asceso, apague
  else if (digitalRead(led)==HIGH)
  	digitalWrite(led, LOW);

  delay(1); //delay para evitar bugs
}
void loop() {
  //armazenando o tempo em mili segundos
  int currentMillis=millis();
  /* "currentMillis" armazena o tempo atual desde que o sistema foi ligado, "millis" irá apenas de 0ms à 8000ms, isso é feito subtraindo a variavel "previousMillis" de "currentMillis"*/
  int millis = currentMillis - previousMillis;
  switch(millis){
    case 0:
		switchState(led1); //troca o estado do led1
		break;
    case 1000:
    	switchState(led2); //troca o estado do led2
    	break;
    case 2000:
    	switchState(led3); //troca o estado do led3
    	break;
    case 3000:
    	switchState(led4); //troca o estado do led4
    	break;
    case 4000:
    	switchState(led5); //troca o estado do led5
    	break;
    case 5000:
    	switchState(led6); //troca o estado do led6
    	break;
    case 6000:
    	switchState(led7); //troca o estado do led7
    	break;
    case 7000:
    	switchState(led8); //troca o estado do led8
    	break;
    case 8000:
    	switchState(led9); //troca o estado do led9
    	break;
    case 9000:
    	previousMillis=currentMillis; //Iguala o "previousMillis" ao "currentMillis", para que a variável "millis" volte a "0"
    	break;
    default:
    	break;
  }
}
