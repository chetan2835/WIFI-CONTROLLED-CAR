/*Nodemcu ESP8266 WIFI control car with the New Blynk app.
   This code created by the SriTu Hobby team.
   Home Page
*/

// Include the library files
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL31Mfqnplx"   // Replace with your actual Template ID
#define BLYNK_TEMPLATE_NAME "Boat" // Replace with your actual Template Name
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Define the motor pins
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5



// Variables for the Blynk widget values

int Speed;

bool forward = 0;
bool backward = 0;
bool Left = 0;
bool Right = 0;



char auth[] = "jfJ5bU2i3t-J09XUgWzxOmC-BGF7bm6a"; //Enter your Blynk auth token
char ssid[] = "Redmi Note 13 5G"; //Enter your WIFI name
char pass[] = "mittstjmhxhgv6r"; //Enter your WIFI passowrd


void setup() {
  Serial.begin(9600);
  //Set the motor pins as output pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// Get the joystick values
BLYNK_WRITE(V0) {
  forward = param.asInt();
}
// Get the joystick values
BLYNK_WRITE(V1) {
  backward = param.asInt();
}

BLYNK_WRITE(V2) {
  Left = param.asInt();
}

BLYNK_WRITE(V3) {
  Right = param.asInt();
}

//Get the slider values
BLYNK_WRITE(V4) {
  Speed = param.asInt();
}

// Check these values using the IF condition
void smartcar() {
  if (forward == 1) {
    carForward();
    Serial.println("carForward");
  } else if (backward == 1) {
    carBackward();
    Serial.println("carBackward");
  } else if (Left == 1) {
    carturnleft();
    Serial.println("carturnLeft");
  } else if (Right == 1) {
    carturnright();
    Serial.println("carturnRight");
  } else if (forward == 0 && backward == 0 && Left == 0 && Right == 0) {
    carStop();
    Serial.println("carstop");
  }
}
void loop() {
  Blynk.run();// Run the blynk function
  smartcar();// Call the main function
}

/**************Motor movement functions*****************/
void carForward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carBackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}