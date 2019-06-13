//Programa : Controlar 2 motores DC usando Ponte H L298N
//Autor : Wesley e Lucas
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 2;
int IN2 = 3;
int IN3 = 6;
int IN4 = 7;

int led = 13;
int led12 = 12; 
int led11 = 11; 
//int led10 = 10;  
char comando;

boolean ledLigado = false;
  
void setup(){
 //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);

 //Velocidade da porta serial  
 Serial.begin(9600);
 
 //Configuração como pino de saida
 pinMode(led, OUTPUT);  
}

void desligarLed(){
 digitalWrite(led, LOW);
 ledLigado = false;
}

void ligarLedsDireita(){
 digitalWrite(led, LOW);
 digitalWrite(led12, LOW);
 digitalWrite(led11, HIGH);
 //digitalWrite(led10, LOW);
}

void ligarLedsEsquerda(){
 digitalWrite(led, LOW);
 digitalWrite(led12, HIGH);
 digitalWrite(led11, LOW);
 //digitalWrite(led10, LOW);
}

void ligarLedsTodos(){
 digitalWrite(led, HIGH);
 digitalWrite(led12, HIGH);
 digitalWrite(led11, HIGH);
 //digitalWrite(led10, HIGH);
 ledLigado = true;  
}

void desligarLedsTodos(){
 digitalWrite(led, LOW);
 digitalWrite(led12, LOW);
 digitalWrite(led11, LOW);
 //digitalWrite(led10, LOW);
 ledLigado = false; 
}

// C
void frente(){
 desligarLed();
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}

// D
void tras(){
 ligarLedsTodos();
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}

// A
void esquerda(){
 ligarLedsEsquerda();
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH); 
}

// B
void direita(){
 ligarLedsDireita();
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);   
}
// J 
void parar(){
 desligarLed();
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);  
}
 
void ligarLed(){
 digitalWrite(led, HIGH);
 ledLigado = true;
}

// E
void controlarLeds(char cmd){
  if(cmd == 'e'){
     if(ledLigado){
      desligarLed();
     }
     else{
      ligarLed();
     }
   }

  if(cmd == 'f'){
    if(ledLigado){
      desligarLedsTodos();
     }
     else{
      ligarLedsTodos();
     }
  }
}

void verificarDirecao(char comando){
  //Esquerda
   if(comando == 'a'){
     esquerda();
   }
   
   //Direita
   if(comando == 'b'){
     direita();
   }
  
   //Frente
   if(comando == 'c'){
     frente();
   }

   //Tras
   if(comando == 'd'){
     tras();
   }

   //Parar
   if(comando == 'j'){
     parar();
   }
}
  
void loop(){
  // Pergunta se porta serial esta disponivel 
  // Como o modulo HC-05 esta ligado na porta serial, 
  // é o mesmo que perguntar se o bluetooth esta disponivel
  if(Serial.available()){
    comando = Serial.read();
    Serial.print("Comando recebido: ");
    Serial.println(comando);

    verificarDirecao(comando);
     
    controlarLeds(comando);
  }
}
