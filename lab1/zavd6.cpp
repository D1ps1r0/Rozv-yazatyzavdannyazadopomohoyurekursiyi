// Завдання 6: трикутник чисел, найбільша сума шляху зверху вниз

#include <iostream>
#include <algorithm>
using namespace std;

const int R = 4;
int tri[R][R] = {
    {7},
    {3, 8},
    {8, 1, 0},
    {2, 7, 4, 4}};
int memo[R][R];

int maxPath(int r, int c) {
    if (r == R) return 0;
    if (memo[r][c] != -1) return memo[r][c];
    return memo[r][c] = tri[r][c] + max(maxPath(r + 1, c), maxPath(r + 1, c + 1));
}

int main() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < R; j++) memo[i][j] = -1;
    cout << "Naybilsha suma: " << maxPath(0, 0) << '\n';
    return 0;
}
