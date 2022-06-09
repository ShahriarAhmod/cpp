#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int Wi, price;
} item;

int zeroOneKnapsack(item x[], int n, int capacity)
{
    int i,j,mat[n+1][capacity+1],temp,capTemp;
    set<int> s;

    for (i=0; i<=n; i++)
    {
        mat[i][0]=0;
    }
    for (j=0; j<=capacity; j++)
    {
        mat[0][j]=0;
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=capacity; j++)
        {
            if(x[i].Wi>j)
            {
                mat[i][j]=mat[i-1][j];
            }
            else
            {
                mat[i][j]= max(mat[i-1][j], mat[i-1][j-x[i].Wi] + x[i].price);
            }
        }
    }

    temp = mat[n][capacity];
    capTemp = capacity;

    for (i=n; i>0 && temp>0; i--)
    {
        if (temp==mat[i-1][capTemp])
        {
            continue;
        }
        else
        {
            s.insert(i);
            temp -=x[i].price;
            capTemp -= x[i].Wi;
        }
    }
    cout << endl;
    return mat[n][capacity];
}

int main()
{
    int i,n,capacity;
    cout << "Number of items: ";
    cin >> n;
    cout << "Enter the weight and price:\n";

    item x[n];

    for(i=1; i<=n; i++)
    {
        cin >> x[i].Wi;
        cin >> x[i].price;
    }

    cout << "Enter the capacity : ";
    cin >> capacity;

    int result = zeroOneKnapsack(x,n,capacity);
    cout << "The Maximum Profit Is : " << result << endl;

    return 0;
}
