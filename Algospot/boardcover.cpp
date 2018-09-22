// 2018/07/05 solved
#include<iostream>
#include<vector>

using namespace std;

bool** taken;
int C,H,W;
int occasion[4][2][2] = {
    {{0,1},{1,1}},
    {{1,0},{1,1}},
    {{1,0},{1,-1}},
    {{0,1},{1,0}}};

int count_answer(void){
    int first_i=-1, first_j=-1;
    int ret = 0;

    for(int i=1; i<H+1; i++){
        for(int j=1; j<W+1; j++){
            if(!taken[i][j]){
                first_i = i;
                first_j = j;
                break;
            }
        }
        if(first_i != -1) break;
    }

    // cout << "first(i,j): (" << first_i << "," << first_j << ")" << endl;

    if(first_i == -1) return 1;

    for(int i=0; i<4; i++){
        if(!taken[first_i+occasion[i][0][0]][first_j+occasion[i][0][1]] && !taken[first_i+occasion[i][1][0]][first_j+occasion[i][1][1]]){
            taken[first_i+occasion[i][0][0]][first_j+occasion[i][0][1]] = true;
            taken[first_i+occasion[i][1][0]][first_j+occasion[i][1][1]] = true;
            taken[first_i][first_j] = true;
            ret += count_answer();
            taken[first_i+occasion[i][0][0]][first_j+occasion[i][0][1]] = false;
            taken[first_i+occasion[i][1][0]][first_j+occasion[i][1][1]] = false;
            taken[first_i][first_j] = false;
        }
    }
    return ret;
}

int main(void){
    cin >> C;
    for(int test_case=0; test_case<C; test_case++){
        cin >> H >> W; 
        
        taken = new bool*[H+2];
        for(int i=0; i<H+2; i++){
            taken[i] = new bool[W+2];
        }
        char ch;
        for(int i=0; i<H+2; i++){
            for(int j=0; j<W+2; j++){
                if(i!=0 && i!=H+1 && j!=0 && j!=W+1){
                    cin >> ch;
                    if(ch == '#')
                        taken[i][j] = true;
                    else
                        taken[i][j] = false;
                }
                else{
                    taken[i][j] = true;
                }
            }
        }
        int A = count_answer();
        cout << A << endl;
    }

    return 0;
}