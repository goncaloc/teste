

void Motors()
{
  pinMode( PWMA, OUTPUT);
  pinMode( PWMB, OUTPUT);
  pinMode( AIN1, OUTPUT);
  pinMode( AIN2, OUTPUT);
  pinMode( BIN1, OUTPUT);
  pinMode( BIN2, OUTPUT);
  pinMode( STBY, OUTPUT);
  
  digitalWrite( STBY, LOW );
  analogWrite( PWMA, 0);
  analogWrite( PWMB, 0);

  digitalWrite( AIN1, LOW );
  digitalWrite( AIN2, LOW );
 
  digitalWrite( BIN1, LOW );
  digitalWrite( BIN2, LOW );
  
}  

boolean MotorSetup( int M, int dir, int spd )
{
  boolean erro = false;
  byte PWMvalue = spd;

  //PWMvalue = map(abs(spd),0,100,50,255); //anything below 50 is very weak
  
  if ( M == 1 ) // Setup Motor1
  {
    switch ( dir )
    {
      case 0: // Break
        digitalWrite( AIN1, HIGH );
        digitalWrite( AIN2, HIGH );
        break;
      case 1: // Forward
        digitalWrite( AIN1, LOW );
        digitalWrite( AIN2, HIGH );
        break;
      case 2: // Backward
        digitalWrite( AIN1, HIGH );
        digitalWrite( AIN2, LOW );
        break;
      case 3: // FreeRun
        digitalWrite( AIN1, LOW );
        digitalWrite( AIN2, LOW );
        break;
    }
    analogWrite( PWMA, PWMvalue);
  }
  
  else if ( M == 2 ) // Setup Motor2
  {
    switch ( dir )
    {
      case 0: // Break
        digitalWrite( BIN1, HIGH );
        digitalWrite( BIN2, HIGH );
        break;
      case 1: // Forward
        digitalWrite( BIN1, LOW );
        digitalWrite( BIN2, HIGH );
        break;
      case 2: // Backward
        digitalWrite( BIN1, HIGH );
        digitalWrite( BIN2, LOW );
        break;
      case 3: // FreeRun
        digitalWrite( BIN1, LOW );
        digitalWrite( BIN2, LOW );
        break;
    }
    analogWrite( PWMB, PWMvalue);
  }
  else
    erro = true;



  return erro;
}


/*
  digitalWrite( STBY, HIGH ); // ENABLE
  digitalWrite( STBY, LOW ); // DISABLE

  3 bits Mode
  
  // DIR1
  digitalWrite( AIN1, LOW );
  digitalWrite( AIN2, HIGH );

  // DIR2
  digitalWrite( AIN1, HIGH );
  digitalWrite( AIN2, LOW );
  
  // BRAKE
  digitalWrite( AIN1, HIGH );
  digitalWrite( AIN2, HIGH );

   // FREE
  digitalWrite( AIN1, LOW );
  digitalWrite( AIN2, LOW );

  2 bits Mode - PWM set HIGH
  
  // DIR1
  analogWrite( PWMA, 100);
  digitalWrite( PWMB, LOW);
  
  // BRAKE
  digitalWrite( PWMA, HIGH);  
  digitalWrite( PWMB, HIGH);
  
  // DIR2
  digitalWrite( PWMA, LOW);
  analogWrite( PWMB, 100);

  // FREE
  digitalWrite( PWMA, LOW);  
  digitalWrite( PWMB, LOW);

*/
