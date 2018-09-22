// 1번 문제: 상금 헌터

#include<iostream>

using namespace std;

int T;
int first_money[7] = {0, 5000000, 3000000, 2000000, 500000, 300000, 100000};
int second_money[6] = {0, 5120000, 2560000, 1280000, 640000, 320000};

int get_first_money(int place){
    if(place > 21 || place == 0)
        return 0;
    else{
        int part_sum = 0;
        int i;
        for(i=1; i<=6; i++){
            part_sum += i;
            if(part_sum >= place)
                break;
        }
        return first_money[i];
    }
}

int get_second_money(int place){
    if(place > 31 || place == 0)
        return 0;
    else{
        int part_sum = 0;
        int rank=0;
        int i;
        for(i=1; i<=16; i=i*2){
            part_sum += i;
            rank++;
            if(part_sum >= place)
                break;
        }
        return second_money[rank];
    }
}

int main(int argc, char** argv){
    cin >> T;
    int a,b;

    for(int test_case = 0; test_case < T; test_case++){
        cin >> a >> b;
        cout << get_first_money(a) + get_second_money(b) << endl;
    }
    return 0;
}