// Завдання 8: карта 10x10, 0 - озеро, 1 - суша.

#include <iostream>
using namespace std;

const int L = 10;
int m[L][L] = {
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 1, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1}};
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void fill(int i, int j) {
    if (i < 0 || j < 0 || i >= L || j >= L || m[i][j] != 0) return;
    m[i][j] = 2;
    for (int d = 0; d < 4; d++) fill(i + di[d], j + dj[d]);
}

int main() {
    int lakes = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            if (m[i][j] == 0) { lakes++; fill(i, j); }
    cout << "Kilkist ozer: " << lakes << '\n';
    return 0;
}
