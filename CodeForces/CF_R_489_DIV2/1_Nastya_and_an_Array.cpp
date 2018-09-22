#include<iostream>
#include<set>

int *arr;
int n;

using namespace std;

int main(int argc, char** argv){
    cin >> n;
    set<int> not_zeros;

    arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] != 0) not_zeros.insert(arr[i]); 
    }
    
    cout << not_zeros.size();

    return 0;
}