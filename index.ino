const int RPWM = 5;
const int LPWM = 6;

const int relayPin = 7;

const int trigPin = 8;
const int echoPin = 9;

const int switchPin = 4;

const int obstacleThreshold = 60;  
const int emergencyStopDistance = 10; 

const int motorSpeed = 180;

void setup() {
  
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(relayPin, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(switchPin, INPUT_PULLUP); 
  digitalWrite(RPWM, LOW);
  digitalWrite(LPWM, LOW);
  digitalWrite(relayPin, LOW); 
}

void loop() {
  bool isSwitchOn = (digitalRead(switchPin) == LOW); // Switch pressed = ON
  int distance = getDistance();

  if (distance < emergencyStopDistance) {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    digitalWrite(relayPin, LOW);
  }
  else if (isSwitchOn && distance > obstacleThreshold) {
    analogWrite(RPWM, motorSpeed);
    analogWrite(LPWM, 0);
    digitalWrite(relayPin, HIGH);
  }
  else {
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    digitalWrite(relayPin, LOW);
  }

  delay(20); 
}


int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  if (distance == 0 || distance > 200) return 200; 
  return distance;
}
