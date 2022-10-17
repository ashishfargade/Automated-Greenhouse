

// SDA pin of I2c to pin 21
// SCL pin of I2c to pin 22
#include <LiquidCrystal_I2C.h>

#include <dht.h>

dht DHT;

LiquidCrystal_I2C lcd (0x27, 16,2); 

#define dht_apin A0

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int bulb = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(bulb,OUTPUT);

  // Initialize the LCD connected 
  lcd. init();
  
  // Turn on the backlight on LCD. 
  lcd. backlight();
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(500);//Wait before accessing Sensor
  
}

void loop() {

    DHT.read11(dht_apin);

    lcd. setCursor (0,0);
    lcd.print ("H=");
    lcd.print (DHT.humidity);
    lcd.print (", T=");
    lcd.print (DHT.temperature);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");


    if (DHT.humidity >= 70  and  DHT.temperature < 31){
      //FAN ON, BULB ON

       lcd. setCursor (0,1);
       lcd.print ("FAN ON ,BULB ON ");
       
       digitalWrite(motor1pin1, HIGH);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, HIGH);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, LOW);
       delay(1000);
       
    }


    else if(DHT.humidity >= 70 and DHT.temperature >35){
      //FAN ON, BULB OFF

       lcd. setCursor (0,1);
       lcd.print ("FAN ON ,BULB OFF");

       digitalWrite(motor1pin1, HIGH);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, HIGH);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, HIGH);
       delay(1000);
    }


    else if(DHT.humidity < 70 and DHT.temperature < 31){
      //FAN OFF, BULB ON
      
       lcd. setCursor (0,1);
       lcd.print ("FAN OFF,BULB ON ");

       digitalWrite(motor1pin1, LOW);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, LOW);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, LOW);
       delay(1000);
    }


    else if(DHT.humidity < 70 and DHT.temperature > 35){
      //FAN ON , BULB OFF

       lcd. setCursor (0,1);
       lcd.print ("FAN ON ,BULB OFF");

       digitalWrite(motor1pin1, HIGH);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, HIGH);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, HIGH);
       delay(1000);
    }


    else if(DHT.humidity >= 70 and 31<=DHT.temperature<=35){
      //FAN ON , BULB OFF

       lcd. setCursor (0,1);
       lcd.print ("FAN ON ,BULB OFF");
      
       digitalWrite(motor1pin1, HIGH);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, HIGH);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, HIGH);
       delay(1000);
    }



    else{
      //FAN OFF, BULB OFF (temperature is bw 31 to 35 and humidity < 70)

       lcd. setCursor (0,1);
       lcd.print ("FAN OFF,BULB OFF");
      
       digitalWrite(motor1pin1, LOW);
       digitalWrite(motor1pin2, LOW);
       digitalWrite(motor2pin1, LOW);
       digitalWrite(motor2pin2, LOW);

       digitalWrite(bulb, HIGH);
       delay(1000);
      
    }
}
