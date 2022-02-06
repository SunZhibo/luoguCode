#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1001;
const int M = 1001;

int n, V;
int f[2][M];

struct data {
    int vol, val, bel;
    data(){}
    data(int _vol, int _val, int _bel):vol(_vol), val(_val), bel(_bel){}
    bool operator < (const data& X) const {
        return bel < X.bel;
    }
}d[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> V >> n;
    for (int a, b, c, i = 1; i <= n; i++)
        cin >> a >> b >> c, d[i] = data(a, b, c);
    sort(d + 1, d + n + 1);
    int now = 0, last = 1;
    for (int r = 1, l = 1; l <= n; l = r) {
        while(d[r].bel == d[l].bel) r++;
        for (int i = l; i < r; i++) {
            for (int j = V; j >= d[i].vol; j--)
                f[now][j] = max(f[now][j], f[last][j - d[i].vol] + d[i].val);
            
        }
        swap(now, last);
        memcpy(f[now], f[last], sizeof(f[now]));
    }
    cout << f[now][V] << endl;
    return 0;
}