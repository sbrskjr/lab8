#include <iostream>
#include <string>
#include "array_utils.h"
#include "matrix_utils.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1. Завдання 1 (Array97 - видалення дублікатів)" << endl;
        cout << "2. Завдання 2 (Matrix19 - сума рядків)" << endl;
        cout << "3. Завдання 3 (Сортування вибором)" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            task_array_97();
        } else if (choice == 2) {
            task_matrix_19();
        } else if (choice == 3) {
            task_sort_3();
        }
    } while (choice != 0);

    return 0;
}
