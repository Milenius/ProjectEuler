#include<iostream>

using namespace std;


// m^2 + m*n = 500 search for m & n
int main() {
    float m = 0;
    float n = 1;

    while (n>=m || n != (int)n)
    {
        m++;
        n = (500-m*m)/m;
    }
    cout << m << ">" << n << ">" << 0 << endl;
    
    int a = m*m - n*n;
    int b = 2*m*n;
    int c = m*m + n*n;
    
    cout << b*b << ">" << a*a << ">" << c*c << "=" << a*a+b*b << endl;
    cout << a*b*c << " " << a+b+c;

    return 0;
}