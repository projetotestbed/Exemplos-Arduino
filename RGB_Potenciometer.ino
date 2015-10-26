/*		24/09/2015
		LED RGB variando cores de acordo com valores de um potenciometro
		Autor: Arthur Almeida
		O circuito pode ser visto em: http://imgur.com/M4h1Cgk
*/

/* Declarando Pinos usados c/ PWM
	 PWM A modulação por Largura de Pulso ou PWM é a modulação ou alteração da
	 largura do pulso de um sinal de onda quadrada, com estas entradas pode-se
	 obter resultados analógicos por meio de sinal digital.
*/
 
int redPin = 9;
int greenPin = 10;
int bluePin = 11;
 
// Declarando Pinos usados c/ Potenciômetro

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
  
/* Pinos definidos como OUTPUT são ditos em estado de baixa impedância,
	 isso significa que podem distribuir uma quantidade substancial de corrente
	 para outros circuitos
*/ 
  
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
 
void loop()
{
/* Lê o valor em cada pino analógico e escala o valor entre 0 - 255
 	 este valor é subtraído do valor máximo 255 para permitir variar
 	 na escala de 0 à 255. */
  
  RedColor = (255 - map( analogRead(redPotPin), 0, 1024, 0, 255 ));
  BlueColor = (255 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ));
  GreenColor = (255 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ));
 
// Escreve a cor em cada pino usando o PWM e o valor obtido acima
  
  analogWrite(redPin, RedColor);
  analogWrite(bluePin, BlueColor);
  analogWrite(greenPin, GreenColor);

//Escreve na saída serial o valor obtido
  
  Serial.println(RedColor);
  Serial.println(BlueColor);
  Serial.println(GreenColor);
 
}