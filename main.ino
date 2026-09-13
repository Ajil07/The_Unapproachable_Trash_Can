/**
 * @file main.ino
 * @brief Useless Project 3.0: Autonomous Linear Escape Trash Can
 */

#define IN1 18
#define IN2 19
#define IN3 21
#define IN4 22
#define LED_PIN 2

#define TRIG_FRONT 25
#define ECHO_FRONT 34
#define TRIG_REAR  26
#define ECHO_REAR  35

const float TRIGGER_DIST = 40.0;
const float PINCH_DIST   = 18.0;
const float HYSTERESIS   = 3.0;

bool isEscaping = false;

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  isEscaping = false;
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  isEscaping = true;
}

void moveReverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  isEscaping = true;
}

float readDistance(uint8_t trigPin, uint8_t echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);
  if (duration == 0) return -1.0;

  return (duration * 0.0343) / 2.0;
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIG_FRONT, OUTPUT);
  pinMode(ECHO_FRONT, INPUT);
  pinMode(TRIG_REAR, OUTPUT);
  pinMode(ECHO_REAR, INPUT);

  stopMotors();
  Serial.println("--- System Initialized (40cm Trigger Mode) ---");
  delay(1500);
}

void loop() {
  float distFront = readDistance(TRIG_FRONT, ECHO_FRONT);
  delay(25);
  float distRear = readDistance(TRIG_REAR, ECHO_REAR);

  float activeThreshold = isEscaping ? (TRIGGER_DIST + HYSTERESIS) : TRIGGER_DIST;

  bool frontTriggered = (distFront > 0 && distFront < activeThreshold);
  bool rearTriggered  = (distRear > 0 && distRear < activeThreshold);
  bool trapped        = (distFront > 0 && distFront < PINCH_DIST) && 
                        (distRear > 0 && distRear < PINCH_DIST);

  if (trapped) {
    digitalWrite(LED_PIN, HIGH);
    stopMotors();
  } 
  else if (frontTriggered && !rearTriggered) {
    digitalWrite(LED_PIN, HIGH);
    moveReverse();
  } 
  else if (rearTriggered && !frontTriggered) {
    digitalWrite(LED_PIN, HIGH);
    moveForward();
  } 
  else if (frontTriggered && rearTriggered) {
    if (distFront < distRear) {
      digitalWrite(LED_PIN, HIGH);
      moveReverse();
    } else {
      digitalWrite(LED_PIN, HIGH);
      moveForward();
    }
  } 
  else {
    digitalWrite(LED_PIN, LOW);
    stopMotors();
  }

  delay(40);
}
