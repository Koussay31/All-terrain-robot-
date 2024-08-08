#include <Arduino.h>
// Include the PS4Controller library to enable connection and control of a PS4 controller with the ESP32 via Bluetooth.
#include <PS4Controller.h> 

// Define the GPIO pins used for controlling the motors
#define rm1 14 // Right motor input pin 1
#define rm2 27 // Right motor input pin 2
#define lm1 21 // Left motor input pin 1
#define lm2 19 // Left motor input pin 2
#define v1 25 // PWM pin for controlling the speed of the right motor
#define v2 26 // PWM pin for controlling the speed of the left motor

// Initialize variables to store the state of the PS4 controller's analog sticks
int yz=0;
int xz=0;

int power =195;
int test;

// put function definitions here:

// Function to move the robot forward
void   AVANT (){
    digitalWrite(rm1, HIGH);   
    digitalWrite(rm2, LOW);
    
     digitalWrite(lm1, HIGH);   
    digitalWrite(lm2, LOW);
   
    ledcWrite(1, power);
    ledcWrite(2, power);

} 
     
// Function to move the robot backward
void ARRIERE (){
    digitalWrite(rm1, LOW);   
    digitalWrite(rm2, HIGH);
    
     digitalWrite(lm1, LOW);   
    digitalWrite(lm2, HIGH);
   
   ledcWrite(1, power);
    ledcWrite(2, power);

}

// Function to turn the robot to the right
void DROITE(){
    digitalWrite(rm1, HIGH);   
    digitalWrite(rm2, LOW);
    
     digitalWrite(lm1, LOW);   
    digitalWrite(lm2, HIGH);
   
   ledcWrite(1, power);
    ledcWrite(2, power);

}

// Function to make the robot turn right with a longer radius
void DROITE_LONG(){
    digitalWrite(rm1, HIGH);   
    digitalWrite(rm2, LOW);
    
     digitalWrite(lm1, HIGH);   
    digitalWrite(lm2, HIGH);
   
   ledcWrite(1, power);
    ledcWrite(2, power);

}

// Function to turn the robot to the left
void GAUCHE(){
    digitalWrite(rm1, LOW);   
    digitalWrite(rm2, HIGH);
    
     digitalWrite(lm1, HIGH);   
    digitalWrite(lm2, LOW);
   
    ledcWrite(1, power);
    ledcWrite(2, power);

}

// Function to make the robot turn left with a longer radius
void GAUCHE_LONG(){
    digitalWrite(rm1, HIGH);   
    digitalWrite(rm2, HIGH);
    
     digitalWrite(lm1, HIGH);   
    digitalWrite(lm2, LOW);
   
    ledcWrite(1, power);
    ledcWrite(2, power);

}

// Function to stop the robot
void STOP(){
    digitalWrite(rm1, LOW);   
    digitalWrite(rm2, LOW);
    
     digitalWrite(lm1, LOW);   
    digitalWrite(lm2, LOW);
   
    ledcWrite(1, power);
    ledcWrite(2, power);

}
void sens1(){
  //void loop()
 
{  int y =(PS4.data.analog.stick.ly);  //Left stick  - y axis - forward/backward car movement
  int x =(PS4.data.analog.stick.rx);  //Right stick - x axis - left/right car movement
  if ((x!=xz)||(y!=yz)){
  Serial.println("y=");
  Serial.print(y);
  Serial.println("x=");
  Serial.println(x);}
  if (PS4.isConnected()){
    if (PS4.event.button_down.r1 && power<236)
       {power =power+20;}
    if (PS4.event.button_down.l1 && power>195)
       {power =power-20;}   
     if( PS4.data.button.triangle|| PS4.data.button.up) 
    {
      AVANT();
       Serial.print ("avant");
        Serial.print ("\n");
       
    }
    else if( PS4.data.button.cross || PS4.data.button.down)
    {
      ARRIERE();
       Serial.print ("arrière");
      Serial.print ("\n");
    }        
     else if (  PS4.data.button.square || PS4.data.button.left)
    {
      GAUCHE();
       Serial.print ("gauche");
      Serial.print ("\n");
    }        
    else if (  PS4.data.button.circle || PS4.data.button.right)
    {
      DROITE();
       Serial.print ("droite");
      Serial.print ("\n");
    } 
    else if ( PS4.data.button.r2 )
    {
      DROITE_LONG();
       Serial.print ("droite_long");
      Serial.print ("\n");
    }  
     else if ( PS4.data.button.l2 )
    {
      GAUCHE_LONG();
       Serial.print ("gauche_long");
      Serial.print ("\n");
    } 
    else     {
      STOP();
       Serial.print ("stop");
      Serial.print ("\n");
    }
   
    
    
    /*if( PS4.data.button.cross ){
      Serial.println("Pressing the cross button");
    }
      
    if( PS4.data.button.square ){
      Serial.println("Pressing the square button");
    }
      
    if( PS4.data.button.triangle ){
      Serial.println("Pressing the triangle button");
    }
      
    if( PS4.data.button.circle ){
      Serial.println("Pressing the circle button");
    }*/
  }
      yz=y;
      xz=x;
}
}
void sens2(){
  //void loop()
{ 
  int y =(PS4.data.analog.stick.ly);  //Left stick  - y axis - forward/backward car movement
  int x =(PS4.data.analog.stick.rx);  //Right stick - x axis - left/right car movement
  if ((x!=xz)||(y!=yz)){
  Serial.println("y=");
  Serial.print(y);
  Serial.println("x=");
  Serial.println(x);}
  if (PS4.isConnected()){
    if (PS4.event.button_down.r1 && power<236)
       {power =power+20;}
    if (PS4.event.button_down.l1 && power>195)
       {power =power-20;}   
     if(y<-20 || PS4.data.button.triangle|| PS4.data.analog.button.up) 
    {
      //AVANT();
      ARRIERE();
       Serial.print ("avant");
        Serial.print ("\n");
       
    }
    else if(y>20 || PS4.data.button.cross || PS4.data.button.down )
    {
      //ARRIERE();
      AVANT();
       Serial.print ("arrière");
      Serial.print ("\n");
    }        
     else if ( x<-20|| PS4.data.button.square || PS4.data.button.left )
    {
      //GAUCHE();
      DROITE();
       Serial.print ("gauche");
      Serial.print ("\n");
    }        
    else if ( x>20 || PS4.data.button.circle || PS4.data.button.right  )
    {
      //DROITE();
      GAUCHE();
       Serial.print ("droite");
      Serial.print ("\n");
    }  
    else if ( PS4.data.button.r2 )
    {
      //DROITE_LONG();
      GAUCHE_LONG();
       Serial.print ("droite_long");
      Serial.print ("\n");
    }  
     else if ( PS4.data.button.l2 )
    {
      //GAUCHE_LONG();
      DROITE_LONG();
       Serial.print ("gauche_long");
      Serial.print ("\n");
    } 
    else     {
      STOP();
       Serial.print ("stop");
      Serial.print ("\n");
    }
   
    
    
    /*if( PS4.data.button.cross ){
      Serial.println("Pressing the cross button");
    }
      
    if( PS4.data.button.square ){
      Serial.println("Pressing the square button");
    }
      
    if( PS4.data.button.triangle ){
      Serial.println("Pressing the triangle button");
    }
      
    if( PS4.data.button.circle ){
      Serial.println("Pressing the circle button");
    }*/
  }
      yz=y;
      xz=x;
}
}

void setup()
{
   // put your setup code here, to run once:
  

  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  ledcAttachPin(v1, 1);
  ledcAttachPin(v2, 2);
  ledcSetup(1, 12000, 8);
  ledcSetup(2, 12000, 8);
//  pinMode(v1,OUTPUT);
//  pinMode(v2,OUTPUT);

Serial.begin(9600);
PS4.begin("a0:b7:65:dc:01:ca");//08:3a:f2:52:e0:4e 
Serial.println("Ready.");
  
}


void loop()
{
  if (PS4.data.button.share){test=1;
  Serial.println("start");}
  else if (PS4.data.button.options){test=2;
  Serial.println("select");}
switch (test)
{
  case 1 :
  sens1();
  break;

  case 2 :
  sens2();
  break;

  default :
  
  break;
}
}
/*if (PS4.event.button_down.start){ 
  void loop()
  {sens1();}
}

else 
if (PS4.event.button_down.select){sens2();}
}*/