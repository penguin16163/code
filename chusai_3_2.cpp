#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll J(int x) 
{
    if (x==0) return 0;
    ll s=1;
    for (int i=1; i<=x; ++i) s*=i;
    return s;
}
int main()
{
    char s[20];
    ll ans=0;
    cin >> s;
    int len =strlen(s);
    for (int i=0; i<len; ++i) {
        ll co=0;
        for (int j=i+1; j<len; ++j) if (s[i]>s[j]) ++co;
        ans+=J(len-i-1)*co;
    }
    ans+=1;
    printf("%d", ans);
}
/*
input:
25431

output:
48
*/
