#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int K = 1000010;
const int mod = 19940417;

int n, k, val;
ll f[K][2];
struct point {
    int x, y;
    point(){}
    point(int _x, int _y):x(_x), y(_y){}
    bool operator == (const struct point& P) const {
        return x == P.x && y == P.y;
    }
    bool operator < (const struct point& P) const {
        return x < P.x;
    }
}p[K];

inline void add(ll &x, const ll y) {
    (x += y) %= mod;
}

ll qpow(ll p, ll q) {
    ll res = 1, base = p;
    while(q) {
        if (q & 1)
            (res *= base) %= mod;
        q >>= 1, (base *= base) %= mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int x, y, i = 1; i <= k; i++)
        cin >> x >> y, p[i] = point(x, y);
    p[0] = point(0, 0), p[++k] = point(n, 0);
    sort(p, p + k + 1);
    k = unique(p, p + k + 1) - p - 1;
    f[0][1] = 1;
    for (int i = 1; i <= k; i++) {
        int extra = (p[i].x - p[i - 1].x) - (p[i].y + p[i - 1].y);
        if (p[i].x == p[i - 1].x || extra & 1) continue;
        if (p[i].x - p[i - 1].x == p[i].y - p[i - 1].y) {
            add(f[i][0], f[i - 1][0]);
            if (p[i - 1].y == 0) add(f[i][0], f[i - 1][1]);
        } else if (p[i].x - p[i - 1].x == p[i - 1].y - p[i].y) {
            add(f[i][1], f[i - 1][1] + f[i - 1][0]);
        } else if (extra < 0) {
            add(f[i][1], f[i - 1][0]);
            if (p[i - 1].y == 0) add(f[i][1], f[i - 1][1]);
        } else if (extra == 0) {
            add(f[i][0], f[i - 1][0] + f[i - 1][1]);
            add(f[i][1], f[i - 1][0]);
            if (p[i - 1].y == 0) add(f[i][1], f[i - 1][1]);
        } else {
            ll t = (2 * f[i - 1][0] + f[i - 1][1]) * qpow(2, extra / 2 - 1) % mod;
            add(f[i][1], t);
            if (p[i].y != 0) add(f[i][0], t);
        }
        if (f[i - 1][0])
            val = max(val, (p[i].x - p[i - 1].x + p[i].y + p[i - 1].y) / 2);
        val = max(val, (p[i].x - p[i - 1].x + p[i].y - p[i - 1].y) / 2);
    }
    if (!f[k][1]) val = 0;
    cout << f[k][1] << " " << val << endl;
    return 0;
}