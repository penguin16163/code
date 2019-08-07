#include<bits/stdc++.h>
using namespace std;
int v[105];
double w[105],f[10005];
int T,n,s;
double p;
int main() 
{
    scanf("%d", &T);
    while (T--) {
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        memset(f,0,sizeof(f));
        s=0;
        scanf("%lf%d", &p, &n);
        for (register int i=1; i<=n; ++i) {
           scanf("%d%lf", &v[i], &w[i]);  
            s+=v[i];  
        }
        f[0]=1; 
        for (register int i=1; i<=n; ++i) {
            for (register int j=s; j>=v[i]; --j) {
                f[j]=max(f[j],f[j-v[i]]*(1-w[i]));
            }
        } 
        for (register int i=s; i>=0; --i) {
            if (f[i]>1-p) {
                printf("%d\n",i);
                break;
            }
        }
    }
}