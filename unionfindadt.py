graph={}
v=int(input("No of Vertex:"))
for i in range(v):
    graph[i]=[]
n=int(input("No of edges:"))
print('vertices connected by edges :')
for i in range(n):
    x,y=map(int,input().split())
    graph[x].append(y)
parent=[-1]*v
f=0
def find(x):
    if(parent[x]==-1):
        return x
    return find(parent[x])
for i in graph:
    for j in graph[i]:
        x=find(i)
        y=find(j)
        if(x==y):
            f=1
            break
        parent[find(x)]=find(y)
if(f):
    print("Cycle is detected")
else:
    print("No Cycle")
