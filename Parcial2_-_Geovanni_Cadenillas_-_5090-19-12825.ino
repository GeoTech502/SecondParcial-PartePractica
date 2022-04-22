int Pulsador = 2;
int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int verde = 11;
int azul = 12;
int rojo = 13;
int valor;
int estado = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(verde,OUTPUT);
  pinMode(azul,OUTPUT);
  pinMode(rojo,OUTPUT);
  
  pinMode(Pulsador,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED1,LOW);
}

void loop() {
  /*Programación LED RGB*/
  valor = map (analogRead(A0),0,1023,0,70);

  if (valor<2){
    digitalWrite(azul,LOW);
    digitalWrite(rojo,LOW);
    digitalWrite(verde,LOW);
    Serial.print("Apagado:");
    Serial.println(valor);
    delay(300);
  }
  
  if ((valor>=2) and (valor<=10)){
    digitalWrite(verde,HIGH);
    digitalWrite(azul,LOW);
    digitalWrite(rojo,LOW);
    Serial.print("Verde:");
    Serial.println(valor);
    delay(300);
  }

  if ((valor>10) and (valor<=20)){
    digitalWrite(verde,LOW);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    Serial.print("Azul:");
    Serial.println(valor);
    delay(300);
  }

  if ((valor>20) and (valor<=30)){
    digitalWrite(verde,LOW);
    digitalWrite(azul,LOW);
    digitalWrite(rojo,HIGH);
    Serial.print("Rojo:");
    Serial.println(valor);
    delay(300);
  }

  if ((valor>30) and (valor<=40)){
    digitalWrite(verde,HIGH);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,LOW);
    Serial.print("Cian:");
    Serial.println(valor);
    delay(300);
  }

  if ((valor>40) and (valor<=50)){
    digitalWrite(verde,HIGH);
    digitalWrite(azul,LOW);
    digitalWrite(rojo,HIGH);
    Serial.print("Amarillo:");
    Serial.println(valor);
    delay(300);
  }

  if ((valor>50) and (valor<=60)){
    digitalWrite(verde,LOW);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,HIGH);
    Serial.print("Magenta:");
    Serial.println(valor);
    delay(300);
  }
  
  if ((valor>60) and (valor<=70)){
    digitalWrite(verde,HIGH);
    digitalWrite(azul,HIGH);
    digitalWrite(rojo,HIGH);
    Serial.print("Blanco:");
    Serial.println(valor);
    delay(300);
  }

  if(digitalRead(Pulsador)==HIGH){
  pulsador();
  }
}

void pulsador(){
  while(digitalRead(Pulsador)==LOW);
  estado = digitalRead(LED1);
  /*Led Rojo*/
  digitalWrite(LED1,!estado);
  delay(7000);
  digitalWrite(LED1,LOW);
  delay(600);
  
  /*Led Amarillo*/
  digitalWrite(LED2,HIGH);
  delay(8000);
  digitalWrite(LED2,LOW);
  delay(500);

  /*Led Verde*/
  digitalWrite(LED3,HIGH);
  delay(7000);
  digitalWrite(LED3,LOW);
  
  while(digitalRead(Pulsador)==HIGH);
}
