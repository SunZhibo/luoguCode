#include <iostream>
#include <cstdio>

using namespace std;

const int N = 101;
const int M = 1001;

int n, V;
int f[M];

int main() {
    ios::sync_with_stdio(false);
    cin >> V >> n;
    for (int vol, val, i = 1; i <= n; i++) {
        cin >> vol >> val;
        for (int j = V; j >= vol; j--)
            f[j] = max(f[j], f[j - vol] + val);
    }
    cout << f[V] << endl;
    return 0;
}