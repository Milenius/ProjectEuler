#include<iostream>

int steps(int x, int y, int width, int height){
    if (x == width && y == height)
        return 1;
    
    if (x > width || y > height)
        return 0;

    if (x >= width)
        return steps(x, y+1, width, height);

    if (y >= height)
        steps(x+1, y, width, height);

    return steps(x+1, y, width, height) + steps(x, y+1, width, height);
}

int main(){
    std::cout << steps(0,0,20,20);//Needs to long, just calculate (40 20) binomial

    
}