/*
 * LED-Complexity
 * by Ashley Woon
 * This program switches between red, green, and blue based on an internal counter set by the push button.
 */

int counter = 0;
int pushButton = A0;
int redLED = 12;
int greenLED = 27;
int blueLED = 33;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initializing LED pin outputs
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  // initializing input pin as input
  pinMode(A0, INPUT);
}

void loop() {
  // read button input
  int buttonState = digitalRead(pushButton);
  delay(100);
  // each button push will be counted
  if (buttonState == HIGH) {
    counter++;
    delay(100);
  }
  Serial.println(counter);

  if(counter == 1) {
    // output only red
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }
  else if(counter == 2) {
    // output only green
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  }
  else if(counter == 3) {
    // output only blue
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, HIGH);
  }
  else {
    counter=0;
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH); 
  }

}
