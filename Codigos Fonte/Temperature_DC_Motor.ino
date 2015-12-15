/* 23/09/2015
	Ligar motor DC de acordo com temperatura do ambiente
	Autor: Arthur Almeida
	O circuito pode ser visto em: http://imgur.com/W2wplN9
*/

//Declarando vari�veis

int transistorPin = 3; //Pino digital em que o transistor est� conectado

int sensorTemp = A1;     //Pino anal�gico em que o sensor de temperatura est� conectado

void setup()

{
  Serial.begin(9600);
  pinMode(transistorPin, OUTPUT); //Declarando o pino do transistor como OUTPUT

}

void loop()

{
    // Mapeando os valores lidos pelo sensor de temperatura, 20 � 358, na escala dos graus em Celsius mostrados pelo mesmo, -40 � 125
  
  	int valorReal = map (analogRead(sensorTemp), 20, 358, -40, 125);
  
    Serial.println(valorReal);

  	//Condi��o para acionar o motor
  
	if (valorReal >=60) //Caso a temperatura seja maior que 60 graus, aciona o motor com potencia abaixo
    {
		analogWrite(transistorPin, valorReal/2); // O motor � acionado com a metade do valor lido pelo sensor de temperatura
    }
  	else
    {
        analogWrite(transistorPin, 0); //Caso a temperatura seja menor que 60 graus, o motor recebe o valor zero
    }
}