/*
Sensor de Umidade do Solo
*/

// include the library code:
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define pino_sinal_analogico A0
int valor_analogico;

void setup() {
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Umidade:");
}
void loop() {
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);
  lcd.clear();
  // Print a message to the LCD.
  lcd.print("Umidade: ");
  lcd.print(valor_analogico);
 
  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400)
  {
    Serial.println(" Status: Solo umido");
      lcd.clear();
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("Umidade: ");
      lcd.print(valor_analogico);
      lcd.setCursor(0,1);
      lcd.print("Solo Umido");
      
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800)
  {
    Serial.println(" Status: Umidade moderada");
      lcd.clear();
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("Umidade: ");
      lcd.print(valor_analogico);
      lcd.setCursor(0,1);
      lcd.print("Umidade Moderada");
  }
 
  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024)
  {
    Serial.println(" Status: Solo Seco");
    lcd.clear();
    // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("Umidade: ");
      lcd.print(valor_analogico);
      lcd.setCursor(0,1);
      lcd.print("Solo Seco");
  }
  delay(100);

  
  // Turn off the blinking cursor:
  lcd.noBlink();
  delay(1000);
  // Turn on the blinking cursor:
  lcd.blink();
  delay(1000);
}
