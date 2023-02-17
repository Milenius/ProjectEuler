#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>

void printVector(std::vector<long long> vec) {
    std::cout << "{";
    for (long long x : vec)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}

int main() {
    int limit = 10;
    std::vector<long long> combinations;

    for (int a = 2; a <= limit; a++) {
        for (int b = 2; b <= limit; b++) {
            combinations.push_back(std::pow(a,b));
        }
    }

    std::sort(combinations.begin(),combinations.end());
    combinations.erase(std::unique(combinations.begin(),combinations.end()),combinations.end());

    printVector(combinations);
    std::cout << combinations.size();
}