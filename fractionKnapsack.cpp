#include <iostream>
using namespace std;

typedef struct
{
    double weight,price,ratio;
} item;

double fractionalKnapsack(item x[], int n, int capacity)
{
    int i,j;
    double temp;
    double profit=0;

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(x[j].ratio<x[j+1].ratio)
            {
                temp = x[j].ratio;
                x[j].ratio = x[j+1].ratio;
                x[j+1].ratio = temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(x[i].weight<=capacity)
        {
            profit+=x[i].price;
            capacity-=x[i].weight;
        }
        else
        {
            profit+=x[i].ratio*capacity;
            break;
        }
    }

    return profit;
}

int main()
{
    int i,n,capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    item x[n];

    for(i=0; i<n; i++)
    {
        cin >> x[i].weight;
        cin >> x[i].price;
        x[i].ratio = x[i].price/x[i].weight;
    }

    cout << "Enter the capacity of Knapsack : ";
    cin >> capacity;

    cout << fractionalKnapsack(x,n,capacity);

    return 0;
}
