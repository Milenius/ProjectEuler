#include<iostream>
#include<vector>
#include<algorithm>

int getDigit(int number, int position) {
    return (number/position)%10;
}

std::vector<int> multiplyVectorRaw(std::vector<int> vec, int factor) {
    int carry, digit = 0;
    
    for (int i = 0; i < vec.size(); i++) {
        int n = vec[i];

        digit = n*factor;
        digit += carry;
        if (digit >= 10) {
            carry = digit - getDigit(digit,1);
            digit -= carry;
            carry /= 10;     
        } else {
            carry = 0;
        }
        vec[i] = digit;
    }

    while (carry) {
        vec.push_back(getDigit(carry,1));
        carry /= 10;
    }
        
    return vec;
}

std::vector<int> bigFactorial(int factorial) {
    std::vector<int> number = {factorial};
    
    for (int i = 1; i < factorial; i++) {
        number = multiplyVectorRaw(number, factorial-i);
    }

    std::reverse(number.begin(), number.end());

    return number;
}

int sumVector(std::vector<int> vec) {
    int sum = 0;
    for (int n : vec) 
        sum += n;

    return sum;
}

int main() {
    std::vector<int> number = bigFactorial(100);    

    

    for (int n : number)
        std::cout << n << "";
    std::cout << std::endl;

    std::cout << sumVector(number);
}