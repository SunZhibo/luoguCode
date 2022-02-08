#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 150001;

int n, ans;
int val[N], f[N];
struct data {
    int id, dis; bool isL;
    data(){}
    data(int _id, int _dis, bool _isL):id(_id), dis(_dis), isL(_isL){}
    bool operator < (const data &T) const {
        if (dis == T.dis)
            return isL > T.isL;
        return dis < T.dis;
    }
}p[N * 2];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int l, r, i = 1; i <= n; i++) {
        cin >> l >> r, val[i] = r - l + 1;
        p[i * 2 - 1] = data(i, l, true);
        p[i * 2] = data(i, r, false);
    }
    sort(p + 1, p + n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) {
        int id = p[i].id;
        if (p[i].isL)
            f[id] = ans + val[id];
        else
            ans = max(ans, f[id]);
    }
    cout << ans << endl;
    return 0;
}