#include<iostream>
#include<vector>
#include<math.h>

std::vector<int> factors(int number){
    std::vector<int> result;
    
    for (int i = 1; i < sqrt(number); i++) {
        if (number%i == 0) {
            result.push_back(i);
            result.push_back(number/i);
        }
    }
    return result;
}

int sumVector(std::vector<int> vec) {
    int sum = 0;
    for (int n : vec) 
        sum += n;

    return sum;
}

int sumOfProperDivisors(int num) {
    return sumVector(factors(num))-num;
}

void printVector(std::vector<auto> vec) {
    std::cout << "{";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}

bool isAmicable(int a, int b) {
    return a != b && sumOfProperDivisors(a) == b && sumOfProperDivisors(b) == a; 
}

int main() {

    int sum_amicable = 0;

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            if (isAmicable(i,j)) {
                sum_amicable += (i+j);
                std::cout << i << " and " << j << std::endl;
            }
        }
    }
    std::cout << sum_amicable << "/2 = " << sum_amicable/2 << std::endl;
}