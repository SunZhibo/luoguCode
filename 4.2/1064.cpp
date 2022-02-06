#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 61;
const int M = 3201;

int n, V;
int f[M], g[M];

struct data {
    int vol, val, bel;
    data(){}
    data(int _vol, int _val, int _bel):vol(_vol), val(_val), bel(_bel){}
}d[N];

int main() {
    cin >> V >> n, V /= 10;
    for (int a, b, c, i = 1; i <= n; i++)
        cin >> a >> b >> c, a /= 10, d[i] = data(a, a * b, c);
    for (int sum, i = 1; i <= n; i++) {
        if (d[i].bel) continue;
        memset(g, 0, sizeof(g)), sum = 0;
        for (int j = 1; j <= n; j++)
            if (d[j].bel == i) {
                sum += d[j].vol;
                for (int k = V; k >= d[j].vol; k--)
                    g[k] = max(g[k], g[k - d[j].vol] + d[j].val);
            }
        for (int j = V; j >= d[i].vol; j--)
        for (int k = min(sum, j - d[i].vol); k >= 0; k--)
            f[j] = max(f[j], f[j - d[i].vol - k] + g[k] + d[i].val);
    }
    cout << f[V] * 10 << endl;
    return 0;
}