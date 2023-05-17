﻿/*
Данную программу выполнил Стеклянников Пётр Сергеевич из 151 группы. © Все права защищены.
*/

/*
Создать очередь из целых чисел.
Выполнить циклический сдвиг очереди так, чтобы на первом месте был первый четный элемент.
Например, было  1 3 5 2 5 1 4 5 3 4 5 2 1 
		  Стало 2 5 1 4 5 3 4 5 2 1 1 3 5
*/


#include<iostream>							//подключение библиотеки ввода-вывода
using namespace std;


struct queue {								//очередь описывается как struct следующим образом
	int inf;
	queue * next;
};


void push(queue*& h, queue * &t, int x) {	//вставка элемента в очередь
	queue* r = new queue;					//создаем новый элемент
	r -> inf = x;							//информационное поле inf = x
	r -> next = NULL;						//всегда последний(?)

	if (!h && !t) {							//если очередь пуста
		h = t = r;							//это и голова, и хвост
	}

	else {
		t -> next = r;						//r - следующий для хвоста
		t = r;								//теперь r - хвост
	}
}


int pop(queue*& h, queue *&t) {				//удаление элемента из очереди
	queue * r = h;							//создаем указатель на голову
	int i = h -> inf;						//сохраняем значение головы
	h = h -> next;							//сдвигаем указатель на следующий элемент

	if (!h)									
		t = NULL;

	delete r;								//удаляем первый элемент
	return i;
}


queue * result(queue * &h, queue * &t, int &n) {	//Функция, которая выполняет циклический сдвиг

	int count = 0;

	while (h) {										//Пока h не пуст

		if ( (h->inf) % 2 == 0) {					//Если нашли первый четный
			cout << "Первый чётный найден и равен " << h->inf << endl;
			break;
		}

		if (count == n) {							 //Если прошли уже круг, а его в очереди не оказалось	
			cout << "Четных чисел в очереди нет" << endl;
			break;
		}

		else {										//Иначе выполняется циклический сдвиг
			int x = pop(h, t);						//Удаляем первый элемент и запоминаем его значение
			cout << "x = " << x << endl;			//Вывод только ради наглядности
			push(h, t, x);
			count++;								//счётчик для проверки, прошли ли мы круг
		}
	}

	return h;										//Возвращаем исходную очередь
}




int main() {								//Главная функция
	setlocale(LC_ALL, "RUS");				//Русская клавиатура

	int n;									//Количество целых чисел
	cout << "n = ";
	cin >> n;								//Вводим количество целых чисел
	cout << endl;

	if (n > 0) {
		queue* head = NULL;						//Инициализация головы 
		queue* tail = NULL;						//Инициализация хвоста
		int x;
		cout << "Введите целые числа:" << endl;
		for (int i = 0; i < n; i++) {			//Процесс заполнения очереди
			cin >> x;							//Вводим число
			push(head, tail, x);				//Заполняем очередь
		}
		cout << endl;

		head = result(head, tail, n);			//Результат


		cout << endl << "Ответ:" << endl;
		while (head)							//Пока rest не станет пустым
			cout << pop(head, tail) << " ";		//Выводим на экран элементы очереди rest функцией pop(...)
	}

	else {
		cout << "Очередь является пустой" << endl;
	}

	cout << endl;
	system("Pause");						//Пауза
	return 0;								//Конец программы
}
