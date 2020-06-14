#include <bits/stdc++.h> 
using namespace std; 
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    vector<int> v1,v2;
    int n,val,c1=0,c2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v1.push_back(val);
    }
    for(int i=0;i<n;i++)
    {
        cin>>val;
        v2.push_back(val);
    }
    int a;
    vector<int> tv;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[v2[j]].push_back(gcd(v1[i],v2[j]));
            if(mp[v2[j]][i]!=1 && v1[i]<v2[j])
            {
                c1+=1;
               // cout<<v1[i]<<" "<<v2[j]<<endl;
            }
        }
    }
    int i=0,j;
    for(auto x:mp)
    {
        int a=x.first;
        vector<int> tv=x.second;
        for(j=0;j<tv.size();j++)
        {
            if(tv[j]!=1 && v2[i]<v1[j])
                c2+=1;
        }
        i+=1;
    }
    cout<<max(c1,c2)<<endl;
}