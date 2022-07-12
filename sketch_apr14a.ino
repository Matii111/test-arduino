#include <TimeLib.h>
#include <TM1637Display.h>
#define CLK 6
#define DIO 7

TM1637Display display(CLK,DIO);

int pulsador = 1;
int led=0;
int i=0;
int estado = LOW;

const uint8_t hello[]={
  SEG_C | SEG_E | SEG_F | SEG_G,
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
  SEG_E | SEG_C | SEG_B | SEG_F,
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F 
};

void setup(){
  pinMode(led,OUTPUT);
  pinMode(pulsador,INPUT);
    
  //setup display
  display.setBrightness(5);
  setTime(23,59,45,14,4,2022);
}

void loop() {
  //-> reloj
  //-->display hello
  if (i==0){i+=1;
    display.setSegments(hello,4,0);
    delay(5000);
    display.clear()
    ;}
    digitalWrite(led,HIGH);
    time_t t =now();

//--> menu reloj
      int button = digitalRead(pulsador); 
    if(button!=HIGH){  
      int button = digitalRead(pulsador); 
      if (minute(t)>=0 or minute(t)<=9){
        display.showNumberDec(minute(t),true,2,2);
      }else{display.showNumberDec(minute(t),false,2,2);}
      display.showNumberDecEx(hour(t),0b01000000,true,2,0);
    ;}
    while(button==HIGH){
      display.showNumberDecEx(day(t),0b01000000,false,2,0);
      display.showNumberDec(month(t),false,2,2);
      delay(100);
      button = LOW
    ;}      
} 
