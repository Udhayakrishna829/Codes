import sys
def prims(g):
    cost=0
    spt=[0 for i in range(len(g))]
    spt=[spt[:] for i in range(len(g))]
    mstedge=1
    visit=[1]
    fro=[0]
    dist=[0]
    for i in range(1,len(g)):
        if g[0][i]==0:
            dist.append(sys.maxsize)
        else:
            dist.append(g[0][i])
        fro.append(0)
        visit.append(0)
    while(mstedge<len(g)):
        mindis=sys.maxsize
        for i in range(1,len(visit)):
            if visit[i]==0 and dist[i]<mindis:
                v=i
                mindis=dist[i]
        u=fro[v]
        spt[u][v]=spt[v][u]=dist[v]
        mstedge+=1
        visit[v]=1
        for i in range(1,len(visit)):
            if visit[i]==0 and g[i][v]!=0 and g[i][v]<dist[i]:
                dist[i]=g[i][v]
                fro[i]=v
        cost+=g[u][v]
    for i in range(len(g)):
        print(spt[i])
    print(cost)
if __name__ == '__main__':
    '''n=int(input('Enter the no of vertices : '))
    g=[]
    g=[g for i in range(n)]
    print(g)                            #for user input
    for i in range(n):
        print('Enter the data for {} row'.format(i+1))
        for j in range(n):
            g[i].append(int(input()))'''
    g=[ [0, 2, 0, 6, 0], 
	    [2, 0, 3, 8, 5], 
		[0, 3, 0, 0, 7], 
		[6, 8, 0, 0, 9], 
		[0, 5, 7, 9, 0]] 
    prims(g)
