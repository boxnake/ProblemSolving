// 2018/??/?? solved.
#include<iostream>
#include<string>

using namespace std;

int codes[8];

bool isAscending(){
    for(int i=0; i<7; i++){
        if(codes[i] > codes[i+1])
            return false;
    }
    return true;
}

bool isDescending(){
    for(int i=0; i<7; i++){
        if(codes[i] < codes[i+1])
            return false;
    }
    return true;
}

int main(int argc, char** argv){
    for(int i=0; i<8; i++){
        cin >> codes[i];
    }

    if(isAscending())
        cout << "ascending" << endl;
    else if(isDescending())
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;

    return 0;
}