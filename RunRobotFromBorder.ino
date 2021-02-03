#define echoPin 12 //echp pin 12 ci pine qosuludur
#define trigPin 13 //trig pini 13 e qosulu
#define MatorR1 7
#define MatorR2 6
#define MatorRE 9  //matorlarin qosulu oldugu pinler
#define MatorL1 5
#define MatorL2 4
#define MatorLE 3

long vaxt, mesafe;
void setup() {
  //trig pini dalga gonderir
  //echo pini dalgani qebul edir
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(MatorL1, OUTPUT);
  pinMode(MatorL2, OUTPUT);
  pinMode(MatorLE, OUTPUT); 
  pinMode(MatorR1, OUTPUT);
  pinMode(MatorR2, OUTPUT);
  pinMode(MatorRE, OUTPUT);


  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  vaxt = pulseIn(echoPin, HIGH); 
  mesafe = vaxt / 29.1 / 2; //vaxti sesin suretin egore mesafeye ceviririk

  Serial.println(mesafe);

  if (mesafe< 15) // default mesafe 15 dir
  {
    geri();  
    delay(150);
    sag();  
    delay(250);
  }
  else {  
    ileri();
  }

}
void ileri(){  

  digitalWrite(MatorR1, HIGH); 
  digitalWrite(MatorR2, LOW); 
  analogWrite(MatorRE, 150); 
  digitalWrite(MatorL1, HIGH); 
  digitalWrite(MatorL2, LOW); 
  analogWrite(MatorLE, 150); 
  
}
void sag(){ 

  digitalWrite(MatorR1, HIGH); 
  digitalWrite(MatorR2, LOW); 
  analogWrite(MatorRE, 0); /
  digitalWrite(MatorL1, HIGH); // Sol matoru ileri hereketi aktivlesir
  digitalWrite(MatorL2, LOW); // Sol matorun geri hereketi passivlesir
  analogWrite(MatorLE, 150); // Sol matorun sureti 150
  

}
void geri(){ 
  digitalWrite(MatorR1, LOW); // Sağ matorun ileri hereketi passivlesir
  digitalWrite(MatorR2, HIGH); // Sağ matorun geri hereketi aktiflesir
  analogWrite(MatorRE, 150); // Sağ matorun sureti 150
  digitalWrite(MatorL1, LOW); // Sol matorun ileri hereketi passivlesir
  digitalWrite(MatorL2, HIGH); // Sol matorun geri hereketi aktiflesir
  analogWrite(MatorLE, 150); // Sol matorun sureti 150
  
}
