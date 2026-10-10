#include <LiquidCrystal.h>
#include <Servo.h>

// 1. إعداد الشاشة (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 6, 7, 8);

// 2. إعداد محرك الباب
Servo myDoor;

// 3. تعريف المنافذ
const int pirPin = 2;       // حساس الحركة
const int buzzerPin = 3;    // السماعة
const int relayFan = 4;     // المروحة
const int relayLamp = 13;   // المصباح
const int gasPin = A0;      // حساس الغاز (MQ-2)

// متغيرات التحكم
String msg = "   Subhan Allah wa bihamdihi   "; 
unsigned long messageTimer = 0; 
const long displayDuration = 30000; // مدة ظهور الرسائل (30 ثانية)
int gasThreshold = 450;             // حساسية الغاز (عدلها لو الإنذار حساس بزيادة)

void setup() {
  lcd.begin(16, 2);
  myDoor.attach(9);
  myDoor.write(0); // الباب مغلق
  
  pinMode(pirPin, INPUT);
  pinMode(relayLamp, OUTPUT);
  pinMode(relayFan, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  
  lcd.print("System Online");
  delay(2000);
  lcd.clear();
}

void loop() {
  // --- أولاً: فحص خطر الغاز (الأولوية القصوى) ---
  int gasValue = analogRead(gasPin); 
  
  if (gasValue > gasThreshold) {
    digitalWrite(relayFan, HIGH);    // شغل المروحة فوراً
    tone(buzzerPin, 1500);           // صوت إنذار حاد
    lcd.setCursor(0, 0);
    lcd.print("!!! GAS ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("Fan: ON  Danger ");
    return; // اخرج من اللوب ولا تنفذ باقي الكود لضمان استمرار الإنذار
  } else {
    noTone(buzzerPin); // اطفئ الإنذار لو الغاز اختفى
  }

  // --- ثانياً: نص التسبيح المتحرك (السطر الثاني دائماً) ---
  static int textPos = 0;
  lcd.setCursor(0, 1);
  String displayMsg = msg.substring(textPos) + msg.substring(0, textPos);
  lcd.print(displayMsg.substring(0, 16)); 
  textPos++;
  if (textPos >= msg.length()) textPos = 0;

  // --- ثالثاً: فحص الحركة (الإضاءة التلقائية) ---
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(relayLamp, HIGH);
    lcd.setCursor(0, 0);
    lcd.print(">> Motion! <<   "); 
    messageTimer = millis(); // ابدأ عد الـ 30 ثانية
  } else {
    digitalWrite(relayLamp, LOW);
  }

  // --- رابعاً: أوامر التحكم من الـ Serial Monitor ---
  if (Serial.available() > 0) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim(); cmd.toLowerCase();

    lcd.setCursor(0, 0);
    if (cmd == "open") {
      myDoor.write(90);
      lcd.print(">> Door: OPEN <<");
      tone(buzzerPin, 1000, 200);
    } 
    else if (cmd == "close") {
      myDoor.write(0);
      lcd.print(">> Door: CLOSE<<");
      tone(buzzerPin, 800, 200);
    }
    else if (cmd == "fan on") {
      digitalWrite(relayFan, HIGH);
      lcd.print(">> Fan: ON   <<");
    }
    else if (cmd == "fan off") {
      digitalWrite(relayFan, LOW);
      lcd.print(">> Fan: OFF  <<");
    }
    messageTimer = millis(); // صفر العداد ليبدأ 30 ثانية من جديد
  }

  // --- خامساً: إخفاء رسائل السطر الأول بعد 30 ثانية ---
  if (millis() - messageTimer > displayDuration) { 
    lcd.setCursor(0, 0);
    lcd.print("                "); 
  }

  delay(250); // سرعة تحديث الشاشة والحركة
}