#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int big(int a, int b) {
    return a > b ? a : b;
}
int small(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int a, b;
    cin>>a>>b;
    int diff = abs(a - b);
    int quotient;
    if(a != 0 and b != 0) {
        quotient = big(a, b) / small(a, b);
    }
    else {
        quotient = 0;
    }

    int gcd_ans = gcd(diff, quotient);

    cout<<gcd_ans<<endl;
}
