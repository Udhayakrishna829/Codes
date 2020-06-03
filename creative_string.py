from collections import Counter as c

n,m=map(int,input().split())

def fun(d):
    a=d.most_common(1)[0]
    x=a[0]
    a=a[1]
    for i in d.keys():
        if(d[i]==a):
            x=min(x,i)
    return x

l=[]
for i in range(n):
    l.append(input())
k=[]
for i in range(m):
    k.append([])
for i in range(n):
    for j in range(m):
        k[j].append(l[i][j])
s=''
for i in range(m):
    k[i]=c(k[i])
    s+=fun(k[i])
print(s)
