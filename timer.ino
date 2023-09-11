#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

int TimeHours10s =  0;
int TimeHours1s =  0;
int TimeMinutes10s =  0;
int TimeMinutes1s =  0;
int TimeSeconds10s =  0;
int TimeSeconds1s =  0;
int AlarmHours10s =  0;
int AlarmHours1s =  0;
int AlarmMinutes10s =  0;
int AlarmMinutes1s =  0;
int AlarmSeconds10s =  0;
int AlarmSeconds1s =  0;

int t=0;
int l=0;
int Select = 11;
int start = 10;
int Min = 8;
int Hour = 9;
int Buzzer =12;

void setup() 
{
  // initialize I/O pins.
  
  pinMode(Select,INPUT);  //
  pinMode(start, INPUT);  //
  pinMode(Hour, INPUT);  //
  pinMode(Min, INPUT);  //
  pinMode(Buzzer, OUTPUT);  //
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Adjustable Timer"); 
  lcd.setCursor(0,1);
  lcd.print("By Tech garage");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  
//CalculateTime();  
ShowTime();
ShowAlarm();
delay(500);
CompareAlarmTime();
//-------------------------------------setting up Alarm Value------------

if (digitalRead(Select)== HIGH)
{
  t=1;
  }
if(t==1 && digitalRead(Min)== HIGH)
{
  AlarmMinutes1s++;
  delay(500);
  CalculateAlarm();
}
if(t==1 && digitalRead(Hour)== HIGH)
{
  AlarmHours1s++;
  delay(500);
  CalculateAlarm();
}
//----------------------------------------------------------------

if(digitalRead(start)== HIGH)
{
  l=1;

 }
  if(l==1)
  {   CalculateTime();
  }
delay(500);
}

void ShowTime()
  {
  //--------------------------------------------
  // Turn on the display
  lcd.display();
  lcd.setCursor(0, 0); // top left
  lcd.print("Count  ");//
  if(TimeHours10s == 0)
  lcd.print(" ");//
  else
  lcd.print(TimeHours10s);//
  lcd.print(TimeHours1s);//
  lcd.print(":");//
  lcd.print(TimeMinutes10s);//
  lcd.print(TimeMinutes1s);//
  lcd.print(":");//
  lcd.print(TimeSeconds10s);//
  lcd.print(TimeSeconds1s);//
  lcd.setCursor(0, 0); // top left
  }

void ShowAlarm()
  {
  //--------------------------------------------
  // Turn on the display
  //lcd.display();
  lcd.setCursor(0, 1); // bottom left
  lcd.print("set to ");//
  if(AlarmHours10s == 0)
  lcd.print(" ");//
  else
  lcd.print(AlarmHours10s);//
  lcd.print(AlarmHours1s);//
  lcd.print(":");//
  lcd.print(AlarmMinutes10s);//
  lcd.print(AlarmMinutes1s);//
  lcd.print(":");//
  lcd.print(AlarmSeconds10s);//
  lcd.print(AlarmSeconds1s);//
  lcd.setCursor(0, 1); // bottom left
  }

void CalculateTime()
{
 TimeSeconds1s++;
  if(TimeSeconds1s == 10)
  {
  TimeSeconds1s = 0;
  TimeSeconds10s++;
  }
  if(TimeSeconds10s == 6)
  {
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeMinutes1s++;
  }
  if(TimeMinutes1s == 10)
  {
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeMinutes10s++;
  }
  if(TimeMinutes10s == 6)
  {
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeHours1s++;
  }
  if(TimeHours1s == 10) 
  {
  TimeHours1s=0;
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
  TimeHours10s++;
  }
  if(TimeHours10s == 2 && TimeHours1s == 4) 
  {
  TimeHours10s=0; 
  TimeHours1s=0;
  TimeMinutes10s = 0;
  TimeMinutes1s = 0;
  TimeSeconds10s = 0;
  TimeSeconds1s = 0;
 
  } 
}

 void CalculateAlarm()
{
 //AlarmSeconds1s++;
  if(AlarmSeconds1s == 10)
  {
  AlarmSeconds1s = 0;
  AlarmSeconds10s++;
  }
  if(AlarmSeconds10s == 6)
  {
  AlarmSeconds10s = 0;
  AlarmSeconds1s = 0;
  AlarmMinutes1s++;
  }
  if(AlarmMinutes1s == 10)
  {
  AlarmMinutes1s = 0;
  AlarmSeconds10s = 0;
  AlarmSeconds1s = 0;
  AlarmMinutes10s++;
  }
  if(AlarmMinutes10s == 6)
  {
  AlarmMinutes10s = 0;
  AlarmMinutes1s = 0;
  AlarmSeconds10s = 0;
  AlarmSeconds1s = 0;
  AlarmHours1s++;
  }
  if(AlarmHours1s == 10) 
  {
  AlarmHours1s=0;
  AlarmMinutes10s = 0;
  AlarmMinutes1s = 0;
  AlarmSeconds10s = 0;
  AlarmSeconds1s = 0;
  AlarmHours10s++;
  }
  if(AlarmHours10s == 2 && AlarmHours1s == 4) 
  {
  AlarmHours10s=0; 
  AlarmHours1s=0;
  AlarmMinutes10s = 0;
  AlarmMinutes1s = 0;
  AlarmSeconds10s = 0;
  AlarmSeconds1s = 0;
  } 
}
 void CompareAlarmTime()
 {
  if(TimeHours10s >= AlarmHours10s && TimeHours1s >= AlarmHours1s && TimeMinutes10s >= AlarmMinutes10s && TimeMinutes1s >= AlarmMinutes1s )
  {
   digitalWrite(Buzzer, LOW); 
   
  }
  else
  {digitalWrite(Buzzer, HIGH); 
    }
  
 }
