
#include <Wire.h>// biblioteca para display
#include <LiquidCrystal_I2C.h>// biblioteca para display

LiquidCrystal_I2C lcd(0x27,16,2);// Inicializa o display no endereco 0x27

int startStopPin = 2;
int resetPin = 3;
int sensorStartStop = 0;

long timeFromLoop;
long deltaTime;

bool started = false;
bool paused = false;

bool lastStartStopValue = false;

void setup() {

  pinMode(startStopPin, INPUT);
  pinMode(resetPin, INPUT);

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(1, 0);
  lcd.print("RobotChallenge");
  lcd.setCursor(3, 1);
  lcd.print("John Deere");
  delay(500);
  lcd.clear();

  cronoReset();
}

void cronograph(){
  int min, sec, cent;

  deltaTime = millis() - timeFromLoop;
  min = deltaTime/60000;
  sec = (deltaTime/1000)%60;
  cent = (deltaTime/10)%100;

  lcd.setCursor(4,1);
  
  if (min<10) lcd.print("0");
  lcd.print(min);
  lcd.print(":");

  if (sec<10) lcd.print("0");
  lcd.print(sec);
  lcd.print(":");

  lcd.print(cent);
  delay(10);
}

void cronoReset(){
  started = false;
  paused = false;
  deltaTime = 0;
  
  lcd.setCursor(3, 0);
  lcd.print("Cronometro");
  lcd.setCursor(4, 1);
  lcd.print("00:00:00");
}

void loop() {

  if (digitalRead(startStopPin) == LOW && !started) {
    started = true;
    timeFromLoop = millis();
    Serial.println("Start sensor activated."); 
  } 

  if (digitalRead(startStopPin) == LOW && started && deltaTime > 1000) {
    paused = true;
    Serial.println("Stop sensor activated. Paused time."); 
  }
 
  if (started && !paused){
    cronograph();
    Serial.println("Cronograph counting..."); 
  }

  if (digitalRead(resetPin) == HIGH && started) {
    cronoReset();
    Serial.println("Reseted."); 
  }

  lastStartStopValue = digitalRead(startStopPin);
}
