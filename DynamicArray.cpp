#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"] : ";
        cin>>a[i];

    }

    cout<<"Array = ";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";



    return 0;
}
