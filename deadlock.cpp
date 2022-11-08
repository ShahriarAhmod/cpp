#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>available(m);
    ll allocation[n][m],request[n][m],need[n][m];
    ll finish[n];
    for(int i=0; i>n; i++)
    {
        finish[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        cin>>available[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>allocation[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            ll d=0;
            cin>>request[i][j];
            need[i][j]=max(d,request[i][j]-allocation[i][j]);
            //cout<<need[i][j]<<" ";
        }
        //cout<<endl;
    }
    int tot=0;
    vector<ll>v;
    while(1)
    {
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            ll ok=1;
            if(finish[i]==1)continue;
            for(int j=0; j<m; j++)
            {
                ok&=(need[i][j]<=available[j]);
            }
            //cout<<ok<<endl;
            //cout<<i<<endl;
            if(ok)
            {
                v.push_back(i+1);
                cnt++;
                tot++;
                finish[i]=1;
                for(int j=0; j<m; j++)
                {
                    available[j]+=allocation[i][j];
                }
            }
        }

        if(cnt==0)
        {
            if(tot==n)
            {
                cout<<"Safe State"<<endl;
                for(int i=0; i<v.size(); i++)
                {
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else
            {
                cout<<"DeadLock"<<endl;
            }
            break;
        }
    }
}
/*
5 3
3 3 2
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1*/