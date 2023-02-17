#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

bool isPalindrome(int n){
    stringstream ss;
    ss << to_string(n);

    vector<char> digits;
    char c;
    while(ss >> c) 
    {
        digits.push_back(c);
    }
    for (size_t i = 0; i < digits.size(); i++)
    {
        if (digits[digits.size()-1-i] == digits[i])
        {
            //digits.pop_back();
        } else 
        {
            return false;
        }
        
    }
    return true;
}

int max(vector<int> v) {
    int top = INT_MIN;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] > top)
        {
            top = v[i];
        }
        
    }
    return top;
}

int main() {
    int temp;
    vector<int> v;

    for (size_t i = 999; i>100; i--)
    {
        for (size_t j = 999; j>100 ; j--)
        {
            temp = i*j;
            if (isPalindrome(temp))
            {
                v.push_back(temp);
            }
            
        }
    }
    cout << max(v) << endl;
    return 0;
}