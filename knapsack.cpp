#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int weight,price;
} item;

int zeroOneKnapsack(item x[], int n, int capacity)
{
    int i,j,mat[n+1][capacity+1],temp,capTemp;
    set<int> s;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=capacity; j++)
        {
            mat[i][j]=0;
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=capacity; j++)
        {
            if(x[i].weight>j)
            {
                mat[i][j]=mat[i-1][j];
            }
            else
            {
                mat[i][j]= max(mat[i-1][j], mat[i-1][j-x[i].weight] + x[i].price);
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
            capTemp -= x[i].weight;
        }
    }

    set<int>::iterator itr;

    cout << "\nSelected items are: ";
    for(itr=s.begin(); itr!=s.end(); itr++)
    {
        cout << *itr <<" ";
    }
    cout << endl;
    return mat[n][capacity];
}

int main()
{
    int i,n,capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter weight first then the price\n";

    item x[n];

    for(i=1; i<=n; i++)
    {
        cin >> x[i].weight;
        cin >> x[i].price;
    }

    cout << "Enter the capacity of Knapsack: ";
    cin >> capacity;

    int result = zeroOneKnapsack(x,n,capacity);
    cout << "Profit: " << result;
    cout << endl;

    return 0;
}
