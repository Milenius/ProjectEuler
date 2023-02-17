#include<vector>
#include<algorithm>
#include<iostream>

void print(const std::vector<int>& v)
{
    for (int e : v) {
        std::cout << "" << e;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    // vector should be sorted at the beginning.
    int index = 1;
    do {
        if (index == 1000000)
            print(v);
        index++;
    } while (std::next_permutation(v.begin(), v.end()));
}