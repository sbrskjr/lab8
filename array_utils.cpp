#include "array_utils.h"
#include <iostream>
#include <fstream>

using namespace std;

void task_array_97() {
    int arr[MAX_SIZE];
    int n = 0;
    string in_file = "array_in_97.txt";
    string out_file = "array_out_97.txt";
    
    cout << "Введіть ім'я вхідного файлу (або enter для array_in_97.txt): ";
    string temp;
    cin.ignore();
    getline(cin, temp);
    if (!temp.empty()) in_file = temp;
    
    read_array_from_file(in_file, arr, n);
    if (n == 0) return;
    
    cout << "Вихідний масив: ";
    print_array(arr, n);
    
    remove_duplicates(arr, n);
    
    cout << "Масив після обробки: ";
    print_array(arr, n);
    
    write_array_to_file(out_file, arr, n);
    cout << "Результат записано у файл " << out_file << endl;
}

void task_sort_3() {
    int arr[MAX_SIZE];
    int n = 0;
    string in_file = "sort_in_3.txt";
    string out_file = "sort_out_3.txt";
    
    read_array_from_file(in_file, arr, n);
    if (n == 0) return;
    
    cout << "Несортований масив: ";
    print_array(arr, n);
    
    selection_sort(arr, n);
    
    cout << "Відсортований масив: ";
    print_array(arr, n);
    
    write_array_to_file(out_file, arr, n);
    cout << "Записано у " << out_file << endl;
}

void remove_duplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        bool has_duplicate_later = false;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                has_duplicate_later = true;
                break;
            }
        }
        if (has_duplicate_later) {
            for (int k = i; k < n - 1; k++) {
                arr[k] = arr[k + 1];
            }
            n--;
            i--;
        }
    }
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void read_array_from_file(string filename, int arr[], int &n) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Помилка відкриття файлу " << filename << endl;
        n = 0;
        return;
    }
    fin >> n;
    if (n > MAX_SIZE) n = MAX_SIZE;
    for (int i = 0; i < n; i++) {
        fin >> arr[i];
    }
    fin.close();
}

void write_array_to_file(string filename, const int arr[], int n) {
    ofstream fout(filename);
    if (!fout.is_open()) {
        cout << "Помилка запису у файл " << filename << endl;
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << arr[i] << " ";
    }
    fout << endl;
    fout.close();
}

void print_array(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
