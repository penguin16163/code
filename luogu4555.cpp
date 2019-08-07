#include<bits/stdc++.h>
#define maxN 200005
using namespace std;
char s[maxN],t[maxN];
int len;
int l[maxN],r[maxN],p[maxN];
int main()
{
    scanf("%s", &s);
    len=strlen(s);
    int cnt=0;
    t[++cnt]='@',t[++cnt]='%';
    for (int i=0; i<len; ++i) {
        t[++cnt]=s[i];
        t[++cnt]='%';
    }
    t[++cnt]='\0';
    int mx=0,x=0;
    for (int i=1; i<=cnt; ++i) {
        if (i<mx) p[i]=min(p[x*2-i],mx-i);
        else p[i]=1;
        while (t[i-p[i]]==t[i+p[i]]) ++p[i];
        if (mx<i+p[i]) {
            x=i;
            mx=i+p[i];
        }
        l[i+p[i]-1]=max(l[i+p[i]-1],p[i]-1);
        r[i-p[i]+1]=max(r[i-p[i]+1],p[i]-1);
    }
    for (int i=2; i<=cnt; i+=2) 
        r[i]=max(r[i],r[i-2]-2);
    for (int i=cnt; i>=2; i-=2)
        l[i]=max(l[i],l[i+2]-2);
    int ans=0;
    for (int i=2; i<=cnt; i+=2)
        if ((l[i]!=0)&&(r[i]!=0)) ans=max(ans,l[i]+r[i]);
    printf("%d\n",ans);
}

