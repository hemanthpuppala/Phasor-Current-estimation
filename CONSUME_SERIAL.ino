//#include <avr/wdt.h>
//#include <Filters.h> //Easy library to do the calculations
//#include <Wire.h>

//float testFrequency = 60;                     // test signal frequency (Hz)
//float windowLength = 1/testFrequency;     // how long to average the signal, for statistist

//int Sensor = 0; //Sensor analog input, here it's A0

float pow1=0;
float temp=0;
float bmag=0;
//long tiempo=millis();
int N=0;
unsigned long printPeriod = 100; //Refresh rate
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
const unsigned long intervalo=0;

float get_bmag()
{
  float Bmag=0;
  Bmag = analogRead(A1);//voltaje del sensor de corriente alterna
  return(Bmag);
}

float get_pow1()
{
  float Pow1=0;
  long tiempo=millis();
    Pow1  = analogRead(A2);
  return(Pow1);
}

float get_temp()
{
  float temp=0;
  long tiempo=millis();
  temp = analogRead(A3);
  return(temp);
}


void setup() {
 Serial.begin(9600); 
 pinMode(7, OUTPUT);      // set the LED pin mode
 //wdt_enable(WDTO_8S);
}

void loop() {


 float bmag = get_bmag();
 float pow1 = get_pow1();
 float temp = get_temp();
   
digitalWrite(7, LOW);

//RunningStatistics inputStats;                //Easy life lines, actual calculation of the RMS requires a load of coding
//inputStats.setWindowSecs( windowLength );
  digitalWrite(7, HIGH);
  Serial.print(bmag);
  Serial.print("x");
  Serial.print(pow1);
  Serial.print("x");
  Serial.print(temp);
  Serial.print("x");

digitalWrite(7, LOW); 

    }
    
