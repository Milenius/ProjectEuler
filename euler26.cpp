#include<iostream>
#include<vector>
#include<set>

bool isReciprocal(int num) {
    std::vector<int> digits = {0};
    std::set<int> dividends;
    int dividend = 1;

    for (int i = num; i > 0; i--) {
        dividends.insert(dividend);
        dividend = (dividend%num) * 10;
        if (dividends.find(dividend) != dividends.end()) {
            if (dividend == 0) {
                return false;
            } else {
                return true;
            }
        }
        digits.push_back(dividend/num); 
    }

    if (digits[digits.size()-1] == 0)
        digits.pop_back();

    return false;;
}

std::vector<int> getReciprocal(int num) {
    std::vector<int> digits = {0};
    std::set<int> dividends;
    int dividend = 1;

    for (int i = num; i > 0; i--) {
        dividends.insert(dividend);
        dividend = (dividend%num) * 10;
        if (dividends.find(dividend) != dividends.end()) {
            continue;
        }
        digits.push_back(dividend/num); 
    }

    if (digits[digits.size()-1] == 0)
        digits.pop_back();

    return digits;;
}

void printVector(std::vector<auto> vec) {
    std::cout << "{";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
}


int main() {
    std::vector<int> num;
    int length = 0;
    int longest = 0;
    for (int i = 0; i < 1000; i++) {
        if (isReciprocal(i)) {
            num = getReciprocal(i);
            if (num.size() > length) {
                length = num.size();
                longest = i;
            }
                
        }
    }
    std::cout << longest;
}