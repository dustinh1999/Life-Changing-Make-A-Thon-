

/*
/* Grove - Temperature Sensor demo v1.0
*  This sensor detects the environment temperature,
*  Connect the signal of this sensor to A1, use the
*  Serial monitor to get the result.
*  By: http://www.seeedstudio.com
*  
*/
#include <rgb_lcd.h>
#include <Wire.h>



int a;
float temperature=0;
int B=6000;                  //B value of the thermistor
float resistance;
int x;
  int colorR = 0;
  int colorG = 0;
  int colorB = 0;
rgb_lcd lcd;

void setup()
{
    Serial.begin(9600);
    pinMode(7, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode (5, OUTPUT);
    
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    
    pinMode(4,OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);

    pinMode(11, OUTPUT);
    
   digitalWrite(7, HIGH);
   digitalWrite(6, HIGH);
   digitalWrite(5, HIGH);
   
   digitalWrite(10, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(8, HIGH);
   
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);

  digitalWrite(11, LOW);
  

    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
   

    delay(1000);


}

void loop()
{
      lcd.clear();
      lcd.print("temperature:");
      lcd.print(temperature);
      
     
    a=analogRead(A1);
    resistance=(float)(1023-a)*10000/a; //get the resistance of the sensor;
  temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet&nbsp;;
  // temperature=17.5;
    Serial.println(resistance);
    delay(1000);
    Serial.print("Current temperature is ");
    Serial.println(temperature);
    if (temperature<14)
    {
    digitalWrite(7,LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(8, HIGH);
   digitalWrite(4, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
    }
    if (temperature>14&&temperature<17)
    {
      digitalWrite(7,HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(10, LOW);
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);
   digitalWrite(4, LOW);
   digitalWrite(3, LOW);
   digitalWrite(2, LOW);
    }
        if (temperature>17)
    {
      digitalWrite(7,LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
   digitalWrite(9, LOW);
   digitalWrite(8, LOW);
   digitalWrite(4, HIGH);
   digitalWrite(3, HIGH);
   digitalWrite(2, HIGH); 
    }
      Serial.println(x);




       // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1);
  
    if (temperature<14){
      digitalWrite(7,LOW);
      colorB = 255;
      colorR=0;
      colorG=0;
    }
    if (temperature>14&&temperature<17){
      
      colorG=255;
      colorR=0;
      colorB=0;
    }
    if (temperature>17){
      colorR = 255;
      colorB=0;
      colorG=0;
      
    }
    if (temperature>25)
      {
          digitalWrite(11, HIGH);
      }
    lcd.setRGB(colorR, colorG, colorB);
    // print the number of seconds since reset:
    lcd.print(millis()/1000);

    delay(100);
    return 5;

}

