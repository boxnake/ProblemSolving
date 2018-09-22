#include<iostream>

using namespace std;

char input_str[101];
int length;

int count_string_length(){
    for(int i=0; i<101; i++){
        if(input_str[i] == '\0')
            return i;
    }
    return 100;
}

bool find_answer(){
    for(int i=0; i<length-2; i++){
        if(input_str[i] == '.' || input_str[i+1] == '.' || input_str[i+2] == '.')
            continue;
        else{
            if((input_str[i] != input_str[i+1]) && (input_str[i+1] != input_str[i+2]) && (input_str[i] != input_str[i+2]))
                return true;
        }
    }
    return false;
}

int main(int argc, char** argv){
    cin >> input_str;

    length = count_string_length();

    if(find_answer())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}