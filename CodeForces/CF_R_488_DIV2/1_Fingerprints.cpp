#include<iostream>

using namespace std;

int n,m;
int *x, *y, *result;
int total_count=0;

int main(int argc, char** argv){
    cin >> n;
    cin >> m;
    x = new int[n];
    y = new int[m];
    result = new int[10];

    for(int i=0; i<n; i++)
        cin >> x[i];
    for(int i=0; i<m; i++)
        cin >> y[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(x[i] == y[j]){
                result[total_count++] = x[i];
            }
        }
    }

    for(int i=0; i<total_count; i++){
        cout << result[i];
        if(i != total_count-1)
            cout << " ";
    }

    return 0;
}
