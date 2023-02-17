#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

int getHundred(int number) {
    return (number/100)%10;
}

int getTens(int number) {
    return (number/10)%10;
}

int getDigit(int number) {
    return number%10;
}

const string digits[] = {
    "zero", "one", "two", "three", "four", "five","six", "seven", "eight", "nine"
};

const string tens[] = {
    "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"
};

const string decades[] = {
    "", "", "twenty", "thirty", "forty","fifty", "sixty", "seventy", "eighty", "ninety"
};

string numberToWord(int number) {
    int d1,d2,d3; //Hundred Digit, Tens Digit, last Digit
    d1 = getHundred(number);
    d2 = getTens(number);
    d3 = getDigit(number);

    string result = "";

    if (number == 1000)
        return "onethousand";

    if (d1 != 0) {
        result += digits[d1] + "hundred";
        if (d2 != 0 || d3 != 0)
            result += "and";
    }
    if (d2 != 0) {
        if (d2 == 1) {
            result += tens[d3];
            return result;
        }
        result += decades[d2];
    }
    if (d3 != 0)
        result += digits[d3];

    return result;
}


int main() {
    string word;
    int num_letters = 0;

    for (int i = 1; i <= 1000; i++) {
        word = numberToWord(i);
        cout << word << endl;
        num_letters += word.size();
    }
    

    cout << num_letters;
}