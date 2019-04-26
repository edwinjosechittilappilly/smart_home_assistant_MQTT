#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 100) {
    digitalWrite(led, HIGH);
}
  else {
    digitalWrite(led,LOW);
  }
  if (distance < 75) {
      digitalWrite(led2, HIGH);
}
  else {
      digitalWrite(led2, LOW);
  }
  if (distance < 50) {
      digitalWrite(led3, HIGH);
      
} 
  else {
    digitalWrite(led3, LOW);
  }
  if (distance < 30) {
    digitalWrite(led4, HIGH);
   
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 20) {
    digitalWrite(led5, HIGH);
   
}
  else {
    digitalWrite(led5,LOW);
  }
  if (distance < 10) {
    digitalWrite(led6, HIGH);
   
}
  else {
    digitalWrite(led6,LOW);
  }
  delay(500);
}
