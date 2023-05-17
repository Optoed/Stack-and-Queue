﻿/* 
* В файле содержится двумерный массив размерностью n × n.
* В новый файл вывести отсортированный массив.
* 
* 1. Столбцы по возрастанию с помощью быстрой сортировки.
*/

#include <iostream> //подключение библиотек
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


ifstream fin("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\sort_massiv\\input_sort_massiv.txt"); //открываем файл с данными
ofstream fout("C:\\Users\\User\\Desktop\\ВУЗ ДОМАШКА\\Программирование и Информатика\\С++ Homework\\task_SORT\\sort_massiv\\output_sort_massiv_1.txt"); //записываем ответ в новый файл


bool Check() {    //Проверяем, открылся ли файл

	if (!fin.is_open()) {
		return 0;
	}

	else {
		return 1;
	}
}

vector <vector<int> > Fill() { //Считывание с исходного файла данных в vector <vecotr <int> > a

	vector <vector<int> > a;

	bool move = 0;
	int number;

	string line, subline;
	string::size_type k, pos;

	while (getline(fin, line)) {     //считываем строки исходного файла
		 
		if (move == 1) {        //Первую строчку мы пропускаем и не считываем, так как там записан размер массива
			vector <int> a1;
			pos = 0;
			k = line.find(' ', pos);
			while (k != string::npos) {         //проходимся по строке и записываем в вектор
				subline = line.substr(pos, k - pos);
				number = stoi(subline);
				a1.push_back(number);
				pos = k + 1;
				k = line.find(' ', pos);
			}
			
			if (k > line.size()) {
				k = line.size();
				subline = line.substr(pos, k - pos);
				number = stoi(subline);
				a1.push_back(number);
			}

			a.push_back(a1);
		}
		
		else {
			move = 1;
		}
	}

	return a;    //возвращаем вектор чисел
}

void Sort(vector<vector<int> >& a, int l, int r) {      //Сортировка (как в условии)

	for (int stolbec = 0; stolbec < a.size(); stolbec++) {
		int left = l;
		int right = r;
		int opor = a[(left + right) / 2][stolbec];

		while (left <= right) {
			while (a[left][stolbec] < opor) {
				left++;
			}
			while (a[right][stolbec] > opor) {
				right--;
			}
			if (left <= right) {
				
				swap(a[left][stolbec], a[right][stolbec]);
				right--;
				left++;
			}
		}

		if (right - l > 0) {
			Sort(a, l, right);
		}
		if (r - left > 0) {
			Sort(a, left, r);
		}
	}
}

void Print(vector<vector<int>> &a) {    //вывод содержимого вектора
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void Output(vector <vector <int> >& a) {    //вывод в файл содержимое отсортированного массива

	fout << a.size() << endl;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (j < a.size() - 1)
				fout << a[i][j] << ' ';
			else
				fout << a[i][j];
		}
		fout << endl;
	}
	cout << "Содержимое отсортированого n*n двумерного массива было записано в output_sort_massiv.txt" << endl;
}

int main() {

	setlocale(LC_ALL, "RUS"); //русская раскладка

	bool check = Check(); //проверяем открылся ли файл

	if (check)
		cout << "Файл открылся!" << endl;
	else
		cout << "Файл не открылся!" << endl;
	cout << endl;

	vector<vector<int> > a, a_sort;

	a = Fill();   //Считываем с исходного файла данные в vector <vecotr <int> > a

	cout << "Вывод исходного n*n двумерного массива:" << endl;
	cout << a.size() << endl;
	Print(a); //Вывод исходного n*n двумерного массива:
	
	cout << endl;

	a_sort = a;
	int l = 0;
	int r = a_sort.size() - 1;

	Sort(a_sort, l, r); //сортируем массив

	cout << "1. Столбцы по возрастанию с помощью быстрой сортировки." << endl;
	cout << "Вывод n*n двумерного массива после быстрой сортировки:" << endl;
	cout << a.size() << endl;
	Print(a_sort); //выводим отсортированный массив
	cout << endl;

	Output(a_sort); //выводим отсортированный массив в файл

	return 0; //конец программы
}