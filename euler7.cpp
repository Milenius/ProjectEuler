#include<iostream>
#include<vector>

using namespace std;

vector<long> sieveTo(long n) {
    vector<long> v;
    v.push_back(2L);
    long p = 3;
    while (v.size() <= n)
    {
        
        bool flag = true;
        for (size_t i = 2; i < p; i++)
        {
            if (p%i == 0)
            {
                flag = false;
            } 
        }
        if (flag)
        {
            v.push_back(p);
            cout << p << " ";
        }
        p++;
    }
    return v;
}

int main() {

    vector<long> v = sieveTo(10001);

    cout << v.size() << endl << "done";
    return 0;
}