#include<SoftwareSerial.h>
SoftwareSerial bt(0, 1); /* (Rx,Tx) */

//Declarations

//L298N driver -1
// Motor A connections
int enAL1 = 13;
int in1L1 = 9;
int in2L1 = 11;
// Motor B connections
int enBL1 = 12;
int in3L1 = 10;
int in4L1 = 8;

//L298N driver -1
// Motor A connections
int enAL2 = 6;
int in1L2 = 2;
int in2L2 = 3;
// Motor B connections
int enBL2 = 7;
int in3L2 = 4;
int in4L2 = 5;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(enAL1, OUTPUT);
  pinMode(enBL1, OUTPUT);
  pinMode(in1L1, OUTPUT);
  pinMode(in2L1, OUTPUT);
  pinMode(in3L1, OUTPUT);
  pinMode(in4L1, OUTPUT);
  pinMode(enAL2, OUTPUT);
  pinMode(enBL2, OUTPUT);
  pinMode(in1L2, OUTPUT);
  pinMode(in2L2, OUTPUT);
  pinMode(in3L2, OUTPUT);
  pinMode(in4L2, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, LOW);
  bt.begin(9600); /* Define baud rate for software serial communication */
  Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {
  if (bt.available()) /* If data is available on serial port */
  {
    char a = bt.read();
    Serial.println(a);/* Print character received on to the serial monitor */
    if (a == '1') {
      directionControlforward();
    }
    if (a == '2') {
      directionControlbackward();
    }
    if (a == '3') {
      directionControlleft();
    }
    if (a == '4') {
      directionControlright();
    }
    if (a == '5') {
      directionControlup();
    }
    if (a == '6') {
      directionControldown();
    }
    if (a == '7') {
      directionControlopen();
    }
    if (a == '8') {
      directionControlclose();
    }
  }
}

// This function lets you control spinning direction of motors


//forward movement

void directionControlforward() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL1, 255);
  analogWrite(enBL1, 255);

  // Turn on motor A & B
  digitalWrite(in1L1, HIGH);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, HIGH);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
}

//backward movement

void directionControlbackward() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL1, 255);
  analogWrite(enBL1, 255);

  // Turn on motor A & B
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, HIGH);
  digitalWrite(in3L1, HIGH);
  digitalWrite(in4L1, LOW);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
}


//left movement

void directionControlleft() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL1, 255);
  analogWrite(enBL1, 255);

  // Turn on motor A & B
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, HIGH);
  digitalWrite(in4L1, LOW);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
}

//right movement

void directionControlright() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL1, 255);
  analogWrite(enBL1, 255);

  // Turn on motor A & B
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, HIGH);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L1, LOW);
  digitalWrite(in2L1, LOW);
  digitalWrite(in3L1, LOW);
  digitalWrite(in4L1, LOW);
}


//arm up

void directionControlup() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL2, 255);
  analogWrite(enBL2, 255);

  // Turn on motor A & B
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, HIGH);
  digitalWrite(in3L2, HIGH);
  digitalWrite(in4L2, LOW);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, LOW);
}

//arm down

void directionControldown() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL2, 255);
  analogWrite(enBL2, 255);

  // Turn on motor A & B
  digitalWrite(in1L2, HIGH);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, HIGH);
  digitalWrite(in4L2, LOW);
  delay(2000);



  // Turn off motors
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, LOW);
}

//claw open

void directionControlopen() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL2, 255);
  analogWrite(enBL2, 255);

  // Turn on motor A & B
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, HIGH);
  digitalWrite(in4L2, LOW);
  delay(7000);



  // Turn off motors
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, LOW);
}

//claw close

void directionControlclose() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enAL2, 255);
  analogWrite(enBL2, 255);

  // Turn on motor A & B
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, HIGH);
  delay(7000);



  // Turn off motors
  digitalWrite(in1L2, LOW);
  digitalWrite(in2L2, LOW);
  digitalWrite(in3L2, LOW);
  digitalWrite(in4L2, LOW);
}
