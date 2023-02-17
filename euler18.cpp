#include<iostream>
#include<sstream>
#include<vector>
#include<string>

std::string input = "75 95 64 17 47 82 18 35 87 10 20 04 82 47 65 19 01 23 75 03 34 88 02 77 73 07 63 67 99 65 04 28 06 16 70 92 41 41 26 56 83 40 80 70 33 41 48 72 33 47 32 37 16 94 29 53 71 44 65 25 43 91 52 97 51 14 70 11 33 28 77 73 17 78 39 68 17 57 91 71 52 38 17 14 91 43 58 50 27 29 48 63 66 04 68 89 53 67 30 73 16 69 87 40 31 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";
std::string test = "3 7 4 2 4 6 8 5 9 3 ";

int getMax(std::vector<std::vector<int>> vec, int y, int x) {
    if (y == 14)
        return vec[y][x];
    
    int left = getMax(vec,y+1,x);
    int right = getMax(vec,y+1,x+1);
    
    if (left > right) {
        return left+vec[y][x];
    } else {
        return right+vec[y][x];
    }
}

int main() {
    std::vector<std::vector<int>> numbers;
    std::vector<int> temp;
    std::stringstream ss;

    int cur_num;
    int j = 1;

    ss << input;

    while (ss >> cur_num) {
        temp.push_back(cur_num);

        for (int i = 1; i < j; i++) {
            ss >> cur_num;
            temp.push_back(cur_num);
        }
        numbers.push_back(temp);
        temp.erase(temp.begin(),temp.end());
        j++;
    }

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << getMax(numbers,0,0);
}