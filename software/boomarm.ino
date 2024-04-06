#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

const byte pwm1=15;  // D8
int x=0;
String command;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();
  myservo.attach(pwm1);
  Serial.begin(9600);
  Serial.println("Live");
}

boolean isNumeric(String str) {
    unsigned int stringLength = str.length();
 
    if (stringLength == 0) {
        return false;
    }
 
    boolean seenDecimal = false;
 
    for(unsigned int i = 0; i < stringLength; ++i) {
        if (isDigit(str.charAt(i))) {
            continue;
        }
 
        if (str.charAt(i) == '.') {
            if (seenDecimal) {
                return false;
            }
            seenDecimal = true;
            continue;
        }
        return false;
    }
    return true;
}

void loop() {
    if(Serial.available()){ // parse command
    command = Serial.readStringUntil('\n');
      if (isNumeric(command.c_str()) == 1) { // if only digits -> store integer given as var 'x'
        x = int(command.toFloat());
        myservo.write(x);
      }
        
      else if(command.equals("reset")){
        //ESP.restart(); //ESP.reset();
      }
      else{
        Serial.println("Invalid Command");
        Serial.println(command);
      }
         
  }
}
