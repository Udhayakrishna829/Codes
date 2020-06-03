from collections import Counter as c
for i in range(int(input())):
    s=input()
    k=c(s).values()
    if(max(k)>1):
        print("Yes")
    else:
        print("No")
