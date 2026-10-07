// Завдання 5: лабіринт з кількома виходами.
#include <iostream>
using namespace std;

const int N = 6;
int a[N][N] = {
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 1} };
int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };


void try_(int i, int j, int z, int& k) {
    a[i][j] = 2;
    if (z > 0 && (i == 0 || j == 0 || i == N - 1 || j == N - 1)) {
        if (z < k) k = z;
    }
    else {
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d], nj = j + dj[d];
            if (ni >= 0 && ni < N && nj >= 0 && nj < N && a[ni][nj] == 0)
                try_(ni, nj, z + 1, k);
        }
    }
    a[i][j] = 0;
}

int main() {
    int k = 36;
    try_(3, 2, 0, k);
    if (k == 36) cout << "Vykhodu nemaye\n";
    else cout << "Minimalna kilkist krokiv k = " << k << '\n';
    return 0;
}
