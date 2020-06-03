for _ in range(int(input())):
    x,y=[],[]
    for i in range(int(input())):
        a,b=map(int,input().split())
        x.append(a)
        y.append(b)
    x=max(x)-min(x)
    y=max(y)-min(y)
    print(max(x,y)**2)
