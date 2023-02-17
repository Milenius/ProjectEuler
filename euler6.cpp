#include<iostream>

using namespace std;

int main() {
    int sumSqr = 0;
    int sqrSum = 0;

    int target = 100;

    for (int i = 0; i <= target; i++)
    {
        sumSqr += i*i;
        sqrSum += i;
    }

    sqrSum *= sqrSum;

    cout << sumSqr << " " << sqrSum << " " << sqrSum-sumSqr;
    
    return 0;
}