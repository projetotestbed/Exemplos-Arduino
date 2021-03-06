//Autor: Felipe Tomazelli
// imagem: http://i.imgur.com/ftrOSwK.png
 
// Define sinonimos para facilitar o código.
#define sensorLum A0
#define pot A1
#define saida 13

int i = 0; //Contador
float temp_1 = -1.0; //Variável temporária 1
float temp_2 = -1.0; //variavel temporária 2

//Importa a biblioteca do display LCD
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7); //Pinos utilizados para a ligação do display

void setup() {
  // inicia o lcd
  lcd.begin(16,2);

  // Configura portas como entrada e saida.
  pinMode(pot, INPUT);
  pinMode(saida, OUTPUT);

  //Ativando o serial monitor que exibirá os valores lidos no sensor.
  Serial.begin(115200);

  // Garante que a saida comece em nivel baixo.
  digitalWrite(saida,LOW);
}

void loop() {
  // Compara o valor do sensor de luminosidade com o valor definido no potenciometro.
  if (analogRead(sensorLum)>analogRead(pot)) {
    // Se for menor ativa a saida.
    digitalWrite(saida,HIGH);
  }
  else {
	// Se for maior, desativa.
	digitalWrite(saida,LOW);
  }
  // Ao final do codigo há um delay de 100ms, cada unidade do contador "i" equivale a 100ms, a função abaixo mostrará no display a luminosidade por 10 segundos.
  if (i<100){
    if (temp_1!=analogRead(sensorLum)){ //verifica se houve mudança no display
	  lcd.clear(); // limpa o display
  	  lcd.print("Luminosidade: ");
  	  lcd.setCursor(0,1);  //quebra de linha
  	  lcd.print(analogRead(sensorLum)); 
      temp_1=analogRead(sensorLum); //iguala o valor temporário ao do display
	  temp_2=-1.0;  //Reseta o valor temporário do potenciometro
    }
  }
  //A função abaixo mostrará por 5 segundos a luminosidade mínima para ascender a lâmpada.
  else{
    if (temp_2!=analogRead(pot)){
		lcd.clear(); //Limpa o display
		lcd.print("Potenciometro: ");
   		lcd.setCursor(0,1); //Quebra de linha
  		lcd.print(analogRead(pot)); 
      	temp_2=analogRead(pot); //Iguala o valor temporário ao do display
		temp_1=-1.0; //Reseta o valor temporário do sensor de luminosidade
    }
  }
  //Definindo o valor de "i" como 100ms.
  delay(100);
  i++;
  //Reseta o contador após 15s
  if (i==150)
    i=0;
}
