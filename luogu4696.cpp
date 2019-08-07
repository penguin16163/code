#include<cstdio>
const int N=1e6+50;
inline void read(int &_)
{
    static char ch;
    while(ch=getchar(),ch<'0'||ch>'9');_=ch-48;
    while(ch=getchar(),ch<='9'&&ch>='0')_=_*10+ch-48;
}
int Out[10],out;
inline void prt(int u)
{
    if(!u)++out;
    else for(;u;Out[++out]=u%10,u/=10);
    for(;out;putchar(48+Out[out--]));
    putchar(' ');
}
int n,m,x,ans;
int a[N],b[N],c[N],kmp[N];
int pre[N],net[N],L[N],R[N],Ans[N];
inline bool get(int *p,int u,int v)
{
    return (!L[u]||p[v+L[u]]<p[v])&&(!R[u]||p[v+R[u]]>p[v]);
}
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) {
        read(b[i]);a[b[i]]=i;
        pre[i]=i-1;net[i]=i+1;
    }
    for(int i=n;i>=1;i--) {
        x=a[i];
        if(pre[x])L[i]=b[pre[x]]-i;
        if(net[x]<=n)R[i]=b[net[x]]-i;
        pre[net[x]]=pre[x];
        net[pre[x]]=net[x];
    }
    x=0;
    for(int i=2;i<=n;i++){
        while(x&&!get(a,x+1,i))x=kmp[x];
        if(get(a,x+1,i))x++;
        kmp[i]=x;
    }
    x=0;
    for (int i=1;i<=m;i++) read(c[i]);
    for(int i=1;i<=m;i++){
        while(x&&!get(c,x+1,i))x=kmp[x];
        if(get(c,x+1,i))x++;
        if(x==n)Ans[++ans]=i-n+1,x=kmp[x];
    }
    prt(ans);putchar('\n');
    for(int i=1;i<=ans;i++)prt(Ans[i]);
}