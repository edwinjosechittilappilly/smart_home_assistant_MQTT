char serIn;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("success");
  while (Serial.available() > 0) serIn = Serial.parseInt();
}
int num = 10;
void loop() {
  if (Serial.available() > 0) {
    serIn = Serial.parseInt();
    if (serIn == 11) {
      Serial.println("light one on");
    }
    if (serIn == 10) {
      Serial.println("light one off");
    }
    if (serIn == 21) {
      Serial.println("light two on");
    }

    if (serIn == 20) {
      Serial.println("light two off");
    }
    if (serIn == 31) {
      Serial.println("light three on");
    }
    if (serIn == 30) {
      Serial.println("light three off");
    }
    if (serIn == 41) {
      Serial.println("light four on");
    }
    if (serIn == 40) {
      Serial.println("light four off");
    }
    while (Serial.available() > 0) serIn = Serial.read();
  }

}
