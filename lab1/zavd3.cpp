// Завдання 3: перестановки (без повторень). Послідовність спочатку
// перевіряємо на однакові елементи і виводимо лише якщо їх немає.
#include <iostream>
using namespace std;

int A[6];
int cnt = 0;

bool hasDuplicates() {
    for (int i = 1; i <= 5; i++)
        for (int j = i + 1; j <= 5; j++)
            if (A[i] == A[j]) return true;
    return false;
}

void try_(int k) {
    if (k != 0) {
        for (int v = 0; v <= 4; v++) {
            A[k] = v;
            try_(k - 1);
        }
    } else if (!hasDuplicates()) {
        for (int i = 1; i <= 5; i++) cout << A[i] << ' ';
        cout << '\n';
        cnt++;
    }
}

int main() {
    try_(5);
    cout << "Kilkist: " << cnt << '\n';
    return 0;
}
