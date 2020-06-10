#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
    int i,j,lis[n];
    for(i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(arr[i]>arr[j])
                lis[i]=max(lis[i],lis[j]+1);
    sort(lis,lis+n);
    return lis[n-1];
}
int main()
{
    int arr[]={10,22,9,33,21,50,41,60};
    cout<<lis(arr,8);
}
