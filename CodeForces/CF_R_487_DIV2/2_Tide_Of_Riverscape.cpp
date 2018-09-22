#include<iostream>

using namespace std;

int n,p;
char *record;

bool isPeriod(int period){
    
}

int main(int argc, char** argv){
    cin >> n;
    cin >> p;

    record = new char[n+1];
    cin >> record;

    if(record[p] == '.'){
        for(int i=0; i<n; i++){
            if(record[i] == '.'){
                record[i] = '0';
            }
        }
        record[p] = (record[0] == '0')? '1': '0';
        cout << record << endl;
    }
    else{
        bool possible = false;
        for(int i=0; i+p<n && (i+p)<(2*p); i++){
            if(record[i] != record[i+p]){
                possible = true;
                if(record[i] == '.')
                    record[i] = (record[i+p] == '0')? '1': '0';
                if(record[i+p] == '.')
                    record[i+p] = (record[i] == '0')? '1': '0';
            }
            else if(record[i]=='.' && record[i+p] == '.'){
                possible = true;
                record[i] = '0';
                record[i+p] = '1';
            }
        }
        for(int i=0; i<n; i++){
            if(record[i] == '.'){
                record[i] = '0';
            }
        }
        if(possible){
            cout << record << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}