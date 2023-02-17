#include<iostream>
#include<vector>
#include<sstream>

#include<math.h>

std::vector<int> factors(int number){
    std::vector<int> result;

    int square_root = sqrt(number);
    
    for (int i = 1; i < square_root; i++) {
        if (number%i == 0) {
            result.push_back(i);
            result.push_back(number/i);
        }
    }
    return result;
}

std::vector<long> primfaktoren(long n) {
    std::vector<long> faktoren;
    long p = 2;
    if (n == 1)
    {
        return faktoren;
    }
    
    while (p*p <= n)
    {
        if (n%p == 0)
        {
            faktoren.push_back(p);
            n /= p;
        } else 
        {
            p++;
        }
    }
    faktoren.push_back(n);

    return faktoren;
}

long triangleNum(long num) {
    long res = 0;
    for (long i = 1; i <= num; i++)
    {
        res += i;
    }
    return res;
}

int main(){
    long number = 10;
    long prime = 2;
    long cur_exponent = 0;
    long result = 1;
    std::vector<long> exponents; 
    std::vector<long> test;

    
    

    while (result <= 500) {
        result = 1;
        test = primfaktoren(triangleNum(number));
        prime = test[0];
        cur_exponent = 1;
        
        exponents.erase(exponents.begin(),exponents.end()); 

        for (size_t i = 1; i < test.size(); i++) {
            if (prime == test[i]){
                cur_exponent++;
            } else {
                exponents.push_back(cur_exponent);
                cur_exponent = 1;
                prime = test[i];
            }
            
        }
        exponents.push_back(cur_exponent);

        for (size_t i = 0; i < exponents.size(); i++) {
            result *= (exponents[i]+1);
        }

        
        if (result > 500) {
            std::cout << triangleNum(number) << std::endl;
            std::cout << result << std::endl << std::endl;
        }
        
        number++;
    }
    
    
}