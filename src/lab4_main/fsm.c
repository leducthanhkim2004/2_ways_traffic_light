#include "fsm.h"
#include "software_time.h"
#include<Arduino.h>
#define D3 6
#define D4 7
#define D5 8
#define D6 9
#define STATE1 1
#define STATE2 2
#define STATE3 3
#define STATE4 4
int state = STATE1;
//RED1 GREEN2
void state1(){
  //RED1
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  //GREEN2
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
}
//RED1 yellow2
void state2(){
  //RED1
  digitalWrite(D3,HIGH);
  digitalWrite(D4,HIGH);
  //YELLOW2
  digitalWrite(D5,LOW);
  digitalWrite(D6,HIGH);
}
//yellow1 red2
void state4(){
  //YELLOW 1
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
  //RED2
  digitalWrite(D5,HIGH);
  digitalWrite(D6,HIGH);
}
//GREEN1 RED2
void state3(){
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
  //RED
  digitalWrite(D5,HIGH);
  digitalWrite(D6,HIGH);
}
void stateMachine(void) {
    switch(state) {
      case STATE1:
        // Only change state when timer expires
        if (isTimerExpired(0)) {
          state = STATE2;
          state2();
          setTimer(0, 200);
        }
        break;
      case STATE2:
        if (isTimerExpired(0)) {
          state = STATE3;
          state3();
          setTimer(0, 300);
        }
        break;
      case STATE3:
        if (isTimerExpired(0)) {
          state = STATE4;
          state4();
          setTimer(0, 200);
        }
        break;
      case STATE4:
        if (isTimerExpired(0)) {
          state = STATE1;
          state1();
          setTimer(0, 300);
        }
        break;
      default:
        break;
    }
}
void initTrafficLight(void) {
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  
  // Initialize first state
  state1();
  setTimer(0, 300);
}