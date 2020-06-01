#include <bits/stdc++.h> 
using namespace std; 
typedef pair<int,int> p;
void djikstra(vector<p> adj[],int s,int n) 
{
    int i,dist[n],visit[n];
    for(i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
        visit[i]=0;
    }
    priority_queue<p,vector<p>,greater<p>> pq;
    pq.push(make_pair(0,s));
    dist[s]=0;
    visit[s]=1;
    while(pq.empty()==false)
    {
        int u=pq.top().second;
        pq.pop();
        visit[u]=1;
        for(auto ii:adj[u])
        {
            int v=ii.first;
            int w=ii.second;
            if(dist[v]>dist[u]+w && visit[v]==0)
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(i=0;i<n;i++)
        cout<<i<<"   "<<dist[i]<<endl;
}
int main()
{
    int n,st,ed,e,i,wt;
    cout<<"Enter the no of vertices"<<endl;
    cin>>n;
    vector<p> adj[n];
    cout<<"Enter the no of edges"<<endl;
    cin>>e;
    for(i=0;i<e;i++)
    {
        //cout<<"Enter the start"<<i+1<<endl;
        cin>>st;
        //cout<<"Enter the end"<<i+1<<endl;
        cin>>ed;
        //cout<<"Enter the weight"<<i+1<<endl;
        cin>>wt;
        adj[st].push_back(make_pair(ed,wt));
        adj[ed].push_back(make_pair(st,wt));
    }
    djikstra(adj,0,n);
}