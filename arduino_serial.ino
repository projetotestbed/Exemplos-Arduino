/*
Aplicação que rodará no Arduino, em conjunto com a arduino_serial.py na máquina do usuário.
Esta aplicação apenas acende/apaga o LED do Arduino (pino 13) sempre que recebe da serial, e envia uma mensagem informando o que foi recebido.
*/

int letra = 0;
int pino = 13;

void setup() {
	Serial.begin(115200);
	pinMode(pino, OUTPUT);
}

void muda() {
	if(digitalRead(pino) == HIGH)
		digitalWrite(pino, LOW);
	else
		digitalWrite(pino, HIGH);
}

void loop() {
        
	if (Serial.available() > 0) {

		// ler byte da serial
		letra = Serial.read();

		// enviar mensagem com a letra lida
		Serial.print("Leu a letra ");

		if(letra != NULL) {
			Serial.println(byte);
			muda();
		}
		else
			Serial.println("NULL");
	}
}
