#include<iostream>

using namespace std;

int l,r,x,y;
int result = 0;

int gcd(int a, int b){
    int mod = a % b;
    while(mod > 0){
        a = b;
        b = mod;
        mod = a % b;
    }
    return b;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(int argc, char **argv){
    cin >> l >> r >> x >> y;

    for(int a=l; a<=y; a++){
        for(int b=1; b<=r ; b++){
            if(gcd(a,b) == x && lcm(a,b) == y) result++;
        }
    }
    cout << result;
    return 0;
}