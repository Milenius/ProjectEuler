#include<iostream>

int colatz(int input) {
    while (input != 1) {
        if (input%2 == 0) {
            input /= 2;
        } else {
            input = 3*input + 1;
        }
    }
    return input;
}

long colatzLength(long long input) {
    long length = 0;
    while (input > 1) {
        if (input%2 == 0) {
            input = input/2;
        } else {
            input = 3*input + 1;
        }
        length++;
    }
    return length;
}

int main() {
    long max_length = LONG_MIN;
    long max_input = 0;
    long length;
    for (long i = 1; i < 1000000; i++) {
        length = colatzLength(i);
        if (length >= max_length) {
            max_length = length;
            max_input = i; 
            std::cout << i << std::endl; 
        }  
            
    }
    std::cout << max_input << " " << max_length << std::endl;
}