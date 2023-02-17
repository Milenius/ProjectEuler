#include<iostream>

int main() {
    int size = 1001;

    int pauses = 1;
    int current = 1;
    int sum = 1;
    int max_ring = (size-1)/2;

    for (int ring = 0; ring < max_ring; ring++) {
        for (int i = 0; i < 4; i++) {
            current += ring*2 + 2;
            sum += current;    
        }
    }

    std::cout << sum;
}