#include "scheduler.h"
#include "fsm.h"
#include "software_time.h"
#include <Arduino.h>

void TIMER_ISR(void *pvParameters) {
  while(1) {
    SCH_Update(); 
   
    vTaskDelay(pdMS_TO_TICKS(10)); 
  }
}



void setup() {
  initTrafficLight();
  // SET UP TASK
  xTaskCreate(TIMER_ISR,       
              "TIMER_ISR",     
              2048,             
              NULL,          
              2,               
              NULL);        
  // Initialize the scheduler
  SCH_Init();
  SCH_Add_Task(timerRun,0,1);
  SCH_Add_Task(stateMachine,0,1);
}
void loop() {
 
  SCH_Dispatch_Tasks();
}
