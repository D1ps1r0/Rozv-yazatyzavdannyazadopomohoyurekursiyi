// Завдання 7: удав на полі 8x8 з каменями. Старт у клітинці (1,1),

#include <iostream>
using namespace std;

const int M = 8;
int f[M][M] = {
    {0, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 1, 0, 1, 0} };
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };
int best = 0;

void snake(int i, int j, int len) {
    f[i][j] = 2;
    if (len > best) best = len;
    for (int d = 0; d < 4; d++) {
        int ni = i + di[d], nj = j + dj[d];
        if (ni >= 0 && ni < M && nj >= 0 && nj < M && f[ni][nj] == 0)
            snake(ni, nj, len + 1);
    }
    f[i][j] = 0;
}

int main() {
    snake(0, 0, 1);
    cout << "Maksymalna dovzhyna udava: " << best << '\n';
    return 0;
}
