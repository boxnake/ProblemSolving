// 2018/07/05 solved.
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>

#define ull unsigned long long
#define ll long long

using namespace std;

int C, n, m;
int A;
bool areFriends [10][10] = {false,};
bool taken[10] = {false,};

int check_answer(int selected){
    int firstFree = -1;
    int ret = 0;
    for(int i=0; i<n; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    
    for(int pairWith = firstFree+1; pairWith < n; pairWith++){
        if(!taken[firstFree] && !taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[firstFree] = taken[pairWith] = true;
            ret += check_answer(selected+1);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}

int main(int argc, char** argv){
    cin >> C;
    for(int test_case=0; test_case < C; test_case++){
        cin >> n;
        cin >> m;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                areFriends[i][j] = false;
            }
        }
        for(int friend_pair=0; friend_pair < m; friend_pair++){
            int f1, f2;
            cin >> f1;
            cin >> f2;
            areFriends[f1][f2] = true;
            areFriends[f2][f1] = true;
        }
        for(int i=0; i<10; i++){
            taken[i] = false;
        }
        A = check_answer(0);
        cout << A << endl;
    }

    
    return 0;
}