#include<iostream>
#include<set>
#include<vector>

std::set<int> primes;
bool isPrime(int num) {
    if (num <= 1)
        return false;

    if (primes.find(num) != primes.end())
        return true;

    for (int i = 2; i*i <= num; i++) {
        if (num%i == 0)
            return false;
    }

    primes.insert(num);
    return true;
}

int quad(int num, int a, int b) {
    return num*num + a*num + b;
}

int main() {
    int limit = 1000;
    unsigned int max_length = 0;
    int best_a;
    int best_b;

    for (int a = -limit; a <= +limit; a++) {
        for (int b = -limit; b <= +limit; b++) {
            unsigned int length = 0;
            while(isPrime(length * length + a * length + b)) {
                length++;
            }
            if (length > max_length) {
                max_length = length;
                best_a = a;
                best_b = b;
            }          
        }
        //std::cout << "a:" << a << std::endl;
    }

    std::cout << best_a * best_b;
}