#include<bits/stdc++.h>
using namespace std;

string str[205];


int main()
{
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        cin>>str[i];
    for (int i=1; i<=n; ++i) {
        int ans=0;
        for (int j=1; j<=n; ++j) {
            int k=0;
            while (str[i].find(str[j],k)!=string::npos)  {
                k=str[i].find(str[j],k);
                k+=str[j].size()-1;
                ans++;
            } 
        }
        printf("%d\n",ans);
    }
}