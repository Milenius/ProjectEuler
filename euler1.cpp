#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const size_t n = 1000;
      
    vector<int> v;

    for (int i = 1; i < n; i++) {
        if (i % 5 == 0) {
            v.push_back(i);
        } else if (i % 3 == 0) {
            v.push_back(i);
        }
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    cout << sum;
}