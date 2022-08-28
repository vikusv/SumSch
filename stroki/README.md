## Общая информация
Написание, документация и проверка работы некоторых строковых функций 


Для запуска в командную строку необходимо ввести `$ make run`
#### Список представленных функций
```
Функция                 Оригинал
Puts()                  puts()
Strlen() и StrlenAlt()  strlen()
Strcpy()                strcpy()
Strncpy()               strncpy()
Strcat() и StrcatAlt()  strcat()
Strncat()               strncat()
Strchr()                strchr()
Strcmp()                strcmp()
```
#### Пример работы
```
$ make run
Puts:      This is a sample string.
puts:      This is a sample string.
Strlen:    24.
strlen:    24.
StrlenAlt: 24.
strlen:    24.
Strcpy     "This is a sample string."
strcpy     "This is a sample string."
Strncpy    "This is a"
strncpy    "This is a"
Strcat     "This is a sample string."
strcat     "This is a sample string."
StrcatAlt  "This is a sample string."
strcat     "This is a sample string."
strncat    "The end."
strncat    "The end."
Strchr:    3.
strchr:    3.
Strcmp:    0, -13.
strcmp:    0, -1.
```
