////// In The name of ALLAH the beneficent the merciful  \\\
//// created by mohammadhasan Aghanoori \\\\ 
/// Program: 15 degree Celsius Cooler with thermoelectric element TEC1-12706
// 12 mehre 1397

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2    /// the wire of ds18b20
#define Relay_Pin1 4
#define Relay_Pin2 5
int Low_temp=-2;
int High_temp=8;
 
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(Relay_Pin1, OUTPUT);
  digitalWrite(Relay_Pin1, LOW);
  
  pinMode(Relay_Pin2, OUTPUT);
  digitalWrite(Relay_Pin2, LOW);
  
  pinMode(13, OUTPUT);    ///VCC for relay module
  digitalWrite(13, HIGH);
}
 
 
void loop(void)
{
  sensors.requestTemperatures(); 
  Serial.print(sensors.getTempCByIndex(0));
  if (sensors.getTempCByIndex(0) < Low_temp){
    digitalWrite(Relay_Pin1, HIGH);
    digitalWrite(Relay_Pin2, HIGH);
   }
  if (sensors.getTempCByIndex(0) > High_temp){
    digitalWrite(Relay_Pin1, LOW);
    digitalWrite(Relay_Pin2, LOW);
  }
}
