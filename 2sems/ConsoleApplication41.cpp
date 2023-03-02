
#include <iostream>
#include <vector>

using namespace std;


// обход элементов массива заполнение массива данными псевдослучайными числами - ввод
void random_mas(int** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(array + i) + j) = rand() % 99 - 25;
        }
    }
}

// вывод массива на экран
void print_massive(int** array, int n, int m) {
    for (int i = 0; i < n; i++) {
        std::cout << endl;
        for (int j = 0; j < m; j++) {
            std::cout << '[';
            if ((*(*(array + i) + j)) < 10 && (*(*(array + i) + j)) >= 0) {
                std::cout << ' ';
            }
            if ((*(*(array + i) + j)) < 100 && (*(*(array + i) + j)) >= -9) {
                std::cout << ' ';
            }
            std::cout << *(*(array + i) + j) << ']' << ' ';
        }
    }
    std::cout << endl;
}

// вычисление суммы, произведения элементов массива по заданной строке
void sum_row(int** array, int n, int m, int index) {
    int sum_value = 0;
    int i = index;
    for (int j = 0; j < m; j++) {
        sum_value += *(*(array + i) + j);
    }
    
    std::cout << endl << "Сумма значений строки "  << index <<": " << sum_value;
}

// вычисление суммы, произведения элементов массива по заданному столбцу
void sum_column(int** array, int n, int m, int index) {
    int sum_value = 0;
    int j = index;
    for (int i = 0; i < m; i++) {
        sum_value += *(*(array + i) + j);
    }

    std::cout << endl << "Сумма значений столбца " << index << ": " << sum_value;
}

// вычисление суммы, произведения элементов массива по главной диагонали
void main_diagonal(int** array, int n, int m) {
    int sum_value = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                sum_value += *(*(array + i) + j);
            }
        }
    }
    std::cout << endl << "Сумма значений главной диагонали: " << sum_value;
}

// вычисление суммы, произведения элементов массива по побочной диагонали
void no_main_diagonal(int** array, int n, int m) {
    int sum_value = 0, j=n - 1;
    sum_value += *(*(array + 0) + 9);

    for (int i = 0; i < n; i++) {
        sum_value += *(*(array + i) + j);
        j = (n - i - 1 - 1 );
    }
    std::cout << endl << "Сумма значений побочной диагонали: " << sum_value;
}

// Максимальный элемент в массиве
void MaxIndex(int** array, int n, int m) {
    struct Index {
        int i;
        int j;
    };
    Index maxI = { 0,0 };

    std::cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((*(*(array + i) + j)) > (*(*(array + maxI.i) + maxI.j))) {
                maxI.i = i;
                maxI.j = j;
            }
        }
    }
    std::cout << "Максимальное значение в массиве:" << (*(*(array + maxI.i) + maxI.j));
}

// поиск индексов максимального элемента в массиве в строке 
void Max_index_in_row(int** array, int n, int m, int index) {
    struct Index {
        int i;
        int j;
    };
    Index maxI = { index,0 };
    for (int j = 0; j < m; j++) {
        if ((*(*(array + maxI.i) + j)) > (*(*(array + maxI.i) + maxI.j))) {
            maxI.j = j;
        }
    }
    std::cout << endl << "Индекс максимального значения в строке " << maxI.i << " j=" << maxI.j;
}

// поиск индексов минимального элемента в массиве в строке 
void Min_index_in_row(int** array, int n, int m, int index) {
    struct Index {
        int i;
        int j;
    };
    Index minI = { index,0 };
    for (int j = 0; j < m; j++) {
        if ((*(*(array + minI.i) + j)) < (*(*(array + minI.i) + minI.j))) {
            minI.j = j;
        }
    }

    std::cout << endl << "Индекс минимального значения в строке " << minI.i << " j=" << minI.j;
}

// поиск индексов максимального элемента в массиве в столбце
void Max_index_in_column(int** array, int n, int m, int index) {
    struct Index {
        int i;
        int j;
    };
    Index maxI = { 0,index };
    for (int i = 0; i < m; i++) {
        if ((*(*(array + i) + index)) > (*(*(array + maxI.i) + index))) {
            maxI.i = i;
        }
    }
    std::cout << endl << "Индекс максимального значения в столбце "   << index << " i=" << maxI.i;
}

// поиск индексов минимального элемента в массиве в столбце
void Min_index_in_column(int** array, int n, int m, int index) {
    struct Index {
        int i;
        int j;
    };
    Index minI = { 0, index};
    for (int i = 0; i < m; i++) {
        if ((*(*(array + i) + index)) < (*(*(array + minI.i) + index))) {
            minI.i = i;
        }
    }
    std::cout << endl << "Индекс минимального значения в столбце " << index << " i=" << minI.i;
}

// поиск индексов минимального элемента в главной диагонали
void min_index_main_diagonal(int** array, int n, int m) {
    struct Index {
        int i;
        int j;
    };
    Index minI = { 0, 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                if (((*(*(array + i) + j))) < ((*(*(array + minI.i) + minI.j)))) {
                    minI.i = i;
                    minI.j = j;
                };
            }
        }
    }
    std::cout << endl << "Индекс минимального значения главной диагонали: " << minI.i << " и " << minI.j << " Значение=" << ((*(*(array + minI.i) + minI.j)));
}

// поиск индексов максимального элемента в побочной диагонали
void max_index_no_main_diagonal(int** array, int n, int m) {
    struct Index {
        int i;
        int j;
    };
    Index maxI = { 0, 0 };

    int j = n - 1;

    for (int i = 0; i < n; i++) {
        
        if (((*(*(array + i) + j))) > ((*(*(array + maxI.i) + maxI.j)))) {
            maxI.i = i;
            maxI.j = j;
        };
        j = (n - i - 1 - 1);
    }
    std::cout << endl << "Индекс Максимального значения побочной диагонали: " << maxI.i << " и " << maxI.j << " Значение=" << ((*(*(array + maxI.i) + maxI.j)));
}

// преобразование матрицы в одномерный массив
void in_one(int** array, int n, int m) {
    std::cout << endl << "Новый массив = ";
    int count = 0;
    int mas[100];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mas[count] = (*(*(array + i) + j));
            count++;
        }
    }
    for (int k = 0; k < 100; k++) {
        std::cout << "[" << mas[k] << "] ";
    }
}

// Преобразование матрицы в двумерный массив из одномерного;
void in_doble(int mas[], int n) {
    std::cout << endl;

    for (int k = 0; k < n - 1; k++) {
        if ((k % 3) == 0) {
            std::cout << endl;
        }
        std::cout << "[";
        if (mas[k] > 10 && mas[k] < 10) {
            std::cout << " ";
        }
        if (mas[k] < 10 && mas[k] < 10) {
            std::cout << " ";
        }

        std::cout << mas[k] << "] ";
    }
    std::cout << endl;

}

// поиск и подсчет количества элементов массива, удовлетворяющих заданному условию в строке
void find_and_count_row(int** array, int n, int m, int index, int a, int b) {

    int count = 0;
    for (int i = 0; i < n; i++) {

        if (*(*(array + i) + index) > a && (*(*(array + i) + index) < b)) {
            count++;
        }
    }
    std::cout << endl << "Количество элементов массива удовлетворяющих условию в строке " << index << ": " << count;
}

// поиск и подсчет количества элементов массива, удовлетворяющих заданному условию в столбце
void find_and_count_column(int** array, int n, int m, int index, int a, int b) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(*(array + index) + i) > a && (*(*(array + index) + i) < b)) {
            count++;
        }
    }
std::cout << endl << "Количество элементов массива удовлетворяющих условию в столбце: " << index << ": " << count;
}

// поиск и подсчет количества элементов массива, удовлетворяющих заданному условию главной диагонали
void find_and_count_main_diagonal(int** array, int n, int m, int index, int a, int b){
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) {
                if ((*(*(array + i) + j) > a) && ((*(*(array + i) + j) < b))) {
                    count++;
                };
            }
        }
    }
    std::cout << endl << "количество значения удовлетворяющих заданному условию главной диагонали: " << count;
}

// поиск и подсчет количества элементов массива, удовлетворяющих заданному условию побочной диагонали
void find_and_count_no_main_diagonal(int** array, int n, int m, int index, int a, int b) {
    int j = n - 1, count = 0 ;

    for (int i = 0; i < n; i++) {

        if ((*(*(array + i) + j) > a) && ((*(*(array + i) + j) < b))) {
            count++;
        };
        j = (n - i - 1 - 1);
    }
    std::cout << endl << "количество значения удовлетворяющих заданному условию побочной диагонали: " << count;
}

// вставка  строки
int** insert_row(int** array, int n, int m, int mas[10]){

    int** array_2;
    array_2 = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        *(array_2 + i) = new int[m + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(array_2 + i) + j) = *(*(array + i) + j);
        }
    }
    for (int i = 0; i < n; i++) {
        *(*(array_2 + n ) + i) = mas[i];
    }
    return array_2;
}

// вставка столбца
int** insert_column(int** array, int n, int m, int mas[10]) {

    int** array_2;
    array_2 = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        *(array_2 + i) = new int[m + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *(*(array_2 + i) + j) = *(*(array + i) + j);
        }
    }
    for (int i = 0; i < m; i++) {
        *(*(array_2 + i ) + m ) = mas[i];
    }
    return array_2;
}

// удаление строки
int** delet_column(int** array, int n, int m, int column) {
    int** array_2;
    array_2 = new int* [n];

    int temp_j = 1;

    for (int i = 0; i < n; i++) {
        *(array_2 + i) = new int[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (m - 1) ; j++) {
            if (j > column) {
                *(*(array_2 + i) + j) = *(*(array + i) + (j + temp_j));
            }
            else {
                *(*(array_2 + i) + j) = *(*(array + i) + j);
            }
        }
    }
    return array_2;
}


// Удаление строки
int** delet_row(int** array, int n, int m, int row) {
    int** array_2;
    array_2 = new int* [n];

    int temp_j = 1;

    for (int i = 0; i < n; i++) {
        *(array_2 + i) = new int[m];
    }

    for (int i = 0; i < n - 1 ; i++) {
        for (int j = 0; j < m; j++) {
            if (i > row) {
                *(*(array_2 + i) + j) = *(*(array + (i + 1)) + j);
            }
            else {
                *(*(array_2 + i) + j) = *(*(array + i) + j);
            }
        }
    }
    return array_2;
}


// сортировка элементов заданной строки
void sort_row(int** array, int n, int m, int row) {
    
    int mas[10];
    int count = 0;
    for (int j = 0; j < m; j++) {
        mas[j] = *(*(array + row) + j);
    }

    std::cout << "\nНе отсортированный массив:"<< endl;

    for (int j = 0; j < m; j++) {
        std::cout << " " << mas[j] << " ";
    }

    for (int i = 1; i < n; i++)
    {
        int index, o;
        index = mas[i];
        o = i - 1;

        while (o >= 0 && mas[o] > index)
        {
            mas[o + 1] = mas[o];
            o = o - 1;
        }
        mas[o + 1] = index;
    }
    std::cout << endl <<"Отсортированный массив:" << endl;

    for (int j = 0; j < m; j++) {
        std::cout << " " << mas[j] << " ";
    }

    for (int j = 0; j < m; j++) {
        *(*(array + row) + j) = mas[j];
    }
    print_massive(array, n, m);

}


void sort_row_wp(int** array, int n, int m, int row) {

    int mas[10];
    int count = 0;
    for (int j = 0; j < m; j++) {
        mas[j] = *(*(array + row) + j);
    }

    for (int i = 1; i < n; i++)
    {
        int index, o;
        index = mas[i];
        o = i - 1;

        while (o >= 0 && mas[o] > index)
        {
            mas[o + 1] = mas[o];
            o = o - 1;
        }
        mas[o + 1] = index;
    }

    for (int j = 0; j < m; j++) {
        *(*(array + row) + j) = mas[j];
    }

}

// сортировка элементов заданной столбца
void sort_column(int** array, int n, int m, int column) {
    int mas[10];
    int count = 0;
    for (int j = 0; j < m; j++) {
        mas[j] = *(*(array + j) + column);
    }

    std::cout << "\nНе отсортированный массив (Столбец):" << endl;

    for (int j = 0; j < m; j++) {
        std::cout << " " << mas[j] << " ";
    }

    for (int i = 1; i < n; i++)
    {
        int index, o;
        index = mas[i];
        o = i - 1;

        while (o >= 0 && mas[o] > index)
        {
            mas[o + 1] = mas[o];
            o = o - 1;
        }
        mas[o + 1] = index;
    }
    std::cout << endl << "Отсортированный массив (Столбец):" << endl;

    for (int j = 0; j < m; j++) {
        std::cout << " " << mas[j] << " ";
    }

    for (int j = 0; j < m; j++) {
        *(*(array + j) + column) = mas[j];
    }
    print_massive(array, n, m);

}


void sort_column_wp(int** array, int n, int m, int column) {
    int mas[10];
    int count = 0;
    for (int j = 0; j < m; j++) {
        mas[j] = *(*(array + j) + column);
    }

    for (int i = 1; i < n; i++)
    {
        int index, o;
        index = mas[i];
        o = i - 1;

        while (o >= 0 && mas[o] > index)
        {
            mas[o + 1] = mas[o];
            o = o - 1;
        }
        mas[o + 1] = index;
    }


    for (int j = 0; j < m; j++) {
        *(*(array + j) + column) = mas[j];
    }
 
}

// сортировка элементов всего массива
void sort_all(int** array, int n, int m) {
    std::cout << "\n";
    sort_row_wp(array, n, m, 0);
    sort_row_wp(array, n, m, 1);
    sort_row_wp(array, n, m, 2);
    sort_row_wp(array, n, m, 3);
    sort_row_wp(array, n, m, 4);
    sort_row_wp(array, n, m, 5);
    sort_row_wp(array, n, m, 6);
    sort_row_wp(array, n, m, 7);
    sort_row_wp(array, n, m, 8);
    sort_row_wp(array, n, m, 9);
    sort_column_wp(array, n, m, 9);
    sort_column_wp(array, n, m, 8);
    sort_column_wp(array, n, m, 7);
    sort_column_wp(array, n, m, 6);
    sort_column_wp(array, n, m, 5);
    sort_column_wp(array, n, m, 4);
    sort_column_wp(array, n, m, 3);
    sort_column_wp(array, n, m, 2);
    sort_column_wp(array, n, m, 1);
    sort_column_wp(array, n, m, 0);
    std::cout << "Выводим отсортированный массив:";
    print_massive(array, n, m);
    std::cout << "\n";

}

// умножение матрицы на вектор
void multiplication_vector(int** array, int n, int m, vector<int>&vec) {

    std::cout << "\n Массив умноженный на вектор:";

    int count = 0;
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < m; j++) {
            int value = (*(*(array + i) + j));
            *(*(array + i) + j) =  value * vec[count];
            count++;
        }
        count = 0;
    }
    print_massive(array, n, m);
}

// преобразование матрицы путем умножени строки на число;
void multiplication_value(int** array, int n, int m, int value, int row) {
    std::cout << "\n преобразование матрицы путем умножени строки на число:";
    for (int i = 0; i < n; i++) {
        *(*(array + row) + i) = (*(*(array + i) + row) * value);
    }
    print_massive(array, 10, 10);
}

// преобразование матрицы путем деления строки на число
void division_value(int** array, int n, int m, int value, int row) {
    std::cout << "\n преобразование матрицы путем деления строки на число:";
    for (int i = 0; i < n; i++) {
        *(*(array + row) + i) = (*(*(array + i) + row) / value);
    }
    print_massive(array, 10, 10);
}

// транспонирование матрицы
void transposition(int** array, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            
            swap(* (*(array + i) + j), *(*(array + j) + i));
           
        }
    }

    std::cout << "\nТранспонирование матрицы:";

    print_massive(array, 10, 10);

}

// умножение матрицы на матрицу;
void multiplication_massives(int** mat1, int n, int m, int** mat2)
{
    int x, i, j;

    int** array_2;
    array_2 = new int* [n];

    int temp_j = 1;

    for (int i = 0; i < n; i++) {
        *(array_2 + i) = new int[m];
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(*(array_2 + i) + j) = 0;
            for (x = 0; x < m; x++)
            {
                *(*(array_2 + i) + j) += *(*(mat1 + i) + x) * *(*(mat2 + x) + j);
            }
        }
    }
    print_massive(array_2, 10, 10);
}



int main()
{
    setlocale(LC_ALL, "russian");
    std::cout << "Привет мир!\n";

    const int n = 10, m = 10;

    //Создание массива 
    int **array;
    array = new int* [n];
    for (int i = 0; i < n; i++) {
        *(array + i) = new int[m];
    }
    
    random_mas(array, n, m); // обход элементов массива заполнение массива данными псевдослучайными числами - ввод
    print_massive(array, n, m); // вывод массива на экран
    sum_row(array, n, m, 5); // вывод суммы элементов строки
    sum_column(array, n, m, 1); // вывод суммы элементов столбца
    main_diagonal(array, n, m); // Основная диагональ
    no_main_diagonal(array, n, m); // Побочна диагональ
    MaxIndex(array, n, m); // (не нужно делать) Максимальный индекс в массиве
    Max_index_in_row(array, n, m, 2); // Индекс максимального элемента в строке
    Min_index_in_row(array, n, m, 2); // Индекс минимального элемента в строке
    Max_index_in_column(array, n, m, 2); // Индекс максимального элемента в столбце
    Min_index_in_column(array, n, m, 2); // Индекс минимального элемента в столбце
    min_index_main_diagonal(array, n, m); // Минимальный индекс главной диагонали
    max_index_no_main_diagonal(array, n, m); // Максимальный индекс побочной диагонали
    in_one(array, n, m); // Преобразование матрицы в одномерный массив
    int mas[10] = {3,5,3,12,34,5,6,0,-4, 8};
    in_doble(mas, n); // Преобразование матрицы в двумерный массив из одномерного;
    find_and_count_row(array, n, m, 5, -10 , 50);
    find_and_count_column(array, n, m, 5, -10, 50);
    find_and_count_main_diagonal(array, n, m, 5, -10, 150);
    find_and_count_no_main_diagonal(array, n, m, 5, -10, 15);

    std::cout << "\nДобавление строки в массив:";
    int** array_3 = insert_row(array, n, m, mas);
    print_massive(array_3, n + 1, m);

    std::cout << "\nДобавление столбца в массив:";
    int** array_4 = insert_column(array, n, m, mas);
    print_massive(array_4, n, m + 1);

    std::cout << "\nУдаление столбца из массива:";
    int** array_5 = delet_column(array, n, m, 3);
    print_massive(array_5, n, m - 1);

    std::cout << "\nУдаление строки из массива:";
    int** array_6 = delet_row(array, n, m, 3);
    print_massive(array_6, n - 1, m);

    sort_row(array, n, m, 5);

    sort_column(array, n, m, 6);

    sort_all(array, n, m);

    vector<int> data = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9 , 10};
    multiplication_vector(array, n, m, data);

    multiplication_value(array, n, m, 0, 3);

    division_value(array, n, m, 10, 8);

    transposition(array, n, m);

    multiplication_massives(array, n, m, array);
   
}






