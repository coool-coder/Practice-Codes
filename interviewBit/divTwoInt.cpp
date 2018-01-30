#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long quotient = 0;
    long long dividend;
    long long divisor;

    cin >> dividend;
    cin >> divisor;

    int sign = dividend < 0 ^ divisor < 0 ? -1 : 1;

    divisor = abs(divisor);
    // dividend = abs(dividend);

    if(dividend == INT_MIN)
        dividend = INT_MAX;
    else
        dividend = abs(dividend);
    
    
    // cout << divisor << " " << dividend << endl;
    // while(dividend >= divisor)
    // {
    //     // cout << "entered "; 
    //     dividend -= divisor;
    //     quotient++;
    // }
    cout << 1LL << endl;
    for (long long t = 0, i = 31; i >= 0; i--){
        if (t + (m << i) <= n){
            t += m << i, quotient |= 1LL << i;
            // cout << quotient << " ";
        }
    }
    cout << endl;

    // cout << endl;
    if (sign < 0) quotient = -quotient;
    
    quotient =  quotient >= INT_MAX || quotient < INT_MIN ? INT_MAX : quotient;
        
    cout<<"Quotient = "<<quotient<<"\nRemainder = "<<dividend<<endl;
    return 0;
}