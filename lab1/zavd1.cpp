// Завдання 1: усі послідовності з 5 елементів множини A = {0,1}
#include <iostream>
using namespace std;

int A[6];

void try_(int k) {
    if (k != 0) {
        A[k] = 0; try_(k - 1);
        A[k] = 1; try_(k - 1);
    } else {
        for (int i = 1; i <= 5; i++) cout << A[i] << ' ';
        cout << '\n';
    }
}

int main() {
    try_(5);
    return 0;
}
