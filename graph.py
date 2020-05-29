'''graph = {1: [],
         2: [4, 6, 8, 10, 12, 14, 16, 18, 20],
         3: [6, 9, 12, 15, 18],
         4: [2],
         5: [10, 15, 20],
         6: [2, 3],
         7: [14],
         8: [2],
         9: [3],
         10: [2, 5],
         11: [],
         12: [2, 3],
         13: [],
         14: [2, 7],
         15: [3, 5],
         16: [2],
         17: [],
         18: [2, 3],
         19: [],
         20: [2, 5]}'''
'''---------input-----------
10
9
0 1
1 2
1 6
2 9
2 4
2 3
4 5
6 7
6 8
----------------------------'''


graph={}
v=int(input("No of Vertex:"))
for i in range(v):
    graph[i]=[]
n=int(input("No of edges:"))
print('vertices connected by edges :')
for i in range(n):
    x,y=map(int,input().split())
    graph[x].append(y)
    graph[y].append(x)

def find_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in graph.keys():
        return None
    for node in graph[start]:
        if node not in path:
            newpath = find_path(graph, node, end, path)
            if newpath: return newpath
    return None
def find_all_paths(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return [path]
    if start not in graph.keys():
        return []
    paths = []
    for node in graph[start]:
        if node not in path:
            newpaths = find_all_paths(graph, node, end, path)
            for newpath in newpaths:
                paths.append(newpath)
    return paths
def find_shortest_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if start not in graph.keys():
        return None
    shortest = None
    for node in graph[start]:
        if node not in path:
            newpath = find_shortest_path(graph, node, end, path)
            if newpath:
                if not shortest or len(newpath) < len(shortest):
                    shortest = newpath
    return shortest

def find_longest_path(graph, start, end, path=[]):
    path = path + [start]
    if start not in graph.keys():
        return None
    longest = None
    for node in graph[start]:
        if node not in path:
            newpath = find_shortest_path(graph, node, end, path)
            if newpath:
                if not longest or len(newpath) > len(longest):
                    longest = newpath
    if(longest==None):
        if(start==end):
            return path
    else:
        return longest
def length_of_longest_path(s,e):
    return len(find_longest_path(graph,s,e))-1
def length_of_shortest_path(s,e):
    return len(find_shortest_path(graph,s,e))-1
def find_all_shortest_path(graph):
    l=[]
    for i in range(n-1):
        for j in range(i+1,n):
            l.append(find_shortest_path(graph,i,j))
    return l
def find_overall_shortest_path(graph):
    l=graph.keys()
    for i in range(n-1):
        for j in range(i+1,n):
            k=find_shortest_path(graph,i,j)
            if(len(k)<len(l)):
                l=k
    return l
def length_of_overall_shortest_path():
    return len(find_overall_shortest_path(graph))-1
def find_all_longest_path(graph):
    l=[]
    for i in range(n-1):
        for j in range(i+1,n):
            l.append(find_longest_path(graph,i,j))
    return l
def find_overall_longest_path(graph):
    l=[]
    for i in range(n-1):
        for j in range(i+1,n):
            k=find_longest_path(graph,i,j)
            if(len(k)>len(l)):
                l=k
    return l
def length_of_overall_longest_path():
    return len(find_overall_longest_path(graph))-1

print("___________________________")
print("Length of Shortest path in the graph :",length_of_overall_shortest_path())
print("Shortest path in the graph :",find_overall_shortest_path(graph))
print("___________________________")
print("Length of Longest path in the graph :",length_of_overall_longest_path())
print("Longest path in the graph :",find_overall_longest_path(graph))
