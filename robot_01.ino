
#include "Cenas.h"

volatile boolean error = false;

void setup()
{
  pinMode( LED, OUTPUT);
  
  pinMode( PWMA, OUTPUT);
  pinMode( PWMB, OUTPUT);
  analogWrite( PWMA, 0);
  analogWrite( PWMB, 0);
  /*Motors();
  MotorSetup( motor1, motorFree, 0 );
  MotorSetup( motor2, motorFree, 0 );  
*/
  UpdateLed();
}


void UpdateLed()
{
  digitalWrite( LED, error );
}


void loop()
{

  digitalWrite( LED, 1 );  // DIR1
  analogWrite( PWMA, 100);
  digitalWrite( PWMB, HIGH);

}

  /*
  for ( int x = 0; x < 101; x++)
  {
    error = MotorSetup( motor2, motorFRW, x );
    UpdateLed();
    delay(200);
  }
  
  error = MotorSetup( 3, motorFRW, 2 );
  UpdateLed();
  delay(1000);
  
  for ( int x = 100; x > 1; x--)
  {
    error = MotorSetup( motor2, motorFRW, x );
    UpdateLed();
    delay(200);
  }
  */

