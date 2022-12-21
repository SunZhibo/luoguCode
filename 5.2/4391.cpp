#include <iostream>
#include <cstring>

using namespace std;

const int L = 1000010;

int len, nxt[L];
char s[L];

int main() {
    ios::sync_with_stdio(false);
    cin >> len >> s;
    for (int k = 0, i = 1; i < len; i++) {
        while(k && s[i] != s[k]) k = nxt[k];
        nxt[i + 1] = s[i] == s[k] ? ++k : 0;
    }
    cout << len - nxt[len] << endl;
    return 0;
}