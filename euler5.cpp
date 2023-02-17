#include <numeric>
#include <iostream>
 
#define OUT(...) std::cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'

using namespace std;

int llcm(int head, int tail) {
    return lcm(head,tail);
}

template<typename T, typename ... Types>
int llcm(T head, Types ...tail) {
    return lcm(head,llcm(tail...));
}

int main() {
    

    OUT(llcm(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20));
    return 0;
}