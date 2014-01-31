/***********************************************************************************
 *     ______            RobotGeek Pan and Tilt Demo              ______
 *      |  |            Absolute Analog Control                    |  | 
 *      |__|_   _                                            _    _|__|
 *      |____|__|                                            |___|____|
 *  The following sketch will allow you to control a Desktop RobotTurret v3 using
 *  the included RobotGeek Joysticl and RobotGeek Pushbutton
 *
 *  Products
 *    http://www.robotgeek.com/robotgeek-pantilt.aspx
 *    http://www.robotgeek.com/robotgeek-geekduino-sensor-kit
 *    http://www.robotgeek.com/robotgeek-slider
 *    http://www.robotgeek.com/robotgeek-rotation-knob
 *    http://www.robotgeek.com/p/power-supply-6vdc-2a.aspx
 *    
 *    
 *  Wiring
 *    Pan Servo - Digital Pin 9 
 *    Tilt Servo - Digital Pin 10 
 *
 *    Knob   - Analog Pin 0
 *    Slider - Analog Pin 1 
 *    Jumper for pins 9/10/11 should be set to 'VIN'
 *  
 *
 *  Control Behavior:
 *    Moving the analog controls will move the servos absolutley - this means that 
 *    whaterver position the analog sensor is at will move the slider to that position
 *    Turning the knob will turn the pan servo absolutley.
 *    Moving the slider will move the tilt servo absolutely. NOTE: The slider is not 
 *      linear and will be more sensitive in the center. 
 *
 *  External Resources
 *
 ***********************************************************************************/


//Includes
#include <Servo.h> 

//Defines
#define PAN 9        //Pan Servo Digital Pin
#define TILT 10       //Tilt Servo Digital Pin

#define KNOB_PIN 0       //Horizontal Joystick Analog Pin
#define SLIDER_PIN 1       //Vertical Joystick Analog Pin 

//generic deadband limits - not all joystics will center at 512, so these limits remove 'drift' from joysticks that are off-center.
#define DEADBANDLOW 482   //decrease this value if drift occurs, increase it to increase sensitivity around the center position
#define DEADBANDHIGH 542  //increase this value if drift occurs, decrease it to increase sensitivity around the center position

//max/min puse values in microseconds to send to the servo
#define PAN_MIN      600  //full counterclockwise for RobotGeek 180 degree servo
#define PAN_MAX      2400 //full clockwise for RobotGeek 180 degree servo
#define TILT_MIN  600     //full counterclockwise for RobotGeek 180 degree servo
#define TILT_MAX  2400    //full clockwise for RobotGeek 180 degree servo


Servo panServo, tiltServo;  // create servo objects to control the pan and tilt servos
int horizontalValue, verticalValue;  //variables to hold the last reading from the analog pins for the horizontal and vertical joystick



int panValue = 1500;   //current positional value being sent to the pan servo. 
int tiltValue = 1500;  //current positional value being sent to the tilt servo. 

int speed = 10;

void setup() 
{ 
  //initialize servos
  panServo.attach(PAN, PAN_MIN, PAN_MAX);      // attaches/activates the pan servo on pin PAN 
  tiltServo.attach(TILT, TILT_MIN, TILT_MAX);  // attaches/activates the tilt servo 

  //Analog pins do not need to be initialized
  
  //use the writeMicroseconds to set the servos to their default positions
  panServo.writeMicroseconds(panValue); 
  tiltServo.writeMicroseconds(tiltValue);
} 

void loop() 
{ 

  /**************Servo Positions *******************************/
  //read the values from the analog sensors/joysticks
  horizontalValue = analogRead(KNOB_PIN);
  verticalValue = analogRead(SLIDER_PIN);

  tiltValue = map(verticalValue, 0, 1023, PAN_MAX, PAN_MIN); //Map analog value from native joystick value (0 to 1023) to incremental change (PAN_MAX to PAN_MIN) Note that the program is mapping inversely - this is to allow the knob movement to match the servo movement
  panValue = map(horizontalValue, 0, 1023, TILT_MAX, TILT_MIN); //Map analog value from native joystick value (0 to 1023) to incremental change (TILT_MAX to TILT_MIN) Note that the program is mapping inversely - this is to allow the slider movement to match the servo movement
 
  //use the writeMicroseconds to set the servos to their new positions
  panServo.writeMicroseconds(panValue); 
  tiltServo.writeMicroseconds(tiltValue);
} 

