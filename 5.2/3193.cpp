#include <iostream>
#include <cstring>

using namespace std;

const int L = 21;

int mod, n, m;
char s[L];
int nxt[L];

struct matrix {
    int h, w;
    int mat[L][L];
    matrix(int _h, int _w):w(_w), h(_h){
        memset(mat, 0, sizeof mat);
    }
    matrix operator * (const matrix& x) {
        matrix res(h, x.w);
        for (int i = 0; i < h; i++)
        for (int j = 0; j < x.w; j++)
        for (int k = 0; k < w; k++)
            (res.mat[i][j] += mat[i][k] * x.mat[k][j]) %= mod;
        return res;
    }
};

matrix qpow(matrix base, int val) {
    matrix res(m, m);
    for (int i = 0; i < m; i++)
        res.mat[i][i] = 1;
    while(val) {
        if (val & 1)
            res = res * base;
        base = base * base;
        val >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> mod >> s;
    for (int k = 0, i = 1; i < m; i++) {
        while(k && s[k] != s[i]) k = nxt[k];
        nxt[i + 1] = s[i] == s[k] ? ++k : 0;
    }
    matrix base(1, m), mul(m, m);
    for (int i = 0; i < m; i++)
    for (int j = 0; j < 10; j++) {
        int k = i;
        while(k && j != (s[k] - '0')) k = nxt[k];
        if (j == (s[k] - '0')) k++;
        if (k < m) mul.mat[i][k]++;
    }
    base.mat[0][0] = 1;
    matrix res = base * qpow(mul, n);
    int ans = 0;
    for (int i = 0; i < m; i++)
        (ans += res.mat[0][i]) %= mod;
    cout << ans << endl;
    return 0;
}