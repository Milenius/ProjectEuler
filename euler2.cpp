#include<iostream>
#include<vector>

using namespace std;

int main() {

    const size_t target = 4000000;

    int a = 1;
    int b = 2;
    int temp;
    int sum = 0;

    while ((size_t)b < target)
    {
        //cout << b << " ";
        if (b%2 == 0)
        {
            sum += b;
        }
        temp = b;
        b = a+b;
        a = temp;
    }
    
    cout << sum << endl;

    return 0;
}