#include <iostream>
#include <cmath>
using namespace std;

int calculate_level(int index) {
    return static_cast<int>(log2(index + 1));
}

bool has_left_child(int index, int heap_size) {
    int left_child_index = 2 * index + 1;
    return left_child_index < heap_size;
}

bool has_right_child(int index, int heap_size) {
    int right_child_index = 2 * index + 2;
    return right_child_index < heap_size;
}

bool has_parent(int index) {
    return index > 0;
}

void print_current_position(int heap[], int index) {
    int level = calculate_level(index);
    if (index == 0) {
        cout << "Вы находитесь здесь: " << level << " root " << heap[index] << endl;
    } else if (index % 2 == 1) {
        cout << "Вы находитесь здесь: " << level << " left(" << heap[(index - 1) / 2] << ") " << heap[index] << endl;
    } else {
        cout << "Вы находитесь здесь: " << level << " right(" << heap[(index - 2) / 2] << ") " << heap[index] << endl;
    }
}

bool move_up(int& index) {
    if (has_parent(index)) {
        index = (index - 1) / 2;
        return true;
    } else {
        cout << "Ошибка! Отсутствует родитель" << endl;
        return false;
    }
}

bool move_left(int& index, int heap_size) {
    if (has_left_child(index, heap_size)) {
        index = 2 * index + 1;
        return true;
    } else {
        cout << "Ошибка! Отсутствует левый потомок" << endl;
        return false;
    }
}

bool move_right(int& index, int heap_size) {
    if (has_right_child(index, heap_size)) {
        index = 2 * index + 2;
        return true;
    } else {
        cout << "Ошибка! Отсутствует правый потомок" << endl;
        return false;
    }
}

int main() {
    int arrays[][10] = {
        {1, 3, 6, 5, 9, 8, 0, 0, 0, 0},
        {94, 67, 18, 44, 55, 12, 6, 42, 0, 0},
        {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}
    };

    for (auto& array : arrays) {
        int n = sizeof(array) / sizeof(array[0]);

        cout << "Исходный массив: ";
        for (int i = 0; i < n; ++i) {
            if (array[i] != 0) {
                cout << array[i] << " ";
            }
        }
        cout << endl;

        cout << "Пирамида:" << endl;
        for (int i = 0; i < n; ++i) {
            if (array[i] != 0) {
                int level = calculate_level(i);
                if (i == 0) {
                    cout << level << " root " << array[i] << endl;
                } else if (i % 2 == 1) {
                    cout << level << " left(" << array[(i - 1) / 2] << ") " << array[i] << endl;
                } else {
                    cout << level << " right(" << array[(i - 2) / 2] << ") " << array[i] << endl;
                }
            }
        }
        cout << endl;

        int current_index = 0;
        bool running = true;
        while (running) {
            print_current_position(array, current_index);

            cout << "Введите команду: ";
            string command;
            cin >> command;

            if (command == "up") {
                if (!move_up(current_index)) {
                } else {
                    cout << "Ок" << endl;
                }
            } else if (command == "left") {
                if (!move_left(current_index, n)) {
                } else {
                    cout << "Ок" << endl;
                }
            } else if (command == "right") {
                if (!move_right(current_index, n)) {
                } else {
                    cout << "Ок" << endl;
                }
            } else if (command == "exit") {
                running = false;
            } else {
                cout << "Неизвестная команда. Пожалуйста, используйте одну из команд: up, left, right, exit" << endl;
            }
        }

        cout << endl;
    }

    return 0;
}