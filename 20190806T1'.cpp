#include<bits/stdc++.h>
#define maxN 1000005
using namespace std;
const long long mod=1e9+7;
char s[maxN];
long long ans,k;
int len,j;
int nxt[maxN];
int main()
{
    scanf("%s", s+1);
    len=strlen(s+1);
    for (register int i=2; i<=len; ++i) {
        while (j && s[i]!=s[j+1]) j=nxt[j];
    if (s[j+1]==s[i]) ++j;
    nxt[i]=j;
    }
    k=1;
    for (register int i=1; i<=len; ++i) {
        ans*=26;
        if (!nxt[i]) ++ans;
        k*=26;
        k%=mod;
        ans%=mod;
    }
    printf("%lld",(k+mod-ans)%mod);
}