#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int n,fail[1000010],ans[1000010];
long long cnt;
char a[1000010];
int main()
{
    int T,i,j;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",a);n=strlen(a);
        memset(fail,0,sizeof(fail));
        j=0;
        ans[0]=0;
        ans[1]=1;
        for(i=1; i<n; i++){
            while (j&&(a[i]!=a[j])) j=fail[j];
            j+=(a[i]==a[j]);fail[i+1]=j;
            ans[i+1]=ans[j]+1;
        }

        j=0;
        cnt=1;
        for(i=1;i<n;i++) {
            while(j&&(a[i]!=a[j])) j=fail[j];
            j+=(a[i]==a[j]);
            while((j<<1)>(i+1)) j=fail[j];
            cnt=(cnt*(long long)(ans[j]+1))%MOD;
        }
        printf("%lld\n",cnt);
    }
}