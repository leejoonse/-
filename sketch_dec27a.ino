#include <Bounce2.h>

#define led 7
#define button1 2
#define button2 4
Bounce debouncer_L=Bounce();
Bounce debouncer_R=Bounce();

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  debouncer_L.attach(button1);
  debouncer_R.attach(button2);
  debouncer_L.interval(5);
  debouncer_R.interval(5);
  Serial.begin(9600);
}

void loop() {
  debouncer_L.update();;
  debouncer_R.update();;
  if(debouncer_L.fell()){
   
    digitalWrite(led, HIGH);
    Serial.println("LEFT");
    

  }
  if(debouncer_L.rose()){
    digitalWrite(led, LOW);
    
    Serial.println("RELAEASE");
  }
  if(debouncer_R.fell()){
    
    Serial.println("RIGHT");
    }
  
  if(debouncer_R.rose()){
    
    Serial.println("RELAEASE");
  }
  if(debouncer_L.fell()&&debouncer_R.fell()){
    
    Serial.println("LEFT RIGHT");
  }
  
}
