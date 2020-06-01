#include <bits/stdc++.h> 
using namespace std; 
vector<int> dfsord;
void dfs(int v,int visit[],vector<int> adj[])
{
    int w;
    dfsord.push_back(v);
    visit[v]=1;
    for(auto ii=adj[v].begin();ii!=adj[v].end();ii++)
        if(visit[*ii]==0)
            dfs(*ii,visit,adj);
}
int main()
{
    int n,st,ed,e,i;
    cout<<"Enter the no of vertices"<<endl;
    cin>>n;
    vector<int> adj[n];
    cout<<"Enter the no of edges"<<endl;
    cin>>e;
    for(i=0;i<e;i++)
    {
        cout<<"Enter the start"<<i+1<<endl;
        cin>>st;
        cout<<"Enter the end"<<i+1<<endl;
        cin>>ed;
        adj[st].push_back(ed);
    }
    int visit[n];
    for(i=0;i<n;i++)
        visit[i]=0;
    //for(i=0;i<n;i++)
      //  if(visit[i]==0)
            dfs(2,visit,adj);
    for(auto ii=dfsord.begin();ii!=dfsord.end();ii++)
        cout<<*ii<<" ";
}