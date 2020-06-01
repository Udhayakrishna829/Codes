#include<bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(vector <int> parent,int x){
    if(parent[x]==-1)
        return x;
    return find(parent,parent[x]);
}
main(){
	int v,n,x,y;
	cin>>v;
	cin>>n;
	vector<int> a[v];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[x].push_back(y);
	}
	for(int i=0;i<v;i++){
		parent.push_back(-1);
	}
	int f=0;
	
	for(int i=0;i<v;i++){
	    for(int j=0;j<a[i].size();j++){
	        x=find(parent,i);
	        y=find(parent,a[i][j]);
	        if(x==y){
	        	cout<<x<<y;
	            f=1;
	            break;
	        }
	        parent[find(parent,x)]=find(parent,y);
	    }
	}
	if(f)
	    cout<<"Cycle is detected";
	else
	    cout<<"No Cycle";
	
}
