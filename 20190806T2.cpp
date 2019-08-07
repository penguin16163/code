
#include<bits/stdc++.h>
using namespace std;
vector<string> s;
set<string> xxr;
int l,t;
string st,c;
int main()
{
    freopen("notsub.in","r",stdin);
    freopen("notsub.out","w",stdout);
    cin>>st;
    l=st.length();
    for (register int i=0; i<l; ++i) {
        for (register int j=i; j<l; ++j) {
            c=st.substr(i,j-i+1);
            if (!xxr.count(c)) {
                xxr.insert(c);
                s.push_back(c);
            }
        }
    }
    for (register int i=0; i<s.size(); ++i) {
        for (register int j=i+1; j<s.size(); ++j) {
            if ((s[j].find(s[i])==-1)&&(s[i].find(s[j])==-1)) ++t;
        }
    }
    printf("%d\n", t);
    fclose(stdin);
    fclose(stdout);
    return 0;
}