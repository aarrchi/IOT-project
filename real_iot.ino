#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// defining pin numbers
int trigPin=11;
int echoPin=13;
int buzzerPin =10;

// defining variables
long duration;
int distance;
int distanceCm;
int distanceInch;

void setup() {
  
  pinMode(trigPin, OUTPUT); // sets tripin as an output
  pinMode(buzzerPin, OUTPUT);
  pinMode(echoPin, INPUT); // sets echopin as an input
  Serial.begin(9600); // starts the serial connection 
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
 
  
}

void loop() {
  // main code 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;  //giving distance in cm
  distanceInch=duration*0.0133/2; // giving distance in inch

 
  

  if(distance<=10)
  {
    Serial.println(distance);
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
    lcd.print("Distance: "); // Prints string "Distance" on the LCD
    // Prints the distance value from the sensor
    lcd.print(distance);
    lcd.print(" cm");
    delay(10);
    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distanceInch);
    lcd.print(" inch");
    delay(10);
    
    
   
    }
    else{
      digitalWrite(buzzerPin, LOW);
      lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
      lcd.print("Distance: "); // Prints string "Distance" on the LCD
      lcd.print(distance);
      lcd.print(" cm");
      delay(10);
      lcd.setCursor(0, 1);
      lcd.print("Distance: ");
      lcd.print(distanceInch);
      lcd.print(" inch");
      delay(10);
      
      
      }
}
