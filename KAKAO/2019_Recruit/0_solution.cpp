#include <iostream>
#include<string>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    char* str = new char[a+1];
    for(int i=0; i<a; i++){
        str[i] = '*';
    }
    str[a] = '\0';
    for(int i=0; i<b; i++){
        cout << str << endl;
    }
    return 0;
}