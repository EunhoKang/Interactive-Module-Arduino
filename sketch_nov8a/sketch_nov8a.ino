#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  myStepper.setSpeed(10);
  Serial.begin(115200);
  
}

void loop() {
  //myStepper.step(512); //90도
  //delay(1000);

  if(Serial.available()){
    while(Serial.available()){
      char data = Serial.read();

      switch(data){
        case 'a':
          myStepper.step(-1);
          break;
        case 'd':
          myStepper.step(1);
          break;
         case 'none':
          myStepper.step(0);
          break;
      }
    }
  }

}