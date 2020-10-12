/*
HC-SR04 distance sensor
*/

////////////////
///GenieMaker///
////////////////

#define trigPin A0
#define echoPin A1

// Anything over  (157.48inches) 400 cm (23200 microsecond pulse) is "out of range"
const unsigned int MAX_DIST = 23320;  //23200 

void setup() {
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  
  unsigned long EchoDuration ;
  float cm_distance, inches_distance; 
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);   // Hold the trigger pin high for at least 10 us
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
                                          
  if ( EchoDuration > MAX_DIST ) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(cm_distance);
    Serial.println(" cm");
  }
  
  delay(60); //60ms (millisecond)
}
