#include<iostream>
#include<vector>
#include<algorithm>

int getDigit(int number, int position) {
    return (number/position)%10;
}

std::vector<int> add2Vector(std::vector<int> vec_a, std::vector<int> vec_b) {
    int carry = 0; 
    int digit = 0;
    int a = 0,b = 0;
    std::vector<int> vec;

    if (vec_a.size() < vec_b.size())
        std::swap(vec_a, vec_b);


    std::reverse(vec_a.begin(),vec_a.end());
    std::reverse(vec_b.begin(),vec_b.end());

    for (int i = 0; i < vec_a.size(); i++) {
        a = vec_a[i];

        if (i < vec_b.size()) {
            b = vec_b[i];
            digit = a+b;
            digit += carry;
        } else {
            a = vec_a[i];
            digit = a+carry;
        }
                
        if (digit >= 10) {
            carry = 1;
            digit -= carry*10;    
        } else {
            carry = 0;
        }
        vec.push_back(digit);
    }
    if (carry)
        vec.push_back(carry);

    std::reverse(vec_a.begin(),vec_a.end());
    std::reverse(vec_b.begin(),vec_b.end());
    std::reverse(vec.begin(),vec.end());
    return vec;
}

void printVector(std::vector<auto> vec) {
    std::cout << "{";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}

int bigFiboDigit(int digits) {
    std::vector<int> vec;

    std::vector<int> a = {1};
    std::vector<int> b = {1};

    int index = 2;

    while (vec.size() < digits) {
        vec = add2Vector(a,b);
        a = b;
        b = vec;
        index++;
    }

    return index;
}

int main() {
   std::cout << bigFiboDigit(1000);
}