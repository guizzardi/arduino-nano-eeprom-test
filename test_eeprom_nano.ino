#include <EEPROM.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);  
 
int valore = 0;  
int lettura = 0; 
 
void setup()
{
 
  lcd.begin(20, 4);  
  lcd.print("TEST EEPROM INTERNA");
  delay(2000);

  for (int ind = 0; ind < EEPROM.length(); ind++)
  {
    lcd.setCursor(0, 1);  
    lcd.print("Indirizzo : "); 
    lcd.print(ind);

    valore = random(1, 255);
    EEPROM.write(ind, valore);  
    
    lcd.setCursor(0, 2);  
    lcd.print("Scrittura : "); 
    lcd.print(valore);
    
    delay(100);
    
    lettura = EEPROM.read(ind); 
    
    lcd.setCursor(0, 3);  
    lcd.print("Lettura   : ");                       
    lcd.print(lettura);
  }
}
 
void loop()
{

}
