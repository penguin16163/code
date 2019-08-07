#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

const int MAXN = 50001;
string st, a[MAXN];
int main() {
    freopen("notsub.in", "r", stdin);
    freopen("notsub.out", "w", stdout);
    cin >> st;
    register int len = st.length(), cnt = 0;
    for (register int i = 0; i < len; ++i)
        for (register int j = i; j < len; ++j)  {
            register bool flag = 1;
            register string tmp = st.substr(i, j - i + 1);
            for (register int k = 1; k < cnt; ++k) 
                if (a[k] == tmp) {
                    flag = 0;
                    break;
                }
            if (flag) a[++cnt] = tmp;
        }
    register int ans = 0;
    for (register int i = 1; i <= cnt; ++i)
        for (register int j = i + 1; j <= cnt; ++j)
            if (a[i].find(a[j]) == -1 && a[j].find(a[i]) == -1) ++ans;
    printf("%d\n", ans);
    return 0;
}