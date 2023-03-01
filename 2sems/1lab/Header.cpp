
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void HelloWorld()
{
	std::cout << "Hello World!\n";
}

// Заполнение массива случайными значениями
void random(int mas[], int n) {

	for (int i = 0; i < n; i++)
		mas[i] = rand();
}



// Вывод на экран массива
void print_mas(int mas[], int n) {
	cout << endl;

	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
}


void random(int mas[], float n) {

	int f = n;

	for (int i = 0; i < f; i++)
		mas[i] = rand();
}
// Вывод на экран массива с перегрузкой функций
void print_mas(int mas[], float n) {
	cout << endl;
	int f = n;

	for (int i = 0; i < f; i++)
		cout << mas[i] << " ";
}

// Ссуммирование массива с использованием предикатных функций
int sum_mas(int mas[], int n, int a, int b, bool (*pred) (int i, int a, int b)) {
	int sum = 0;
	cout << endl;
	for (int i = 0; i < n; i++)
		if (pred(i, a, b)) {
			sum += mas[i];
			cout << mas[i] << endl;
		}
	return sum;
}
// Функция задающая диаппазон для вывода индексов
bool diapazon(int i, int a, int b)
{
	return i >= a && i < b;
}

// Удаление элемента из массива, со сдвигом
void delete_elem(int mas[], int n, int index) {
	cout << endl;

	for (int i = index; i < n; i++)
		mas[i] = mas[i + 1];
	mas[n - 1] = 0;
}


//  Добавление элемента к массиву, со сдвигом
void add_elem(int mas[], int n, int index, int elem) {

	cout << endl;
	int temp_mas[100];

	for (int i = 0; i < n - 1; i++) {
		temp_mas[i] = mas[i];
	}
	for (int i = index; i < n - 1; i++) {
		mas[i + 1] = temp_mas[i];
	}
	mas[index] = elem;

}

// Сортировка массива 1 по возрастанию

void bubble_sort(int mas[], int n) {
	cout << endl << "Bubble sort:";
	while (n--) {
		for (int i = 0; i < n; i++) {
			if (mas[i] > mas[i + 1]) {
				int temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
			}
		}

	}
}

// Сортировка массива 2 Сортировка выбором, по убыванию

void selection_sort(int mas[], int n) {

	cout << endl << "Selection sort:";

	int value, index;

	for (int i = 0; i < n - 1; i++) {

		value = mas[i];
		index = i;

		for (int j = i + 1; j < n; j++) {
			if (mas[j] > mas[index]) {
				index = j;
			}
		}

		if (index != i) {
			mas[i] = mas[index];
			mas[index] = value;
		}
	}
}

// Сортировка массива 3 Сортировка вставками

void insertion_sort(int mas[], int n)
{
	cout << endl << "Insertion sort:";

	int index, j;

	for (int i = 1; i < n; i++)
	{
		index = mas[i];
		j = i - 1;

		while (j >= 0 && mas[j] > index)
		{
			mas[j + 1] = mas[j];
			j = j - 1;
		}
		mas[j + 1] = index;
	}
}

// Линейный поиск минимального значения
int linerial_search_min(int mas[], int n) {
	int index = 0, min_value = mas[0];

	for (int i = 0; i < n; i++) {
		if (mas[i] < min_value) {
			index = i;
			min_value = mas[i];
		}
	}

	return index;
}

// Линейный поиск максимального значения
int linerial_search_max(int mas[], int n) {
	int index = 0, min_value = mas[0];

	for (int i = 0; i < n; i++) {
		if (mas[i] > min_value) {
			index = i;
			min_value = mas[i];
		}
	}

	return index;
}

// Алгоритм бинарного поиска. 
int binary_search(int mas[], int n, int elem) {
	int mid = n / 2;
	while (elem != mas[mid]) {
		if (mas[mid] > elem) {
			mid = mid / 2;
		}
		else {
			mid += (mid / 2);
		}
	}
	return mid;
}

int podschet_elementov(int mas[], int n, bool (*pred)(int elem)) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (pred(mas[i])) {
			count++;
		}
	}
	return count;
}

bool polozitelnie(int elem)
{
	return elem > 0;
}

bool otricatelnie(int elem)
{
	return elem < 0;
}

bool nulevie(int elem)
{
	return elem == 0;
}

bool kvadratnie(int elem)
{
	for (int i = 1; i < 100; i++) {
		if (elem == i * i) {
			return true;
		}
	}
	return false;
}

// Сохранение массива в файл
void save_to_file(int mas[], int n) {
	ofstream fout("C:\\data\\file.txt");
	for (int i = 0; i < n; i++)
	{
		fout << mas[i] << " ";
		cout << "Zapisan elem #" << i << ": " << mas[i] << endl;
	}
	fout.close();
}

// Чтение массива из файла
void read_to_file(int mas[], int n) {
	string line;
	ifstream fin("C:\\data\\file.txt");
	if (fin.is_open())
	{
		while (getline(fin, line))
		{
			std::cout << line << std::endl;
		}
	}
	fin.close();
}

// Поиск минимального элемента по модулю в массиве
int v_11_find_min_elem(int mas[], int n) {
	int min_index = 0;
	int min_value = abs(mas[0]);
	for (int i = 1; i < n; i++) {
		if (abs(mas[i]) < min_value) {
			min_value = abs(mas[i]);
			min_index = i;
		}
	}
	return min_index;
}

// Сумма элементов слева от отрицательного 
int v_11_sum_elems_left_otricat(int mas[], int n) {
	int sum_values = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			break;
		}
		else {
			sum_values += mas[i];
		}
	}
	return sum_values;
}


void zip_massive(int mas[], int n, int min, int max) {
	int ans[10];
	int count = 0;
	for (int i = min; i < max; i++) {
		ans[count] = mas[i];
		count++;
	}
	for (int i = 0; i < (max - min); i++)
		cout << "Final massive:" << ans[i] << " ";
	
}


