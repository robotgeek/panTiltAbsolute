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

