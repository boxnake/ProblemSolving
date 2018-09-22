// 2018/07/06 solved.
#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 9999;
int sw_clocks[10][5]= {
    {0,1,2,-1},
    {3,7,9,11,-1},
    {4,10,14,15,-1},
    {0,4,5,6,7},
    {6,7,8,10,12},
    {0,2,14,15,-1},
    {3,14,15,-1},
    {4,5,7,14,15},
    {1,2,3,4,5},
    {3,4,5,9,13}
};

int clocks[16];
int push_count[10]={0,};
int C;

void rotate_clock(int clock){
    if(clocks[clock] == 12) clocks[clock] = 3;
    else clocks[clock] += 3;
}

void push_switch(int sw){
    push_count[sw]++;
    for(int i=0; i<5; i++){
        if(sw_clocks[sw][i] == -1) break;
        rotate_clock(sw_clocks[sw][i]);
    }
}

void reverse_push_switch(int sw){
    push_count[sw]--;
    for(int i=0; i<3; i++){
        push_switch(sw);
    }
}

void initialize_var(){
    for(int i=0; i<10; i++){
        push_count[i] = 0;
    }

    for(int i=0; i<16; i++){
        cin >> clocks[i];
    }
}

bool check_answer(){
    bool correct = true;
    for(int i=0; i<16; i++){
        if(clocks[i] != 12)
            correct = false;
    }
    return correct;
}

int get_answer(int sw){
    int ret = INF;
    if(sw >= 10){
        if(check_answer()){
            return 0;
        }
        else{
            return INF;
        }
    }

    for(int i=0; i<4; i++){
        ret = min(ret, i+get_answer(sw+1));
        push_switch(sw);
    }
    return ret;
}



int main(int argc, char** argv){
    cin >> C;

    for(int test_case=0; test_case<C; test_case++){
        initialize_var();
        int A = get_answer(0);
        if(A == INF)
            cout << -1 << endl;
        else
            cout << A << endl;

    }
    
    return 0;
}