#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2
#define FLOW_SENSOR_PIN 3

LiquidCrystal_I2C lcd(0x27,16,2);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

volatile int pulseCount = 0;
float flowRate;
unsigned long oldTime = 0;
c:\Users\shahc:\Users\shahi\OneDrive\Documents\Arduino\libraries\OV7670i\OneDrive\Documents\Arduino\libraries\OV7670
void pulseCounter()
{
  pulseCount++;
}

void setup()
{
  Serial.begin(9600);

  sensors.begin();

  pinMode(FLOW_SENSOR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, RISING);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop()
{
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  if ((millis() - oldTime) > 1000)
  {
    detachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN));

    flowRate = pulseCount / 7.5;
    pulseCount = 0;
    oldTime = millis();

    attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, RISING);

    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(0,1);
    lcd.print("Flow:");
    lcd.print(flowRate);
    lcd.print(" L/m");

    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print(" C  Flow: ");
    Serial.print(flowRate);
    Serial.println(" L/min");
  }
}