#include<vector>
#include<math.h>
#include<iostream>
#include<algorithm>

std::vector<int> factors(int number){
    std::vector<int> result;
    
    for (int i = 2; i*i <= number; i++) {
        if (number%i == 0) {
            result.push_back(i);
            if (i != number/i)
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
    return sumVector(factors(num));
}

void printVector(std::vector<auto> vec) {
    std::cout << "{";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}

bool isAbundant(int num) {
    return (sumOfProperDivisors(num)>num);
}

std::vector<int> getAbundantNums(int num) {
    std::vector<int> vec;
    for (int i = 0; i <= num; i++) {
        if (isAbundant(i))
            vec.push_back(i);
    }
    return vec;
}

bool isAbundantSum(int num, std::vector<int> vec) {
    int other;
    
    if (num >= 28123)
        return true;

    for (int i : vec) {
        if (i > num)
            return false;
        
        other = num-i;
        if (isAbundant(other))
            return true;
    }

    return false;
}

int main() {
    std::vector<int> abundant_nums = getAbundantNums(28123);
    std::vector<int> abundant_sum_map;
    int temp;

    /*
    for (size_t i = 0; i < abundant_nums.size(); i++) {
        for (size_t j = i; j < abundant_nums.size(); j++) {
            temp = abundant_nums[i]+abundant_nums[j];
            if (temp<28123)
                abundant_sum_map.push_back(temp);
        }
    }

    std::sort(abundant_sum_map.begin(),abundant_sum_map.end());
    abundant_sum_map.erase(std::unique(abundant_sum_map.begin(),abundant_sum_map.end()),abundant_sum_map.end());
    */

    int index = 0;
    long long sum = 0;
    
    for (int i = 0; i < 28123; i++) {
        if (!isAbundantSum(i, abundant_nums)) {
            sum += i;
            std::cout << i << std::endl;
        }
    }

    std::cout << "finish:" << sum << std::endl;
}