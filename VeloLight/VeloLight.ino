//VeloLight v. 1.0
//by G&M with far-galaxy

/* !!! Для увеличения частоты ШИМ замените строчку в файле
 *  %appdata%\..\Local\Arduino15\packages\digistump\hardware\avr\1.6.7\cores\tiny\wiring.c
 *  (прямо так вставляйте ссылку в Проводник)
 *  MS_TIMER_TICK_EVERY_X_CYCLES 64 на MS_TIMER_TICK_EVERY_X_CYCLES 1
 */

#define MAX_V 3500     // Максимальное напряжение
#define LOW_BAT 3000   // Низкое напряжение

// Пины (лучше не менять, иначе прошивка может не загрузиться при подключённой обвязке
#define POT_PIN 1      // Пин резистора (A1)
#define LIGHT_PIN 0    // Пин светодиодов (P0)


void setup() {
  pinMode(LIGHT_PIN,OUTPUT);  
}

void loop() {

  // Считываем значение с резистора
  byte power = map(analogRead(POT_PIN),0, 1023, 0, 255);  

  // Считываем напряжение аккумулятора
  long battery = readVcc();

  // Сложные алгоритмы рассчёта
  int voltage = battery / 255 * power;
  int light = map(voltage, 0, battery, 0, MAX_V);
  light = map(light, 0, battery, 0, 255);
  
  // Проверка напряжения на аккумуляторе
  if (battery > LOW_BAT) analogWrite(LIGHT_PIN, light);

  // Мигать, если напряжение низкое
  else {
    analogWrite(LIGHT_PIN, 50);
    delay(500);
    analogWrite(LIGHT_PIN, 0);
    delay(500);
  }

}


float my_vcc_const = 1.1;

long readVcc() {
#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
ADMUX = _BV(MUX5) | _BV(MUX0);
#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
ADMUX = _BV(MUX3) | _BV(MUX2);
#else
ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif
delay(2); // Wait for Vref to settle
ADCSRA |= _BV(ADSC); // Start conversion
while (bit_is_set(ADCSRA, ADSC)); // measuring
uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH
uint8_t high = ADCH; // unlocks both
long result = (high << 8) | low;
result = my_vcc_const * 1023 * 1000 / result; 
return result; 
}
