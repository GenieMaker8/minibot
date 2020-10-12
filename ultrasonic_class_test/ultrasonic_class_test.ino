/* Ultrasonic Test
*/

////////////////
///GenieMaker///
////////////////


class mSonicSensor {  //Class is used to create an object

  private: 
    int trigPin ; 
    int echoPin ; 
  
  public:
    float cm_distance = 0.0 ; 
    float inches_distance = 0.0 ; 
    unsigned int MAX_ECHO = 23320;  //23200  // Anything over  (157.48inches) 400 cm (23200 microsecond pulse) is "out of range"
    float MAX_DIST = 0.0 ;  //300cm  
  mSonicSensor(int trig, int echo, const unsigned int range_in, float max_range_in){
    trigPin = trig;
    echoPin = echo;
    MAX_ECHO = range_in;
    MAX_DIST = max_range_in ; //cm
  };


  void Init(){

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
  }

  float checkDistance(); 
  
};


float mSonicSensor::checkDistance(){

  unsigned long EchoDuration ;
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);   // Hold the trigger pin high for at least 10 us
  digitalWrite(trigPin, LOW);
    
  EchoDuration = pulseIn(echoPin, HIGH);
  cm_distance = (EchoDuration/2) / 29.15;  //(microsecond/2) * speed of sound  = (microseconds/2) * 34300cm/s  
                                   //                              = (us/2) * 34300cm/1000000us
                                   //                              = (us/2) * 0.0343cm/us
                                   //                              = (us/2) * 1/29.15                                
                                   //                              = (us/2)/29.15
                                     
  inches_distance = (EchoDuration/2) / 74.05; //microsecond * speed of sound = microseconds * 13503.9inches/s 
                                        //                             = (us/2) * 13503.9inches/1000000us
                                        //                             = (us/2) * 0.0135039 inches/us
                                        //                             = (us/2) * 1/74.05
                                        //                             = (us/2)/74.05

  //Serial.print(pos); Serial.print(" : ");  
  //Serial.print(cm_distance); Serial.println(" cm : ");                                        
 
  if ( EchoDuration > MAX_DIST ) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(cm_distance);
    Serial.println(" cm");
  }
  
  delay(60); //60ms (millisecond)

  return cm_distance ; 

}

mSonicSensor SonicEyes = mSonicSensor(A0, A1, 23320, 300.0);  

void setup() {

  SonicEyes.Init(); 
  
}

void loop() {

  SonicEyes.checkDistance() ; 

}

