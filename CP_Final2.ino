const int sensor_pin1 = A0;  /* Soil moisture sensor O/P pin */
const int sensor_pin2 = A1;

// SDA pin of I2c to pin A4
// SCL pin of I2c to pin A5
#include <LiquidCrystal_I2C.h>
#include <dht.h>

dht DHT;

// Create the lcd object address 0x3F and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2);  //

#define dht_apin A2

int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

int mist = 7;

void setup() {

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(mist, OUTPUT);
  
   // Initialize the LCD connected 
  lcd. init();
  
  // Turn on the backlight on LCD. 
  lcd. backlight();

  Serial.begin(9600); /* Define baud rate for serial communication */
  delay(500);

}

void loop() {

  DHT.read11(dht_apin);  
  
  int moisture_percentage1;
  int moisture_percentage2;
  int moisture_average;
  
  int sensor_analog1;
  int sensor_analog2;
  
  sensor_analog1 = analogRead(sensor_pin1);
  sensor_analog2 = analogRead(sensor_pin2);
  
  moisture_percentage1 = ( 100 - ( (sensor_analog1/1023.00) * 100 ) );
  moisture_percentage2 = ( 100 - ( (sensor_analog2/1023.00) * 100 ) );
  moisture_average = ( moisture_percentage1 + moisture_percentage2 )/2;

  
  lcd. setCursor (0,0); 
  lcd. print ("SM=");
  lcd. print (moisture_average);
 
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_average);
  Serial.print("%\n\n");

  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");

  if(moisture_average<35){
    //PUMP 1 ON
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);

    lcd.setCursor(0,1);
    lcd.print("WP1 ON ,");

    Serial.print("WP1 ON");

    delay(1000);
    }

  else {
    //PUMP 1 OFF
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);

    lcd.setCursor(0,1);
    lcd.print("WP1 OFF,");
    
    Serial.print("WP1 OFF");

    delay(1000);
    }

  if(DHT.humidity<62){
    //PUMP 2 ON
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(mist, HIGH);

    lcd.setCursor(9,1);
    lcd.print("WP2 ON ");
    Serial.print("WP2 ON");

    delay(1000);
    }

    else{
    //PUMP 2 OFF
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    digitalWrite(mist, HIGH);

    lcd.setCursor(9,1);
    lcd.print("WP2 OFF");
    Serial.print("WP2 OFF");

    delay(1000);
    }

 
  
}
