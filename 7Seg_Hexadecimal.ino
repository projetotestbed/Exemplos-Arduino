/* 24/09/2015
	Contador em hexadecimal em display 7 Seg
	Autor: Arthur Almeida
	O circuito pode ser visto em: http://imgur.com/NPGHFx0
*/

// Pinos do LED ligados nas entradas digitais
int LED_A = 2;
int LED_B = 3;
int LED_C = 4;
int LED_D = 5;
int LED_E = 6;
int LED_F = 7;
int LED_G = 8;

// Botoes
int BTN_DEC = 12;
int BTN_INC = 11;

// Numero inicial do display
int Num = 0;
int i;

void setup()
{
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
}

void loop()
{
  // Os botoes ficam em estado HIGH quando nao estao sendo pressionados
  // quando pressionados mudam para LOW, e essa condicao inicia a conta abaixo.
  
  if(digitalRead(BTN_DEC) == LOW)
  {
    if(Num > 0)
    {
      // Decrementa caso numero seja maior que zero
      Num--;
    }
    else
    {
      // Se o numero for zero, ao decrementar, o display pisca duas vezes
      // para mostrar que n?o da pra decrementar mais.
      
      for(i = 0; i < 2; i++)
      {
        // Acende todos
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_D, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_G, HIGH);
        delay(500);
        
        // Apaga todos
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_G, LOW);
        delay(500);
      }
    }
    
    // Aguardar o botao ser solto para evitar entrar na condicao enquanto pressionado
    while(digitalRead(BTN_DEC) == LOW) 
    {
    }
  }

  // Mesma condicao anterior, porem agora para incrementar.
  
  if(digitalRead(BTN_INC) == LOW)
  {
    if(Num < 15)
    {
      // Incrementa caso numero seja menor que 15
      Num++;
    }
    else
    {
      // Se o numero for 15, ao incrementar, o display pisca duas vezes
      // para mostrar que nao da pra incrementar mais.
      
      for(i = 0; i < 2; i++)
      {
        // Acende todos
        digitalWrite(LED_A, HIGH);
        digitalWrite(LED_B, HIGH);
        digitalWrite(LED_C, HIGH);
        digitalWrite(LED_D, HIGH);
        digitalWrite(LED_E, HIGH);
        digitalWrite(LED_F, HIGH);
        digitalWrite(LED_G, HIGH);
        delay(500);
        
        // Apaga todos
        digitalWrite(LED_A, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_C, LOW);
        digitalWrite(LED_D, LOW);
        digitalWrite(LED_E, LOW);
        digitalWrite(LED_F, LOW);
        digitalWrite(LED_G, LOW);
        delay(500);
      }
    }
    
    // Aguardar o botao ser solto para evitar entrar na condicao enquanto pressionado
    while(digitalRead(BTN_INC) == LOW) 
    {
    }
  }

  
  // Escrevendo no display
  // Para formar as letrar e numeros no display 7 seg, deve-se acender ou apagar 
  // individualmente os leds distribuidos no display, formando o padr?o da letra ou numero.
  
  if(Num == 0)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, LOW);
  }  
  else if(Num == 1)
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, LOW);
  }
  else if(Num == 2)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 3)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 4)
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 5)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 6)
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 7)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, LOW);
  }
  else if(Num == 8)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 9)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 10)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 11)
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 12)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, LOW);
  }
  else if(Num == 13)
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 14)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, HIGH);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else if(Num == 15)
  {
    digitalWrite(LED_A, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, HIGH);
    digitalWrite(LED_F, HIGH);
    digitalWrite(LED_G, HIGH);
  }
  else // Zero
  {
    digitalWrite(LED_A, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
    digitalWrite(LED_E, LOW);
    digitalWrite(LED_F, LOW);
    digitalWrite(LED_G, LOW);
  }
  
  delay(500);
}
