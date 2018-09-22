#include<iostream>

class Point{
public:
    int x;
    int y;
};

class Square{
public:
    Point points[4];
};

bool isLessThanLine(Point& p1, Point& p2, Point& p){
    if(getLineFuctionValue(p1.x, p2.x, p1.y, p2.y, p.x) >= p.y) return true;
    else return false;
}

double getLineFuctionValue(int x1, int x2, int y1, int y2, int x){
    return (double)(y1-y2)/(x1-x2)*(x-x1)+y1;
}

bool isInSquare(Point& p, Square& s){
}

bool hasInterSection(){

}

int main(int argc, char **argv){

    return 0;
}