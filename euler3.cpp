#include <iostream>
#include <vector>

using namespace std;

vector<long> primfaktoren(long long n) {
    vector<long> faktoren;
    long p = 2;
    if (n == 1)
    {
        return faktoren;
    }
    
    while (p*p <= n)
    {
        if (n%p == 0)
        {
            faktoren.push_back(p);
            n /= p;
        } else 
        {
            p++;
        }
    }
    faktoren.push_back(n);

    return faktoren;
}

int main() {
    vector<long> v = primfaktoren(1000);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}