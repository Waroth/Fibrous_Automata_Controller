
int pinA = A0;
int pinB = A1;
int pinC = A2;
int pinD = A3;
int pinE = A4;
int pinF = A5;

int buttonA = 24;
int buttonB = 22;

int ledA = 30;
int ledB = 32;

int ledC = 40;
int ledD = 42;

int buttonAPrev;
int buttonBPrev;

boolean brushA = true;
boolean brushB;
boolean modeB;

void setup() {

  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);

  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  buttonAPrev = 0;
  buttonBPrev = 0;

  Serial.begin(9600);
}

void loop() {

  if (digitalRead(buttonA) > 0) {
    brushA = true;
    brushB = false;
    modeB = false;
  }

  if (digitalRead(buttonB) > 0) {
    modeB = true;
    brushA = false;
    brushB = true;
  }

  if (modeB) {
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }

  if (brushA) {
    digitalWrite(ledC, HIGH);
  } else {
    digitalWrite(ledC, LOW);
  }

  if (brushB) {
    digitalWrite(ledD, HIGH);
  } else {
    digitalWrite(ledD, LOW);
  }

  digitalWrite(ledA, HIGH);

  buttonAPrev = digitalRead(buttonA);
  buttonBPrev = digitalRead(buttonB);

  //Serial.println("a");
  Serial.print(analogRead(pinF));
  Serial.print(",");
  Serial.print(analogRead(pinE));
  Serial.print(",");
  Serial.print(analogRead(pinD));
  Serial.print(",");
  Serial.print(analogRead(pinC));
  Serial.print(",");
  Serial.print(analogRead(pinB));
  Serial.print(",");
  Serial.print(analogRead(pinA));
  Serial.print(",");
  Serial.print(modeB);
  Serial.print(",");
  Serial.print(brushA);
  Serial.print(",");
  Serial.println(brushB);

}
