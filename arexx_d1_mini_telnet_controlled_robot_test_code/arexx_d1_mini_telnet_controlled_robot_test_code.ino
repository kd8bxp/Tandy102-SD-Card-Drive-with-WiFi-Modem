/* Arexx D1 Mini Telnet Controlled Robot test code
 *  can control the robot over telnet
 *  f - forward
 *  b - backward
 *  l - left
 *  r - right
 *  s - stop
 *  q - quit
 *  
 *  Copyright LeRoy Miller, 2019
 */

// Load Wi-Fi library
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LOLIN_I2C_MOTOR.h>

LOLIN_I2C_MOTOR motor; //I2C address 0x30

// Replace with your network credentials
const char* ssid     = "ESPRobotAP";
const char* password = "123456789";

uint8_t dutyCycle = 25;

// Set web server port number to 80
WiFiServer server(23);

// Variable to store the HTTP request
String header;

void setup() {
  Serial.begin(9600);
  while (motor.PRODUCT_ID != PRODUCT_ID_I2C_MOTOR) //wait motor shield ready.
  {
    motor.getInfo();
  }
  motor.changeFreq(MOTOR_CH_BOTH, 1000); //Change A & B 's Frequency to 1000Hz.

  // Connect to Wi-Fi network with SSID and password
  
  
  WiFi.softAP(ssid, password);
  
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header = c;
        
            //Forward
            if (header == "f") {
              Serial.println("Forward");
              forward();
              } 
              
            //Backward
            else if (header == "b") {
              Serial.println("backward");
              backward();
            } 
            
            //Left
            else if (header == "l") {
              Serial.println("left");
              left();
            } 
            
            //Right
            else if (header == "r") {
              Serial.println("right");
              right();
            } 

            //stop
            else if (header == "s") {
              Serial.println("stop");
              stop();
            }

            else if (header == "q") {
              break;
            }
        }
      }
    }
   
    client.stop();

}

void forward() {
  stop();
  motor.changeDuty(MOTOR_CH_BOTH, dutyCycle);
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CCW);
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CW);
}

void backward() {
  stop();
  motor.changeDuty(MOTOR_CH_BOTH, dutyCycle);
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CCW);
}

void stop() {
  motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_STOP);
}

void left() {
  stop();
  motor.changeDuty(MOTOR_CH_BOTH, dutyCycle);
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CW);
}

void right() {
  stop();
  motor.changeDuty(MOTOR_CH_BOTH, dutyCycle);
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CCW);
}
