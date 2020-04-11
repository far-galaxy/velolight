# VeloLight - фонарь для велосипеда на основе Digispark
- Умная регулировка яркости
- Индикация о низком заряде

## [Видео](https://youtu.be/kZVxb4szTHk)

## Электроника:
- [Digispark](https://aliexpress.ru/item/32807895683.html)
- [Светодиоды](https://aliexpress.ru/item/32833830434.html)
- Транзистор КТ815 или [MOSFET](https://aliexpress.ru/item/32716858730.html) или [MOSFET-ключ](https://aliexpress.ru/item/4000550112144.html)

## Схемы:
### С транзистором
![С транзистором](/Images/Scheme.png)
### С MOSFET
![С MOSFET](/Images/Scheme_MOSFET.png)
### С MOSFET-ключом
![С MOSFET-ключом](/Images/Scheme_Key.png)

## Прошивка:
- [Скачать репозиторий на компьютер](https://github.com/far-galaxy/velolight/archive/master.zip), распаковать архив в корень диска (или любой другой каталог, где нет русских букв)
- Установить [Arduino IDE](https://alexgyver.ru/arduino-first/#step-1) и ядро для Digispark по [инструкции](https://alexgyver.ru/arduino-first/#step-3-1), если вдруг не умеете
- Открыть файл **VeloLight.ino** и загрузить прошивку по инструкции выше

