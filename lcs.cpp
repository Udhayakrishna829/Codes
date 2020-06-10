#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2)
{
    int m=s1.length(),n=s2.length();
    int lcs[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(s1[i-1]==s2[j-1])
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[m][n];
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<lcs(s1,s2);

}
