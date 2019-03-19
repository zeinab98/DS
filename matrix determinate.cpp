#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void getConfactor(int **a,int **temp,int p,int q,int n)
{
    int row=0,col=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=p && j!=q)
            {
                temp[row][col++]=a[i][j];


                if(col==n-1)
                {
                    col=0;
                    row++;
                }
            }
        }
    }
}
int det(int **a,int n)
{
    int sum=0,sign=1;
    /////////////////////for storing Confactor
    int **temp=new int*[n];
    for(int i=0;i<n;i++)
        temp[i] = new int[n];

    if(n==1)
        return a[0][0];

    else if(n==2)
        return(a[0][0]*a[1][1]-a[0][1]*a[1][0]);

    else
        for(int r=0;r<n;r++)
        {
            getConfactor(a,temp,0,r,n);
            sum=sum+a[0][r]*sign*det(temp,n-1);
            sign=-sign;
        }

    return sum;
}
void dispaly(int **a,int n)
{
     for(int i=0;i<n;i++)
     {

        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
     }
}

int main()
{
    srand(time(0));
    int a,b,answer;
    int n;
    cout<<"N : "<<endl;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i] = new int[n];
    cout<<"How do you want to fill array ?"<<endl;
    cout<<"1. random by Computers"<<endl;
    cout<<"2. by user "<<endl;
    cout<<"Enter answer :"<<endl;
    cin>>answer;
    if(answer == 2)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cout<<"Enter a number :"<<endl;
                cin>>arr[i][j];

            }

    if(answer==1)
    {
        cout<<"Random numbers are between a and b "<<endl;
        cout<<"Enter a :"<<endl;
        cin>>a;
        cout<<"Enter b :"<<endl;
        cin>>b;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                arr[i][j]=a+rand()%(b-1);

            }
    }
    cout<<"---------------------------"<<endl;
    dispaly(arr,n);
    cout<<"---------------------------"<<endl;
    cout<<"Determinate :"<<endl;
    cout<<det(arr,n);

}
