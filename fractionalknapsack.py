def knapsack(w,v,c):
    di={}
    val=0
    for i in range(len(w)):
        a,b=v[i],w[i]
        di[a/b]=[a,b]
    for i in reversed(sorted(di.keys())):
        if di[i][1]<=c:
            c-=di[i][1]
            val+=di[i][0]
        else:
            val+=i*c
            c=0
            return val

if __name__ == '__main__':
    n=int(input('Enter the number of items  '))
    v,w=[],[]
    for i in range(n):
        v.append(int(input('Enter the value ')))
        w.append(int(input('Enter the weight ')))
    c=int(input('Enter the capacity '))
    print(knapsack(w,v,c))

