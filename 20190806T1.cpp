#include<bits/stdc++.h>
#define mod 1e9+7
using namespace std;
int len,ans;
string st;
inline bool check(string s) 
{
    string head= "",tail="";
    for (int i=0; i<len; ++i) {
        head+=s[i]; 
		tail+=st[len-i-1];
        if (head==tail) return 0;
    }
    return 1;
}
inline void dfs(string s, int x) {
    if (x==len+1) {
        if (check(s)) ++ans;
        return ;
    }
    for (char i='a'; i<='z'; ++i)
        dfs(s+i, x+1);
}
int main() {
    freopen("diff.in", "r", stdin);
    freopen("diff.out", "w", stdout);
    cin>>st;
    len=st.length();
    dfs("", 1);
    printf("%d\n", ans);
    return 0;
}
