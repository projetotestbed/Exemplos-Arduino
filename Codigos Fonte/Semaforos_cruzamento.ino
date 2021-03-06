/*
    06.10.2015
    elaborado por Andressa Kappaun, Arthur Almeida e Renan Colman
    o circuito pode ser visto em http://imgur.com/1OoaV1d
    Semaforos: controla os 2 semaforos de um cruzamento,
    cada um deles fica verde e amarelo enquanto o outro esta vermelho 
    */

// pinos do semaforo de LED RGB
const int sema1_vermelho=2;
const int sema1_azul=3;
const int sema1_verde=4;

// pinos do semaforo do LEDs 
const int sema2_verde=10;
const int sema2_amarelo=11;
const int sema2_vermelho=12;

int incomingLiga;
int var=1;

// variaveis de controle do loop - nao precisariam ser globais
void setup() {
  
  //Iniciando Serial
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);           // led interno
  pinMode(sema1_verde, OUTPUT);
  pinMode(sema1_azul, OUTPUT);
  pinMode(sema1_vermelho, OUTPUT);
  pinMode(sema2_verde, OUTPUT);
  pinMode(sema2_amarelo, OUTPUT);
  pinMode(sema2_vermelho, OUTPUT);
  Serial.print("\n ####################\n ##SEMAFORO VIRTUAL##\n ####################\n");
  Serial.print("\nPara ligar o semaforo digite: L\n");
  Serial.print("\nPara desligar o semaforo digite: D\n");
}

void loop() {
   
  if (Serial.available() > 0){   
    incomingLiga = Serial.read();
      if (incomingLiga == 'L' || incomingLiga == 'l') { 
        while (incomingLiga != 'd' || incomingLiga != 'D'){
        
        // s1 verde, s2 vermelho
        digitalWrite(sema1_verde, HIGH);
        digitalWrite(sema1_vermelho, LOW);
        digitalWrite(sema2_vermelho, HIGH);
        digitalWrite(sema2_amarelo, LOW);
        digitalWrite(sema2_verde,LOW);
        Serial.println("Semaforo LED: VERMELHO - Semaforo RGB: VERDE");
        delay(3000);
        // s1 amarelo, s2 continua vermelho
        digitalWrite(sema1_verde, HIGH);
        digitalWrite(sema1_vermelho, HIGH);
        Serial.println("Semaforo LED: VERMELHO - Semaforo RGB: AMARELO");
        delay(1000);
        // s1 vermelho, s2 verde
        digitalWrite(sema1_verde, LOW);
        digitalWrite(sema1_vermelho, HIGH);
        digitalWrite(sema2_verde, HIGH);
        digitalWrite(sema2_vermelho, LOW);
        Serial.println("Semaforo LED: VERDE - Semaforo RGB: VERMELHO");
        delay(3000);     
          // s2 amarelo, s1 vermelho
        digitalWrite(sema2_verde, LOW);
        digitalWrite(sema2_amarelo, HIGH);
        Serial.println("Semaforo LED: AMARELO - Semaforo RGB: VERMELHO");
        delay(1000);
        incomingLiga = Serial.read();
        
      if (incomingLiga == 'D' || incomingLiga == 'd'){
        digitalWrite(sema2_verde, LOW);
        digitalWrite(sema2_vermelho, LOW);
        digitalWrite(sema2_amarelo, LOW);
        digitalWrite(sema1_verde, LOW);
        digitalWrite(sema1_vermelho, LOW);
        digitalWrite(sema1_azul, LOW);
        break;
      }
             }
   }  
  }
 }     
