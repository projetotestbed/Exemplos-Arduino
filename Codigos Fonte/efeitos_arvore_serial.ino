/*
 Arvore de natal de LED baseada em cubo 3x3x3
 Autores: Andressa Kappaun, Arthur Almeida e Renan Colman
 A montagem do projeto foi baseada neste tutorial: http://www.instructables.com/id/A-Charlieplexed-Christmas-Tree/
 
 */

int estrelaIn = 7; //Digital 7
int colunaVerde1 = 8; //Digital 8
int colunaVerde2 = 10; //Digital 10
int colunaVerde3 = 12; //Digital 12
int colunaVermelha1 = 9; //Digital 9
int colunaVermelha2 = 11; //Digital 11
int colunaVermelha3 = 13; //Digital 13
int linha1 = 54;//Analogico A0 // base | INFO UTIL: Pinos analogicos no arduino podem ser representados pelo numero da porta, começando pelo 54 no Arduino Mega.
int linha2 = 55; //Analogico A1
int linha3 = 56; //Analogico A2
int linha4 = 57; //Analogico A3
int linha5 = 58; //Analogico A4
int incomingLiga; // Variavel que recebe o digito usado pelo usuario na entrada Serial
boolean flag = true;
int brilho =0;
boolean acender = true;
boolean apagar = false;


void estrelinhaPisca(){
  
  for (int brilho = 0; brilho < 255; brilho=brilho+3){ //Aumenta a intensidade do brilho da estrela ate o valor max
  analogWrite(estrelaIn, brilho);
  delay(2);
  }
  for (int brilho = 255; brilho > 0; brilho=brilho-3){ //Diminui a intensidade do brilho da estrela ate o valor minimo
  analogWrite(estrelaIn, brilho);
  delay(2);
  }
}


void esmaeceEstrela (){ //Aumenta e diminui a intensidade do brilho da estrela, porem alternando com a animacao atual.
  if (flag){
    for(int i=0; i<35;i++){
                  brilho++;
      analogWrite(estrelaIn, brilho);
                  delay(2);

                }
    if(brilho==255){
      flag = false;
    }
  }
  else{
                for(int i=0; i<35;i++){
                  brilho--;
                  analogWrite(estrelaIn, brilho);
                  delay(2);
                  
                }
    if(brilho==0){
      flag = true;
    }
  }
}

void todosApagam(){
  
  for(int i=54; i<59;i++){ //Apaga linhas
      digitalWrite(i, LOW); 
  }
  for(int i=7; i<14;i++){ //Apaga colunas e estrela
    digitalWrite(i, LOW); 
  }
}

void todosAcendem (){
  
  for(int i=54; i<59;i++){ //Acende linhas
      digitalWrite(i, LOW); 
  }
  for(int i=7; i<14;i++){ //Acende colunas e estrela
    digitalWrite(i, HIGH); 
  }  
}

void acendeColunas(){
  
  while(1){

  for(int i=8; i<14;i++){ // Acende colunas
    digitalWrite(i, HIGH);
   delay(80); 
    esmaeceEstrela();    
  } 
  
  for(int i=8; i<14;i++){ // Apaga colunas
    digitalWrite(i, LOW); 
    delay(80);
    esmaeceEstrela();    
  } 

  if (Serial.available() > 0){ //Se o usuario apertar a tecla "q" o loop acaba.
    incomingLiga = Serial.read();
    if(incomingLiga == 'q'){
      break;
      
    }
  }

  }
  todosApagam(); //Apos finalizar o loop, os leds sao apagados.
    Serial.println("Arvore apagada.");
}

void sobeDesce(){
  while(1){
    for(int i=8; i<14;i++){ // Acende colunas
      digitalWrite(i, HIGH);    
    } 
    for(int i=54; i<59;i++){ //Acende linhas
        digitalWrite(i, HIGH);
        delay(120);
    }
    
    estrelinhaPisca();
    
    for(int i=58; i>53;i--){ //Apaga linhas
        digitalWrite(i, LOW); 
        delay(120);
    }
    if (Serial.available() > 0){
    incomingLiga = Serial.read();
    if(incomingLiga == 'q'){
      break;
      
    }
  }
  
  }
  todosApagam();
  Serial.println("Arvore apagada.");
}

void aleatorios(){
    
  while(1){
    
    for(int i=7; i<14;i++){ // Acende colunas
      digitalWrite(i, LOW); 
        }
   
    for(int i=54; i<59;i++){ //Acende linhas
        digitalWrite(i, HIGH);
        }
    
    digitalWrite(random(7,14), HIGH); //Os leds sao acesos de maneira aleatoria usando a funcao random com o range de 7 a 14, variando entre todas as possiveis colunas.
    digitalWrite(random(54, 59), LOW); //Os leds sao acesos de maneira aleatoria usando a funcao random com o range de 54 a 59, variando entre todas as possiveis linhas.
    digitalWrite(random(7,14), HIGH);
    digitalWrite(random(54, 59), LOW);
    delay(80);
    
    if (Serial.available() > 0){
    incomingLiga = Serial.read();
    if(incomingLiga == 'q'){
      break;
      
    }
}
  }
  todosApagam();
    Serial.println("Arvore apagada.");
}

void piscaTudo(){
  
  while(1){
    todosAcendem();
    delay(300);
    todosApagam();
    delay(300);
    
  if (Serial.available() > 0){
    incomingLiga = Serial.read();
    if(incomingLiga == 'q'){
      break;
      
      }
    }
  }
  todosApagam();
    Serial.println("Arvore apagada.");
}
void setup() {
  

  Serial.begin(9600);
  
  //Inicializando as entradas como OUTPUT
  for(int i=7; i<14;i++){ // Acende colunas
      pinMode(i, OUTPUT); 
        }
        
  for(int i=54; i<59;i++){ //Acende linhas
      pinMode(i, OUTPUT);
        }
                    
      Serial.print("\n ###############################\n ##Controle de Luzes da Arvore##\n ###############################\n");
      Serial.print("\n Digite o numero correspondente ao efeito desejado:\n");
      Serial.print("\n 1 - Todos os leds acendem \n");
      Serial.print("\n 2 - Cada coluna acende (LOOP) \n");
      Serial.print("\n 3 - Apaga todos os LEDs \n");
      Serial.print("\n 4 - Pisca estrela amarela \n");
      Serial.print("\n 5 - Cada linha acende (LOOP) \n");
      Serial.print("\n 6 - Cada led acende aleatoriamente (LOOP) \n");
      Serial.print("\n 7 - Pisca a arvore toda (LOOP) \n");
      Serial.print("\n Obs: Aperte a tecla ""q"" para parar os efeitos marcados como LOOP no menu, antes de selecionar outro efeito. \n");
}

void loop() {
  
  if (Serial.available() > 0){ //Verificando a entrada serial
    incomingLiga = Serial.read();
    switch(incomingLiga){ //Opcoes selecionaveis pelo usuario
      case'1':
        Serial.print("Efeito 1 selecionado.\nExecutando...\n");    
        todosAcendem();
      break;
      case'2':
        Serial.print("Efeito 2 selecionado.\nExecutando...\n");
        acendeColunas();
      break;
      case '3':
        Serial.print("Efeito 3 selecionado.\nExecutando...\n");
        todosApagam();
      break;
      case '4':
        Serial.print("Efeito 4 selecionado.\nExecutando...\n");
        estrelinhaPisca();
      break;
      case '5':
        Serial.print("Efeito 5 selecionado.\nExecutando...\n");
        sobeDesce();
      break;
      case '6':
        Serial.print("Efeito 6 selecionado.\nExecutando...\n");
        aleatorios();
      break;
      case '7':
        Serial.print("Efeito 7 selecionado.\nExecutando...\n");
        piscaTudo();
      break;
        
      default:
      Serial.print("\n -----------------------------Entrada invalida. Digite um numero listado-----------------------------\n");          
      Serial.print("\n ###############################\n ##Controle de Luzes da Arvore##\n ###############################\n");
      Serial.print("\n Digite o numero correspondente ao efeito desejado:\n");
      Serial.print("\n 1 - Todos os leds acendem \n");
      Serial.print("\n 2 - Cada coluna acende (LOOP) \n");
      Serial.print("\n 3 - Apaga todos os LEDs \n");
      Serial.print("\n 4 - Pisca estrela amarela \n");
      Serial.print("\n 5 - Cada linha acende (LOOP) \n");
      Serial.print("\n 6 - Cada led acende aleatoriamente (LOOP) \n");
      Serial.print("\n 7 - Pisca a arvore toda (LOOP) \n");
      Serial.print("\n Obs: Aperte a tecla ""q"" para parar os efeitos marcados como LOOP no menu, antes de selecionar outro efeito. \n");
    }
  }

  

}
