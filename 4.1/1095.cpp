#include <iostream>
#include <cstdio>

using namespace std;

int M, S, T;

int main() {
    int d1 = 0, d2 = 0;
    ios::sync_with_stdio(false);
    cin >> M >> S >> T;
    for (int i = 1; i <= T; i++) {
        if (M >= 10)
            M -= 10, d1 += 60;
        else
            M += 4;
        d2 = max(d2 + 17, d1);
        if (d2 >= S) {
            cout << "Yes" << endl << i << endl;
            return 0;
        }
    }
    cout << "No" << endl << d2 << endl;
    return 0;
}