#include <UTFT.h>

// Declare which fonts we will be using
extern uint8_t Grotesk32x64[24324];
UTFT myGLCD(CTE40, 38, 39, 40, 41); 
int s ;
int Up = A3;
int Down =A0;
int Left = A1;
int Right =A2;
int left, right, left_p, right_p, left_diff, right_diff;
bool r = false;
bool l = false;
bool u = false;
bool d = false;

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long interval = 5;
void setup() {
  // put your setup code here, to run once:
myGLCD.InitLCD();
myGLCD.clrScr();
Serial.begin(250000);
}

int FAR_THRESHOLD = 1000;
int NEAR_THRESHOLD = 550

void loop() {
left = analogRead(Left);
right = analogRead(Right);
up = analogRead(Up);
down = analogRead(Down);
Serial.print(left);
Serial.print(' ');
Serial.println(right);
//This meant that we have picked up a signal at the pd positioned at 
//right side of the device first
if (right >= NEAR_THRESHOLD && right <= FAR_THRESHOLD && left >= FAR_THRESHOLD && up >= FAR_THRESHOLD, && down >= FAR_THRESHOLD) side = 1;
//left side first
if (left >= NEAR_THRESHOLD && left <= FAR_THRESHOLD && right >= FAR_THRESHOLD && up >= FAR_THRESHOLD, && down >= FAR_THRESHOLD) side = 2;
//up side first
if (up >= NEAR_THRESHOLD && up <= FAR_THRESHOLD && right >= FAR_THRESHOLD && left >= FAR_THRESHOLD, && down >= FAR_THRESHOLD) side = 3;
//down side first
if (down >= NEAR_THRESHOLD && down <= FAR_THRESHOLD && right >= FAR_THRESHOLD && left >= FAR_THRESHOLD, && up >= FAR_THRESHOLD) side = 4;
	
	switch (side) {
		//all of our other pds have picked up signals
		//by checking this we make sure that we won't have any any wrong //results due to hand place at right IR sensor and not moving
		case 1: if (right >= FAR_THRESHOLD && left >= NEAR_THRESHOLD && left <= FAR_THRESHOLD && up  >= NEAR_THRESHOLD && up <= FAR_THRESHOLD
		&& down >= NEAR_THRESHOLD && down <= FAR_THRESHOLD) {
			myGLCD.setFont(Grotesk32x64);
      myGLCD.setBackColor(255, 0, 0);
      myGLCD.print("RIGHT", CENTER, 150);
			l = false;
			r = false;
			u = false;
			d = false;
      delay(1000);
      myGLCD.clrScr();
		}
		break;
		case 2: if (left >= FAR_THRESHOLD && right >= NEAR_THRESHOLD && right <= FAR_THRESHOLD && up  >= NEAR_THRESHOLD && up <= FAR_THRESHOLD
		&& down >= NEAR_THRESHOLD && down <= FAR_THRESHOLD) {
			myGLCD.setFont(Grotesk32x64);
      myGLCD.setBackColor(255, 0, 0);
      myGLCD.print("Left", CENTER, 150);
			l = false;
			r = false;
			u = false;
			d = false;
      delay(1000);
      myGLCD.clrScr();
		}
    break;
    case 3: if (up >= FAR_THRESHOLD && right >= NEAR_THRESHOLD && right <= FAR_THRESHOLD && left  >= NEAR_THRESHOLD && left <= FAR_THRESHOLD
		&& down >= NEAR_THRESHOLD && down <= FAR_THRESHOLD) {
			myGLCD.setFont(Grotesk32x64);
      myGLCD.setBackColor(255, 0, 0);
      myGLCD.print("Up", CENTER, 150);
			l = false;
			r = false;
			u = false;
			d = false;
      delay(1000);
      myGLCD.clrScr();
		}
    break;
    case 4: if (down >= FAR_THRESHOLD && right >= NEAR_THRESHOLD && right <= FAR_THRESHOLD && left  >= NEAR_THRESHOLD && left <= FAR_THRESHOLD
		&& up >= NEAR_THRESHOLD && up <= FAR_THRESHOLD) {
			myGLCD.setFont(Grotesk32x64);
      myGLCD.setBackColor(255, 0, 0);
      myGLCD.print("Up", CENTER, 150);
			l = false;
			r = false;
			u = false;
			d = false;
      delay(1000);
      myGLCD.clrScr();
		}
    break;
	}
}
