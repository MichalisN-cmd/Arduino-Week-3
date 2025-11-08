const int trigPin = 9;  
const int echoPin = 10;  
const int greenLED = A2;
const int yellowLED = A3  ;
const int redLED = A4;
const int buzzer = 12;
const int buzzer2 = 8;
float duration, distance;  

void setup() {
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
Serial.begin(9600);  
}

void loop() {
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);  
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0343) / 2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance > 100) {
    
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (distance > 50 && distance <= 100) {
    
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
  } 
  else if (distance > 20 && distance <= 50) {
    
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(buzzer2, HIGH);
  } 
  else if (distance <= 20 && distance > 0) {
    
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(buzzer2, HIGH);
    tone(buzzer, 440);   
    tone(buzzer2, 523);  
    delay(100);
    noTone(buzzer);
    noTone(buzzer2);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(buzzer2, LOW);
    delay(100);
  }

  delay(100);
}
