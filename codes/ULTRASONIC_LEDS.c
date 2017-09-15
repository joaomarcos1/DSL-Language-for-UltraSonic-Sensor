int signal = 8;
int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 7;
int distance;
unsigned long pulseduration=0;


void setup(){
 pinMode(ledVermelho, OUTPUT);
 pinMode(signal, OUTPUT);
 pinMode(ledAmarelo, OUTPUT);
 pinMode(ledVerde, OUTPUT);
 Serial.begin(9600);
}

void loop()
{

 pinMode(signal, OUTPUT);

 digitalWrite(signal, LOW);
 delayMicroseconds(5);

 digitalWrite(signal, HIGH);
 delayMicroseconds(5);
 digitalWrite(signal, LOW);


 pinMode(signal, INPUT);

 pulseduration=pulseIn(signal, HIGH);


 pulseduration=pulseduration/2;


 distance = int(pulseduration/29);

  if (distance < 100){
  	 digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  }else
    if (distance >= 100 && distance <= 200){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVerde, LOW);
  	}else
     if (distance > 200){
       digitalWrite(ledVermelho, LOW);
       digitalWrite(ledAmarelo, LOW);
       digitalWrite(ledVerde, HIGH);
    }

 Serial.print("Distance - ");
 Serial.print(distance);
 Serial.println(" cm");
 delay(500);
}
