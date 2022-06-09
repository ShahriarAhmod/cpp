#include <bits/stdc++.h>
using namespace std;

bool cPrime(int n)
{
  if(n == 1) {
    return false;
  }
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
    cin>>n;
    int sum = 0;
    vector<int> v;
  for(int i = 2; i <= n; i++) {

        bool isPrime = cPrime(i);

        if(isPrime == true) {
            sum = sum + i;
            v.push_back(i);
        }

    }

    cout<<"Prime numbers: ";
    for(auto u : v) {
        cout<<u<<" ";
    }
    cout<<endl;
    cout<<"Sum of prime numbers: "<<sum<<endl;
}
