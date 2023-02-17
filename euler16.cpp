#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> doubleVector(std::vector<int> vec) {
    int carry, digit = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        int n = vec[i];

        digit = n*2;
        digit += carry;
        if (digit >= 10) {
            digit -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        vec[i] = digit;
    }

    if (carry)
        vec.push_back(carry);

    return vec;
}

int sumVector(std::vector<int> vec) {
    int sum = 0;
    for (int n : vec) 
        sum += n;

    return sum;
}

int main(){
    std::vector<int> number = {2};
    int exponent = 1000;


    for (int i = 1; i < exponent; i++) {
        number = doubleVector(number);
    }
    

    std::reverse(number.begin(), number.end());

    for (int n : number)
        std::cout << n << " ";
    std::cout << std::endl;

    std::cout << sumVector(number);
}