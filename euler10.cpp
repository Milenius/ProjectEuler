#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(const int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    vector<int> v;
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {

            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (size_t i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            v.push_back(i);
        }
        
    }
    return v;
}

int main(){
    vector<int> primes = sieve(2000000);
    long long sum = 0;
    for (size_t i = 0; i < primes.size(); i++)
    {
        sum += primes[i];
    }
    
    cout << sum << endl;

    return 0;
}