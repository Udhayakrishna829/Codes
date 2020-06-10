#include<bits/stdc++.h>

using namespace std;

int count_subset(int set[],int set_size,int val)

{

    int count=0;

    int t=pow(2,set_size);

    for(int x=0;x<=t;x++)

    {

        int prod=1;

        for(int k=0;k<set_size;k++)

        {

            if(x&(1<<k))

                prod*=set[k];

        }

        if(prod<val)

            count+=1;

    }

    return count;

}

int main()

{

    int set[]={4,8,7,2};

    int v=count_subset(set,4,50);

    cout<<v;

}
