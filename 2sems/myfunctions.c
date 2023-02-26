
//MYFUNCTIONS_C

#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

void hello_world()
{
	cout << "Hello World!\n";
}

// Çàïîëíåíèå ìàññèâà ñëó÷àéíûìè çíà÷åíèÿìè
void random(int mas[], int n) {

	for (int i = 0; i < n; i++)
		mas[i] = rand();
}

// Âûâîä íà ýêðàí ìàññèâà
void print_mas(int mas[], int n) {

	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
}

// Ññóììèðîâàíèå ìàññèâà ñ èñïîëüçîâàíèåì ïðåäèêàòíûõ ôóíêöèé
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
// Ôóíêöèÿ çàäàþùàÿ äèàïïàçîí äëÿ âûâîäà èíäåêñîâ
bool diapazon(int i, int a, int b)
{
	return i >= a && i < b;
}

// Óäàëåíèå ýëåìåíòà èç ìàññèâà, ñî ñäâèãîì
void delete_elem(int mas[], int n, int index) {
	cout << endl;
	
	for (int i = index; i < n; i++)
		mas[i] = mas[i + 1];
	mas[n - 1] = 0;
}


//  Äîáàâëåíèå ýëåìåíòà ê ìàññèâó, ñî ñäâèãîì
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

// Ñîðòèðîâêà ìàññèâà 1 ïî âîçðàñòàíèþ

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

// Ñîðòèðîâêà ìàññèâà 2 Ñîðòèðîâêà âûáîðîì, ïî óáûâàíèþ

void selection_sort(int mas[], int n) {
	
	cout << endl << "Selection sort:" ;

	int value, index;

	for (int i = 0; i < n - 1; i++){

		value = mas[i];
		index = i;

		for (int j = i + 1; j < n; j++) {
			if (mas[j] > mas[index]) {
				index = j;
			}
		}

		if (index != i){
			mas[i] = mas[index];
			mas[index] = value;
		}
	}
}

// Ñîðòèðîâêà ìàññèâà 3 Ñîðòèðîâêà âñòàâêàìè

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

// Ëèíåéíûé ïîèñê ìèíèìàëüíîãî çíà÷åíèÿ
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

// Ëèíåéíûé ïîèñê ìàêñèìàëüíîãî çíà÷åíèÿ
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

// Àëãîðèòì áèíàðíîãî ïîèñêà. 
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
		if (elem == i*i) {
			return true;
		}
	}
	return false;
}

// Ñîõðàíåíèå ìàññèâà â ôàéë
void save_to_file(int mas[], int n) {
	ofstream fout("C:\\data\\file.txt");
	for (int i = 0; i < n; i++)
	{
		fout << mas[i] << " ";
		cout << "Zapisan elem #" << i << ": " << mas[i] << endl;
	}
	fout.close();
}

// ×òåíèå ìàññèâà èç ôàéëà
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

// Ïîèñê ìèíèìàëüíîãî ýëåìåíòà ïî ìîäóëþ â ìàññèâå
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

// Ñóììà ýëåìåíòîâ ñëåâà îò îòðèöàòåëüíîãî 
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



