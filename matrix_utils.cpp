#include "matrix_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void task_matrix_19() {
    double mx[MAX_ROWS][MAX_COLS];
    double sums[MAX_ROWS];
    int m = 0, n = 0;
    string in_file = "matr_in_19.txt";
    
    cout << "Введіть ім'я файлу (enter для matr_in_19.txt): ";
    string temp;
    cin.ignore();
    getline(cin, temp);
    if (!temp.empty()) in_file = temp;
    
    read_matrix_from_file(in_file, mx, m, n);
    if (m == 0 || n == 0) return;
    
    cout << "Вихідна матриця:" << endl;
    print_matrix(mx, m, n);
    
    calculate_row_sums(mx, m, n, sums);
    
    append_matrix_results_to_file(in_file, sums, m);
    cout << "Результати дописано у файл " << in_file << endl;
}

void calculate_row_sums(const double mx[][MAX_COLS], int m, int n, double sums[]) {
    for (int i = 0; i < m; i++) {
        sums[i] = 0;
        for (int j = 0; j < n; j++) {
            sums[i] += mx[i][j];
        }
    }
}

void read_matrix_from_file(string filename, double mx[][MAX_COLS], int &m, int &n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        m = 0; n = 0;
        return;
    }
    fin >> m >> n;
    if (m > MAX_ROWS) m = MAX_ROWS;
    if (n > MAX_COLS) n = MAX_COLS;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> mx[i][j];
        }
    }
    fin.close();
}

void append_matrix_results_to_file(string filename, const double sums[], int m) {
    ofstream fout(filename, ios::app);
    if (!fout.is_open()) {
        cout << "Помилка дозапису " << filename << endl;
        return;
    }
    fout << endl << "Суми елементів рядків:" << endl;
    for (int i = 0; i < m; i++) {
        fout << sums[i] << " ";
    }
    fout << endl;
    fout.close();
}

void print_matrix(const double mx[][MAX_COLS], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mx[i][j] << "	";
        }
        cout << endl;
    }
}
