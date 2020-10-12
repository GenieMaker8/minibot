/* Arduino L298N Motor Driver Test
*/
#define PARALLEL 0  
 
//Define all the L298N control pins from Arduino pins 
//     L298N_pins  Arudino_pins    

#define enB           11
#define in4           10  // analogwrite (PWM) will be disabled by servo.h. digitalWrite is still ok
#define in3            9  // analogwrite (PWM) will be disabled by servo.h. digitalWrite is still ok

#define in2            8
#define in1            7
#define enA            6

class Motor{  //Class is used to create an object

  //class object internal value: speed and direction Pin    
  private: 
  
  int enableSpeedPin;
  int firstDirectionPin;
  int secondDirectionPin;
  
  public:

  //https://www.geeksforgeeks.org/c-classes-and-objects/
  //Constructors have the same name as the class to set class object internal values. 
  //For motor, they are speed and direction pins  
  
  Motor(int enPin, int firstPin, int secondPin){
    enableSpeedPin = enPin;
    firstDirectionPin = firstPin;
    secondDirectionPin = secondPin;
  };
 
  //'Drive' Method to drive motor in 'dir' direction at 'speed'
  //Speed: 0 - 255 
  //Direction: 0 (forward)  1 (backward)
  
  Drive(int speed, int dir ){
    if(dir == 0 ){
      digitalWrite(firstDirectionPin, HIGH);
      digitalWrite(secondDirectionPin, LOW);
    }
    else{
      digitalWrite(firstDirectionPin, LOW);
      digitalWrite(secondDirectionPin, HIGH);
    }
    analogWrite(enableSpeedPin, speed);
  }
  
};

Motor MotorA = Motor(enA, in1, in2);  //left or front motor 
Motor MotorB = Motor(enB, in3, in4);  //right or back motor


void setup() {

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  //Set initial value of speed and direction 
  digitalWrite(enA, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  MotorA.Drive(0, 1); //speed zero mean stop 

  digitalWrite(enB, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  MotorB.Drive(0, 1); //speed zero mean stop 

}
 
void loop() {

  #if PARALLEL == 1  //two motors in parallel position. Both motors control left and right. Both also control forward and backward  
    MotorA.Drive(155, 0); //0 mean forward //1 mean backward //A on the left
    MotorB.Drive(155, 1); //0 mean forward //1 mean backward //B on the right
    delay(550);
  
    MotorA.Drive(0, 0);
    MotorB.Drive(0, 0);   
    delay(300);
  
    MotorA.Drive(205, 0);
    MotorB.Drive(205, 0);
    delay(550);
  
    MotorA.Drive(0, 0);
    MotorB.Drive(0, 0);   
    delay(300);
  #else

    MotorA.Drive(150, 1); //0 mean Right 
    MotorB.Drive(150, 1);   //0 backward and 1 mean forward 
    delay(300);

  #endif 
 
}
