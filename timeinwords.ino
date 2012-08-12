#include <SPI.h>        //SPI.h must be included as DMD is written by SPI (the IDE complains otherwise)
#include <DMD.h>        //
#include <TimerOne.h>   //
#include "SystemFont5x7.h"
#include "Arial_black_16.h"


//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

long   i = 0;
int x = 0;
        
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
  
  x++;
  
  /* The initializer is set to 5000 microseconds. 1,000,000 is 1 second 
     so 200 = 1,000,000 / 5000. Execute every second! */
  if (x == 200) {
     x=0;
     i++; 
  
    int hours = i / 3600;
    int minutes = i / 60;
    int seconds = i - ((hours * 60) + (minutes * 60));

    char hrs[4];
    char mins[4];
    char secs[4];
    
    Serial.println("Hours: " + String(hours) + 
      " Min: " + String(minutes) + 
      " Sec:" + String(seconds));

    formatTimeDigits(hrs, hours);
    formatTimeDigits(mins, minutes);
    formatTimeDigits(secs, seconds);
    
    dmd.drawString(0, 0, hrs, 3, GRAPHICS_NORMAL );
    dmd.drawString(16, 0, mins, 2, GRAPHICS_NORMAL );
    dmd.drawString(0, 8, secs, 2, GRAPHICS_NORMAL );
  }
}

void setup() {
   
  Serial.begin(9600);
   
   Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()

   //clear/init the DMD pixels held in RAM
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
   dmd.selectFont(System5x7);
}

void formatTimeDigits(char strOut[4], int num)
{
  strOut[0] = '0' + (num / 10);
  strOut[1] = '0' + (num % 10);
  strOut[2] = ':';
  strOut[3] = '\0';
}

void loop() {
  // put your main code here, to run repeatedly: 
}
