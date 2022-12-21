#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

const int L = 1000010;

int nxt[L], match[L];
char S[L], T[L];
stack<int> stk;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> S >> T;
    int lenS = strlen(S), lenT = strlen(T);
    for (int k = 0, i = 1; i < lenT; i++) {
        while(k && T[i] != T[k]) k = nxt[k];
        nxt[i + 1] = T[i] == T[k] ? ++k : 0;
    }
    for (int k = 0, i = 0; i < lenS; i++) {
        while(k && S[i] != T[k]) k = nxt[k];
        if (S[i] == T[k]) k++;
        match[i] = k, stk.push(i);
        if (k == lenT) {
            while(k--) stk.pop();
            if (stk.empty()) k = 0;
            else k = match[stk.top()];
        }
    }
    while(!stk.empty())
        ans.push_back(S[stk.top()]), stk.pop();
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}