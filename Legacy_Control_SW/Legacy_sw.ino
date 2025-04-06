/*Programmcode für die Ansteuerung des Mecanumwheel-Roboter mit Greifsystem*/

//Bibliotheken einbinden
#include <Wire.h> //um mit I2C-Geräten kommunizieren zu können, wie z.B der Servo-Treiber
#include <Adafruit_PWMServoDriver.h> //um mit dem Servo-Treiber(PCA9685) kommunizieren zu können

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();//deklariert die pwm Variable

char dataIn;//enthält im späteren Programmcode den Inhalt der vom Serial1 gelesen wird
char x='z';//setzt die Steuerungsvariable (x) auf den character 'z'
int delayzwischenSchritte= 1750;//Zeitliche-Verzögerung die zwischen den einzelnen Schrittmotor-Schritten gebraucht wird
int servoDelay=15;//Zeitliche-Verzögerung um die Servos nicht zu überlasten

//Wert der Startpositionen der Servos
int servo1Pos=250;
int servo2Pos=250;
int servo3Pos=350;
int servo4Pos=400;
int servo5Pos=150;
int servo6Pos=490;

//Pin-Dekleration der einzelnen Schrittmotortreiber
int stepPin1=45;
int dirPin1=44;
int stepPin2=51;
int dirPin2=50;
int stepPin3=47;
int dirPin3=46;
int stepPin4=43;
int dirPin4=42;
int stepPin5=49;
int dirPin5=48;
//Microsteping beim Schrittmotor der Achse1 vom Greifsystem
int MS1Pin=41;
int MS2Pin=39;
int MS3Pin=37;


void setup() {

//Schrittmotor Pin-Belgeungen alle alls Outputs deklarieren
pinMode(stepPin1,OUTPUT);
pinMode(dirPin1,OUTPUT);
pinMode(stepPin2,OUTPUT);
pinMode(dirPin2,OUTPUT);
pinMode(stepPin3,OUTPUT);
pinMode(dirPin3,OUTPUT);
pinMode(stepPin4,OUTPUT);
pinMode(dirPin4,OUTPUT);
pinMode(stepPin5,OUTPUT);
pinMode(dirPin5,OUTPUT);
pinMode(MS1Pin,OUTPUT);
pinMode(MS2Pin,OUTPUT);
pinMode(MS3Pin,OUTPUT);


//MS1,2,3 von Schrittmotor der 1Achse HIGH schalten
digitalWrite(MS1Pin,HIGH);
digitalWrite(MS2Pin,HIGH);
digitalWrite(MS3Pin,HIGH);

//Öffne Schnittstellen
  Serial1.begin(9600);
  delay(20);
  Serial.begin(9600);
//PWM starten für Servo-Treiber
  pwm.begin();
  pwm.setPWMFreq(60);

//Roboterarm in Startposition
pwm.setPWM(0, 0, servo1Pos );
pwm.setPWM(1, 0, servo2Pos );
delay(2000);
pwm.setPWM(2, 0, servo3Pos );
pwm.setPWM(5, 0, servo6Pos );
delay(2000);
pwm.setPWM(3, 0, servo4Pos );
delay(2000);
pwm.setPWM(4, 0, servo5Pos );


}



void loop() {

//Daten am Serial1 abfangen
  if (Serial1.available() > 0) {
     dataIn = Serial1.read(); 
    Serial.println(dataIn); 
     
    if (dataIn == 'z') {
      x = 'z'; 
    }
    if (dataIn == 'a') {
      x = 'a'; 
    }
    if (dataIn == 'b') {
      x = 'b'; 
    }
    if (dataIn == 'c') {
      x = 'c'; 
    }
    if (dataIn == 'd') {
      x = 'd'; 
    }
    if (dataIn == 'e') {
      x = 'e'; 
    }
    if (dataIn == 'f') {
      x = 'f'; 
    }
    if (dataIn == 'g') {
      x = 'g'; 
    }
    if (dataIn == 'h') {
      x = 'h'; 
    }
    if (dataIn == 'i') {
      x = 'i'; 
    }
    if (dataIn == 'j') {
      x= 'j'; 
    }
    if (dataIn == 'k') {
      x = 'k'; 
    }
    if (dataIn == 'l') {
      x = 'l'; 
    }
    if (dataIn == 'm') {
      x = 'm'; 
    }
    if (dataIn == 'n') {
      x = 'n'; 
    }
    if (dataIn == 'o') {
      x = 'o'; 
    }
    if (dataIn == 'p') {
      x = 'p'; 
    }
    if (dataIn == 'q') {
      x = 'q'; 
    }
    if (dataIn == 'r') {
      x = 'r'; 
    }


//Plattform bewegen:

//Plattform nach vorne bewegen
  while(x=='a'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
        
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
  
  
    }

//Plattform nach hinten bewegen
  while(x=='b'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
        
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  digitalWrite(dirPin5,LOW);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  digitalWrite(dirPin5,LOW);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
  
  
    }

//Plattform nach rechts bewegen
  while(x=='c'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
        
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
  
  
    }

//Plattform nach links bewegen
  while(x=='d'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
        
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,LOW);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
  
  
    }
//Rotiere 90grad nach Rechts
while(x=='e'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }

  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,LOW);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW);
  digitalWrite(dirPin3,LOW);
  digitalWrite(dirPin5,LOW);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
}

//Rotiere 90grad nach Links
while(x=='f'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }

  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,HIGH);
  digitalWrite(stepPin2,HIGH);
  digitalWrite(stepPin3,HIGH);
  digitalWrite(stepPin5,HIGH);
  delayMicroseconds(delayzwischenSchritte);
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH);
  digitalWrite(dirPin3,HIGH);
  digitalWrite(dirPin5,HIGH);
  digitalWrite(stepPin1,LOW);
  digitalWrite(stepPin2,LOW);
  digitalWrite(stepPin3,LOW);
  digitalWrite(stepPin5,LOW);
  delayMicroseconds(delayzwischenSchritte);
}


//Roboterarm steuerung

//Greifarm zu
while(x=='g'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(5, 0, servo6Pos );
      servo6Pos++;
      delay(servoDelay);
  }

//Greifarm auf
while(x=='h'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(5, 0, servo6Pos );
      servo6Pos--;
      delay(servoDelay);
  
  }

//Achse2 Servo Rechtslauf
while(x=='p'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(0, 0, servo1Pos );
      pwm.setPWM(1, 0, servo2Pos );
      servo1Pos++;
      servo2Pos++;
      delay(servoDelay);
  
  }

//Achse2 Servo Linkslauf
while(x=='o'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(0, 0, servo1Pos );
      pwm.setPWM(1, 0, servo2Pos );
      servo1Pos--;
      servo2Pos--;
      delay(servoDelay);
  
  }

//Achse3 Servo Rechtslauf
while(x=='m'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(2, 0, servo3Pos );
      servo3Pos++;
      delay(servoDelay);
  
  }

//Achse3 Servo Linkslauf
while(x=='n'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(2, 0, servo3Pos );
      servo3Pos--;
      delay(servoDelay);
  
  }

//Achse4 Servo Rechtslauf
while(x=='k'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(3, 0, servo4Pos );
      servo4Pos++;
      delay(servoDelay);
  
  }

//Achse4 Servo Linkslauf
while(x=='l'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(3, 0, servo4Pos );
      servo4Pos--;
      delay(servoDelay);
  
  }

//Achse5 Servo Rechtslauf
while(x=='i'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(4, 0, servo5Pos );
      servo5Pos++;
      delay(servoDelay);
  
  }

//Achse5 Servo Rechtslauf
while(x=='j'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
      pwm.setPWM(4, 0, servo5Pos );
      servo5Pos--;
      delay(servoDelay);
  
  }

//Achse1 Schrittmotor Rechtslauf
while(x=='q'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
  digitalWrite(dirPin4,HIGH);
  digitalWrite(stepPin4,HIGH);
  delayMicroseconds(2000);
  digitalWrite(dirPin4,HIGH);
  digitalWrite(stepPin4,LOW);
  delayMicroseconds(2000);
  
  }
//Achse1 Schrittmotor Rechtslauf
while(x=='r'){

  if (Serial1.available() > 0) {
       x = Serial1.read();
  }
  digitalWrite(dirPin4,LOW);
  digitalWrite(stepPin4,HIGH);
  delayMicroseconds(2000);
  digitalWrite(dirPin4,LOW);
  digitalWrite(stepPin4,LOW);
  delayMicroseconds(2000);
  
  }
  }
}

  
