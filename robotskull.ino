


//int lowest;
//int highest;
double PWM_value;

#include "KalmanFilter.h"

KalmanFilter kalmanFilter; // create with default parameters

void setup() {
  kalmanFilter.setState( getSomeValue() );
  // initialize serial communications (for debugging only):
  Serial.begin(9600);
  //lowest = 1000;
  //highest = 0;
  analogWrite(5, 0);
}

double getSomeValue()  {
    // return values in range 0..1023  
    return analogRead(A0);
}

void loop() {
  // read the sensor:
  //int sensorReading = getSomeValue();
  
  double value = getSomeValue();
  kalmanFilter.correct(value);
  double correctedValue = kalmanFilter.getState();
  
  int PWM_value = map(correctedValue, 500, 620, 0, 255);

  Serial.print(value); Serial.print(" | "); Serial.print(correctedValue); 
  Serial.print(" | "); Serial.println(PWM_value); 
  
  //Serial.println(PWM_value);
  analogWrite(5, PWM_value);
      
  // delay in between reads for stability
  delay(100);
}

