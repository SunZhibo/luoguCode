#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int L = 1000010;

ll ans;
int len, nxt[L];
char s[L];

int main() {
    ios::sync_with_stdio(false);
    cin >> len >> s;
    for (int k = 0, i = 1; i < len; i++) {
        while(k && s[i] != s[k]) k = nxt[k];
        nxt[i + 1] = s[i] == s[k] ? ++k : 0;
    }
    for (int j = 1, i = 1; i <= len; i++, j = i) {
        while(nxt[j]) j = nxt[j];
        if (nxt[i]) nxt[i] = j;
        ans += (i - j);
    }
    cout << ans << endl;
    return 0;
}