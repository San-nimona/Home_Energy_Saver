#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int PIRSENSOR1=7;
int PIRSENSOR2=8;
int relaylighting=13;
int peoplein;
int peopleout;
int countedin=0;
int countedout=0;
int temperaturepin=A0;
int relayfan=10;
int temperature=0;
int in;
int out;
int result;
int ldr= A1;
int ldrvalue;
void setup() 
{
  lcd.begin(20,4);
pinMode(PIRSENSOR2,INPUT);
digitalWrite(relaylighting,LOW);
pinMode(relaylighting,OUTPUT);
pinMode(relayfan,OUTPUT);
pinMode(ldr,INPUT);
digitalWrite(relayfan,LOW);


Serial.begin(9600);
  
}

void loop() {
   ldrvalue=analogRead(ldr);
   //Serial.println(ldrvalue);
   //delay(200);

peoplein=digitalRead(PIRSENSOR1);

peopleout=digitalRead(PIRSENSOR2);
if(peoplein==0)
{
  in=countedin++;
}
if (peopleout==0)
{out=countedout++;
if(out<0&&result<0){
   
  out=0;
  countedout=0;
    in=0;
     
  countedin=0;
  result=0;
  }}

result=in-out;
Serial.println(in);
   delay(200);
   Serial.println(out);
   delay(200);
   Serial.println(result);
   delay(200);
    Serial.println(temperature);
   delay(200);
   Serial.println(ldrvalue);
   delay(200);
if(ldrvalue<80 && result>0)

{

  digitalWrite(relaylighting,LOW);
  delay(200);
  
  }
  else{
 digitalWrite(relaylighting,HIGH);
 delay(200);
  
}
if(result<0){
  
  out=0;
  countedout=0;
    in=0;
     
  countedin=0;
  result=0;
  
  
  
  
  }
  temperature=readtemperature();
  if(result>0&&temperature>24){
    digitalWrite(relayfan,HIGH);
    }
    else{
        digitalWrite(relayfan,LOW);
      
      }

lcd.clear();
lcd.setCursor(0,0);
lcd.print("peoplein");
lcd.setCursor(0,1);
lcd.print("peopleout");
lcd.setCursor(10,0);
lcd.print(in);
lcd.setCursor(10,1);
lcd.print(out);
lcd.setCursor(0,2);
lcd.print("occupancy");
lcd.setCursor(10,2);
lcd.print(result);
delay(200);
lcd.clear(); 
lcd.setCursor(0,0);
lcd.print("resistance is");
lcd.setCursor(16,0);
lcd.print(ldrvalue);
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("temp=");
lcd.print(temperature);
lcd.setCursor(0,1);
delay(200);
if(ldrvalue<=50)
{
  
lcd.clear(); 
lcd.setCursor(1,0);
lcd.print("it's night");
lcd.setCursor(0,1);
lcd.print("resistance is");
lcd.setCursor(14,1);
  lcd.print(ldrvalue);
delay(200);
  }
  if(ldrvalue>80)
  { 
    lcd.clear(); 
        lcd.setCursor(1,0);
         lcd.print("it's daytime");
         delay(1000);}
lcd.clear(); 
lcd.setCursor(1,0);
lcd.print("resistance is");
lcd.setCursor(16,0);
  lcd.print(ldrvalue);
delay(200);

}

int readtemperature(){
  temperature=analogRead(temperaturepin);
  return  temperature*0.48821;
  
  }
