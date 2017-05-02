#include <iostream>

using namespace std;

int main() {
    int m[4][4] = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
    int i = 0;
    int j = 0;
    int k = 3;
    int l = 3;
    while (i <= k && j <= l) {
        for (int t = j; t <= l; t++)
            cout << m[i][t] << " ";
        i++;
        for (int t = i; t <= k; t++)
            cout << m[t][l] << " ";
        l--;
        for (int t = l; t >= j; t--)
            cout << m[k][t] << " ";
        k--;
        for (int t = k; t >= i; t--)
            cout << m[t][j] << " ";
        j++;
    }
    return 0;
}