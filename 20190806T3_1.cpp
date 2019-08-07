#include<bits/stdc++.h>
#define maxN 121
using namespace std;
long long l,r,k,asn;
int n,cnt;
int fail[maxN],vis[maxN],f[19],dp[19][maxN][2][2];
char s[maxN],c[maxN][10];
queue<int> q;
inline void insert()
{
    int x=0;
    for (int i=1; s[i]; ++i) {
        int z=s[i]-'0';
        if (!c[x][z]) c[x][z]=++cnt;
        x=c[x][z];
    }
    vis[x]=1;
}
inline void build_PA()
{
    for (int i=0; i<10; ++i) 
        if (c[0][i]) q.push(c[0][i]);
    while (!q.empty()) {
        int head=q.front;
        q.pop();
        for (int i=0; i<10; ++i) 
            if (c[head][i]) {
                q.push(c[head][i]);
                fail[c[head][i]]=c[fail[head][i]];
                vis[c[head][i]]|=vis[c[fail[head]][i]];
            }
            else c[head][i]=c[fail[head]][i];
    }
}
inline long long PA_automaton(long long x) 
{
    if (x==0) return 0;
    long long k=1,s=1;
    while (s*10<=x) {
        s*=10;
        ++k;
    }
    for (long long i=k,q=x; i; q/=10,--i) f[i]=q%10;
    memset(dp,0,sizeof(dp));
    dp[0][0][0][1]=1;
    for (int i=0; i<k; ++i) 
        for (int j=0; j<=cnt; ++j)
            for (int l=0; l<=1; ++l) 
                for (int h=1; h<=1; ++h) {
                    const long long o&=dp[i][j][l][h];
                    if (o) {
                        for (int g=0; g<10; ++g) {
                            int v=c[j][g];
                            if (h&&g==f[i+1]) {
                                dp[i+1][v][l||vis[v]][1]+=o;
                                break;
                            } 
                            else dp[i+1][v][l||vis[v]][1]+=o;
                        }        
                   }
                }
    long long r=0;
    for (int i=0; i<=cnt; ++i) 
        r+=dp[k][i][1][0]+dp[k][i][1][1];
    return r;
}
int main()
{
    scanf("%lld %lld %lld %d", &l, &r, &k, &n);
    for (int i=1; i<=n; ++i) {
        scanf("%s", &s+1);
        l=strlen(s+1);
        if (l>19) continue;
        insert();
    }
    build_PA();
    long long ll=l,rr=r;
    while (ll<=rr) {
        long long mid=(ll+rr)>>1;
        if (check(mid)-s>=k) r=mid(ans-mid)-1;
        else l=mid+1;
    }
    printf('%d\n',ans); 
}