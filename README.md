##Перепишите структуру по образцу 20 таска и измените расширение у файлов на *.c
##Открыты ваши новые индивидуальные таски

## Проект: База данных
Лидер группы: Дёмочкин Кирилл  
Разработчики: Бажмин Сергей, Обрезков Вячеслав, Чердакова Алина, Матутин Василий  

##Задачи:  
-Начинаем работать с папками, файлы не трогаем пока(!)  
~~-Создаём 2 структуры папка-файл~~
 
~~-Собираем первый билд~~
 
 ~~-Реализуем функции для работы с деревом(пишем отдельные функции, потом будем их все подключать к main)~~ 
 
  ~~-Добавление/удаление элемента вместе со всем поддеревом(в т.ч. создание новой базы и удаление её целиком)~~  
  
  -~~Поиск по базе данных~~  
  
  ~~1.Пользователь вводит путь, мы по нему переходим~~
   
   ~~2.Пользователь вводит имя папки, мы находим ему первую встретившуюся(поиск справа\слева решайте сами), в т.ч. предусмотреть~~  
   ~~возможность поиска дальше, т.е. продолжить искать дальше, если эта папка не устроила пользователя(пока не пройдём всё)~~  
   
 -~~Собираем и тестим~~
 Пишем документацию с описаниями всех функций и интерфейса
	
	Тестируем и дорабатываем все индивидуальные функции  
	
	Начинаем собирать всё в один файл
	
	Обсуждаем способы хранения базы данных, а так же возможного сжатия данных
	
	Начинаем реализацию "файлов" в системе

 Продолжаем добавлять комментарии к своему коду
 
 Думаем над реализацией прерывания ввода
 
 
 
###Иерархическая база данных  
####Основной фунционал:  
Создание новой базы данных  
Удаление базы данных  
Создание нового объекта в базе данных  
Удаление объекта из базы данных  
Поиск по базе данных  

##Вопросы:  
 ~~По какому принципу происходит сортировка?~~  
 ~~какая структура дерева?~~  
 ~~что конкретно подразумевается под "иерархией"?~~  
 ~~как хранить указатели на "потомков"? массивом?~~(список)  
 ~~какие типы данных храним?~~(long, float, bool, char, строка и бинарный)   
 ~~максимальное число потомков?~~(бесконечно)  
 ~~как нам быть с синхронизацией, чтобы не было конфликтов?~~

