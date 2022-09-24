#include <Arduino.h>
#define LED_RED D2
#define LED_GREEN D3
#define LED_YELLOW D4
#define start D5
#define stop D6


void setup() {
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  pinMode(start,INPUT_PULLUP);
  pinMode(stop, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(start),start_timer, FALLING);
  attachInterrupt(digitalPinToInterrupt(stop),stop_timer, FALLING);
  int state;
  
    /* code */


  // put your setup code here, to run once:
}

ICACHE_RAM_ATTR void start_timer() {
  Serial.println("START");
  digitalWrite(LED_GREEN, LOW);


  //startTimer = true;
  //lastTrigger = millis();
}
ICACHE_RAM_ATTR void stop_timer() {
  Serial.println("STOP");
  digitalWrite(LED_RED, HIGH);
  delay(200);
  digitalWrite(LED_RED,LOW);
  //startTimer = true;
  //lastTrigger = millis();
}

void loop() {

  delay(1000);

  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char ReadFromNode;
    ReadFromNode = Serial.read();
    convert(ReadFromNode); //Convert character to state
  }
}
void convert(char chr){
  if (chr=='run'){
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
  }
}