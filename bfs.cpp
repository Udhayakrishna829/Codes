#include <bits/stdc++.h> 
using namespace std; 
vector<int> bfsord;
queue<int> q;
void bfs(int v,int visit[],vector<int> adj[])
{
    int w,k;
    bfsord.push_back(v);
    visit[v]=1;
    q.push(v);
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        for(auto ii=adj[k].begin();ii!=adj[k].end();ii++)
        {
            if(visit[*ii]==0)
            {
                visit[*ii]=1;
                q.push(*ii);
                bfsord.push_back(*ii);
            }
        }
    }
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
            bfs(2,visit,adj);
    for(auto ii=bfsord.begin();ii!=bfsord.end();ii++)
        cout<<*ii<<" ";
}