
#include <iostream>
#include "Header.h"
#include <stdlib.h>

using namespace std;

int main()
{
	HelloWorld();

    int massive[10];
    random(massive, 10);
    print_mas(massive, 10);

    int massive_3[10];
    const float t = 10.5;
    random(massive_3, t); 
    print_mas(massive_3, t);

    cout << endl;

    int sum = sum_mas(massive, 10, 2, 5, diapazon);
    cout << "Sum=" << sum;
    delete_elem(massive, 10, 5);
    print_mas(massive, 10);
    add_elem(massive, 10, 3, 9999);
    print_mas(massive, 10);
    bubble_sort(massive, 10);
    print_mas(massive, 10);
    selection_sort(massive, 10);
    print_mas(massive, 10);
    insertion_sort(massive, 10);
    print_mas(massive, 10);
    int min_index = linerial_search_min(massive, 10);
    cout << "\nMin_index=" << min_index;
    int max_index = linerial_search_max(massive, 10);
    cout << "\nMax_index=" << max_index;
    int index_elem = binary_search(massive, 10, 9999);
    cout << "\nIndex_elem=" << index_elem;
    int index_elem_2 = binary_search(massive, 10, 26500);
    cout << "\nIndex_elem_2=" << index_elem_2;
    int a = podschet_elementov(massive, 10, polozitelnie);
    cout << "\npolozitelnie=" << a;
    int b = podschet_elementov(massive, 10, otricatelnie);
    cout << "\notricatelnie=" << b;
    int c = podschet_elementov(massive, 10, nulevie);
    cout << "\nnulevie=" << c;
    int d = podschet_elementov(massive, 10, kvadratnie);
    cout << "\nkvadratnie=" << d;
    save_to_file(massive, 10);
    read_to_file(massive, 10);

    int massive_2[10] = { 10, 40, 13, 54, -1, 41, -10, 320, -5, 21 };
    print_mas(massive_2, 10);

    int e = v_11_find_min_elem(massive_2, 10);
    cout << "\nIndex min value=" << e;

    int f = v_11_sum_elems_left_otricat(massive_2, 10);
    cout << "\nSum elems=" << f;

    cout << endl;

    zip_massive(massive_2, 10, 3, 7);
    


    return EXIT_SUCCESS;

}



