#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

long i = 0;
int x = 0;
int switchPin = 3;
boolean buttonPressed = false;

void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
  
  x++;


    
  /* The initializer is set to 5000 microseconds. 1,000,000 is 1 second 
     so 200 = 1,000,000 / 5000. Execute every second! */
  if (x == 200) {
     x=0;

    if (buttonPressed == true) {
      i = i + 60;
      buttonPressed = false;
    }
  
    int hours = i / 3600;
    int minutes = (i % 3600) / 60;
    int seconds = i - ((hours * 60 * 60) + (minutes * 60));

    char hrs[4];
    char mins[4];
    char secs[4];
    
 //   Serial.println("Hrs: " + String(hours) +  " Min: " + String(minutes) +  " Sec:" + String(seconds) + " Ticks: " + String(i));
    //Serial.println(freeRam());
    
    formatTimeDigits(hrs, hours);
    formatTimeDigits(mins, minutes);
    formatTimeDigits(secs, seconds);
    
    dmd.drawString(0, 0, hrs, 3, GRAPHICS_NORMAL );
    dmd.drawString(16, 0, mins, 2, GRAPHICS_NORMAL );
    dmd.drawString(0, 8, secs, 2, GRAPHICS_NORMAL );

    dmd.drawFilledBox(13 + (seconds+9)%10, 8, 17 + (seconds+9)%10, 9, GRAPHICS_NOR);
    dmd.drawFilledBox(13 + seconds%10, 8, 17 + seconds%10, 9, GRAPHICS_NORMAL);

    //if (seconds % 2 == 0) {
    //  dmd.drawFilledBox(13, 8, 16, 9, GRAPHICS_INVERSE);
    //}

    dmd.drawFilledBox(13,10,22,15,GRAPHICS_NOR);
    
    switch (seconds%10){
      case 0 :
         dmd.drawFilledBox(13,10,13,10,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,10,14,10,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,10,15,10,GRAPHICS_NORMAL);
         break;
      case 3 :
         dmd.drawFilledBox(16,10,16,10,GRAPHICS_NORMAL);
         break;
      case 4 :
         dmd.drawFilledBox(17,10,17,10,GRAPHICS_NORMAL);
         break;
      case 5 :
         dmd.drawFilledBox(18,10,18,10,GRAPHICS_NORMAL);
         break;
      case 6 :
         dmd.drawFilledBox(19,10,19,10,GRAPHICS_NORMAL);
         break;
      case 7 :
         dmd.drawFilledBox(20,10,20,10,GRAPHICS_NORMAL);
         break;
      case 8 :
         dmd.drawFilledBox(21,10,21,10,GRAPHICS_NORMAL);
         break;
      case 9 :
         dmd.drawFilledBox(22,10,22,10,GRAPHICS_NORMAL);
    }
    switch (seconds/10) {
      case 0 :
         dmd.drawFilledBox(13,11,13,11,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,11,14,11,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,11,15,11,GRAPHICS_NORMAL);
         break;
      case 3 :
         dmd.drawFilledBox(16,11,16,11,GRAPHICS_NORMAL);
         break;
      case 4 :
         dmd.drawFilledBox(17,11,17,11,GRAPHICS_NORMAL);
         break;
      case 5 :
         dmd.drawFilledBox(18,11,18,11,GRAPHICS_NORMAL);
         break;
      case 6 :
         dmd.drawFilledBox(19,11,19,11,GRAPHICS_NORMAL);
         break;
      case 7 :
         dmd.drawFilledBox(20,11,20,11,GRAPHICS_NORMAL);
         break;
      case 8 :
         dmd.drawFilledBox(21,11,21,11,GRAPHICS_NORMAL);
         break;
      case 9 :
         dmd.drawFilledBox(22,11,22,11,GRAPHICS_NORMAL);
    }
    switch (minutes%10) {
      case 0 :
         dmd.drawFilledBox(13,12,13,12,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,12,14,12,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,12,15,12,GRAPHICS_NORMAL);
         break;
      case 3 :
         dmd.drawFilledBox(16,12,16,12,GRAPHICS_NORMAL);
         break;
      case 4 :
         dmd.drawFilledBox(17,12,17,12,GRAPHICS_NORMAL);
         break;
      case 5 :
         dmd.drawFilledBox(18,12,18,12,GRAPHICS_NORMAL);
         break;
      case 6 :
         dmd.drawFilledBox(19,12,19,12,GRAPHICS_NORMAL);
         break;
      case 7 :
         dmd.drawFilledBox(20,12,20,12,GRAPHICS_NORMAL);
         break;
      case 8 :
         dmd.drawFilledBox(21,12,21,12,GRAPHICS_NORMAL);
         break;
      case 9 :
         dmd.drawFilledBox(22,12,22,12,GRAPHICS_NORMAL);
    }
    switch (minutes/10) {
      case 0 :
         dmd.drawFilledBox(13,13,13,13,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,13,14,13,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,13,15,13,GRAPHICS_NORMAL);
         break;
      case 3 :
         dmd.drawFilledBox(16,13,16,13,GRAPHICS_NORMAL);
         break;
      case 4 :
         dmd.drawFilledBox(17,13,17,13,GRAPHICS_NORMAL);
         break;
      case 5 :
         dmd.drawFilledBox(18,13,18,13,GRAPHICS_NORMAL);
         break;
      case 6 :
         dmd.drawFilledBox(19,13,19,13,GRAPHICS_NORMAL);
         break;
      case 7 :
         dmd.drawFilledBox(20,13,20,13,GRAPHICS_NORMAL);
         break;
      case 8 :
         dmd.drawFilledBox(21,13,21,13,GRAPHICS_NORMAL);
         break;
      case 9 :
         dmd.drawFilledBox(22,13,22,13,GRAPHICS_NORMAL);
    }
    switch (hours%10) {
      case 0 :
         dmd.drawFilledBox(13,14,13,14,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,14,14,14,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,14,15,14,GRAPHICS_NORMAL);
         break;
      case 3 :
         dmd.drawFilledBox(16,14,16,14,GRAPHICS_NORMAL);
         break;
      case 4 :
         dmd.drawFilledBox(17,14,17,14,GRAPHICS_NORMAL);
         break;
      case 5 :
         dmd.drawFilledBox(18,14,18,14,GRAPHICS_NORMAL);
         break;
      case 6 :
         dmd.drawFilledBox(19,14,19,14,GRAPHICS_NORMAL);
         break;
      case 7 :
         dmd.drawFilledBox(20,14,20,14,GRAPHICS_NORMAL);
         break;
      case 8 :
         dmd.drawFilledBox(21,14,21,14,GRAPHICS_NORMAL);
         break;
      case 9 :
         dmd.drawFilledBox(22,14,22,14,GRAPHICS_NORMAL);
         break;
    }
    switch (hours/10) {
      case 0 :
         dmd.drawFilledBox(13,15,13,15,GRAPHICS_NORMAL);
         break;
      case 1 :
         dmd.drawFilledBox(14,15,14,15,GRAPHICS_NORMAL);
         break;
      case 2 :
         dmd.drawFilledBox(15,15,15,15,GRAPHICS_NORMAL);
    }
    
    
    i++; 
    if (i >= 86400){
    i = 0;
    }

  }

    
}

void setup() {
   
  Serial.begin(9600);
   
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
   dmd.selectFont(System5x7);
   
   pinMode(switchPin, INPUT);
}

void formatTimeDigits(char strOut[4], int num)
{
  strOut[0] = '0' + (num / 10);
  strOut[1] = '0' + (num % 10);
  strOut[2] = ':';
  strOut[3] = '\0';
}

int freeRam () {
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void loop() {
  // put your main code here, to run repeatedly: 

    if (digitalRead(switchPin) == HIGH)
    {
      dmd.drawFilledBox(30,15,30,15,GRAPHICS_NORMAL);
      //i = i+60;
      buttonPressed = true;
    }
    else
    {
      dmd.drawFilledBox(31,15,31,15,GRAPHICS_NOR);
    }

}