/*		24/09/2015
		LED RGB variando cores de acordo com valores de um potenciometro
		Autor: Arthur Almeida
		O circuito pode ser visto em: http://imgur.com/M4h1Cgk
*/

/* Declarando Pinos usados c/ PWM
	 PWM A modula��o por Largura de Pulso ou PWM � a modula��o ou altera��o da
	 largura do pulso de um sinal de onda quadrada, com estas entradas pode-se
	 obter resultados anal�gicos por meio de sinal digital.
*/
 
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
 
// Declarando Pinos usados c/ Potenci�metro

int redPotPin = 0;
int greenPotPin = 1;
int bluePotPin = 2;
 
// Declarando Variaveis

int RedColor;
int GreenColor;
int BlueColor;
 
void setup()
{
  Serial.begin(9600); 

// Definindo os pinos como OUTPUT
  
/* Pinos definidos como OUTPUT s�o ditos em estado de baixa imped�ncia,
	 isso significa que podem distribuir uma quantidade substancial de corrente
	 para outros circuitos
*/ 
  
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop()
{
/* L� o valor em cada pino anal�gico e escala o valor entre 0 - 255
 	 este valor � subtra�do do valor m�ximo 255 para permitir variar
 	 na escala de 0 � 255. */
  
  RedColor = (255 - map( analogRead(redPotPin), 0, 1024, 0, 255 ));
  BlueColor = (255 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ));
  GreenColor = (255 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ));
 
// Escreve a cor em cada pino usando o PWM e o valor obtido acima
  
  analogWrite(redPin, RedColor);
  analogWrite(bluePin, BlueColor);
  analogWrite(greenPin, GreenColor);

//Escreve na sa�da serial o valor obtido
  
  Serial.println(RedColor);
  Serial.println(BlueColor);
  Serial.println(GreenColor);
 
}