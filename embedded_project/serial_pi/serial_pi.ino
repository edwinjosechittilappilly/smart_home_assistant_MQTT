char serIn;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("success");
  while (Serial.available() > 0) serIn = Serial.read();
}
int num = 10;
void loop() {
  if (Serial.available() > 0) {
    serIn = Serial.read();
    if (serIn == 'A') {
      Serial.println("success read");
    }
    while (Serial.available() > 0) serIn = Serial.read();
  }

}
