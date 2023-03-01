#pragma once

void HelloWorld();

void random(int mas[], int n);
void print_mas(int mas[], int n);

void random(int mas[], float n);
void print_mas(int mas[], float n);

int sum_mas(int mas[], int n, int a, int b, bool (*pred) (int i, int a, int b));

bool diapazon(int i, int a, int b);

void delete_elem(int mas[], int n, int index);

void add_elem(int mas[], int n, int index, int elem);

void bubble_sort(int mas[], int n);

void selection_sort(int mas[], int n);

void insertion_sort(int mas[], int n);

int linerial_search_min(int mas[], int n);

int linerial_search_max(int mas[], int n);

int binary_search(int mas[], int n, int elem);

int podschet_elementov(int mas[], int n, bool (*pred)(int elem));

bool polozitelnie(int elem);

bool otricatelnie(int elem);

bool nulevie(int elem);

bool kvadratnie(int elem);

void save_to_file(int mas[], int n);

void read_to_file(int mas[], int n);

int v_11_find_min_elem(int mas[], int n);

int v_11_sum_elems_left_otricat(int mas[], int n);

void zip_massive(int mas[], int n, int min, int max);

