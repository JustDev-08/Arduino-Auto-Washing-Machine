
const int trigPin = 2;
const int echoPin = 4;
const int relayPin = 12;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(115200);
}
void loop() {
 long distanceNow = distanceCheck();

 if (distanceNow < 5 ) {
    digitalWrite(relayPin , HIGH);
    delay(700);
    digitalWrite(relayPin , LOW);
    delay(2500);
 }

}

int distanceCheck(){
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  delay(500);
  return distance;
 }
