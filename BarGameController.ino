
const int xMinPin = 7;
const int xMaxPin = 6;
const int yMinPin = 5;
const int yMaxPin = 4;
const int buttonPin = 3;


void setup() {
  // Initialize Button Pins
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();

  delay(500);


  Joystick.setXAxis(0);
  Joystick.setYAxis(0);

}


const int pinToButtonMap = 2;
int lastButtonState[5] = {0,0,0,0,0};



void loop() {


  int xmin = !digitalRead(xMinPin);
  int xmax = !digitalRead(xMaxPin);

  int ymin = !digitalRead(yMinPin);
  int ymax = !digitalRead(yMaxPin);


  if (xmin == 1) {
    Joystick.setXAxis(-127);
  } else if (xmax == 1) {
    Joystick.setXAxis(127);
  } else {
    Joystick.setXAxis(0);
  }


  if (ymin == 1) {
    Joystick.setYAxis(-127);
  } else if (ymax == 1) {
    Joystick.setYAxis(127);
  } else {
    Joystick.setYAxis(0);
  }


  int currentButtonState = !digitalRead(buttonPin);
  if (currentButtonState != lastButtonState[4])
  {
    Joystick.setButton(0, currentButtonState);
    lastButtonState[4] = currentButtonState;
  }

  
/*  for (int index = 4; index < 5; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

*/

  delay(50);
}
