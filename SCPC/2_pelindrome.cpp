#include<iostream>
#include<vector>

using namespace std;

int T;

bool is_pelindrome(int num){
    int radix;

    if(num / 1000 != 0){
        if(((num/1000) == (num%10)) && ((num/100%10) == (num/10%10))) return true;
        else return false;
    }
    else if(num / 100 != 0){
        if((num/100) == (num%10)) return true;
        else return false;
    }
    else if(num / 10 != 0){
        if((num/10) == (num%10)) return true;
        else return false;
    }
    else return true;
}

int main(int argc, char** argv){
    cin >> T;
    for(int test_num=1; test_num <= T; test_num++){
        int N;
        vector<int> pelins;
        cin >> N;
        if(is_pelindrome(N)){
            cout << "Case #" << test_num << endl;
            cout << "1 " << N << endl;
            continue;
        }

        for(int i=1; i<N; i++){
            if(is_pelindrome(i)) pelins.push_back(i);
        }

        vector<int>::iterator first_iter, second_iter, third_iter;
        int partial_sum;
        bool success = false;
        for(first_iter=pelins.begin(); first_iter!=pelins.end()-1; first_iter++){
            for(second_iter=first_iter+1; second_iter!=pelins.end(); second_iter++){
                partial_sum = *first_iter + *second_iter;
                if(partial_sum == N){
                    cout << "Case #" << test_num << endl;
                    cout << "2 " << *second_iter << " " << *first_iter << endl;
                    success = true;
                    break;
                }
            }
            if(success) break;
        }
        if(success) continue;

        for(first_iter=pelins.begin(); first_iter!=pelins.end()-2; first_iter++){
            for(second_iter=first_iter+1; second_iter!=pelins.end()-1; second_iter++){
                for(third_iter=first_iter+2; third_iter!=pelins.end(); third_iter++){
                    partial_sum = *first_iter + *second_iter + *third_iter;
                    if(partial_sum == N){
                        cout << "Case #" << test_num << endl;
                        cout << "3 " << *third_iter << " " << *second_iter << " " << *first_iter << endl;
                        success = true;
                        break;
                    }
                }
            }
            if(success) break;
        }
    }

    return 0;
}