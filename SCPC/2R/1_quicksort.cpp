#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int C,N;
int* A;

int main(int argc, char** argv){
    cin >> C;
    for(int test_case=1; test_case<=C; test_case++){
        cin >> N;
        vector<int> target_indexes;
        int _max = 0;
        int answer_count = 0;
        A = new int[N];
        for(int i=0; i<N; i++){
            cin >> A[i];
            if(A[i]>_max) target_indexes.push_back(i);
            _max = max(_max, A[i]);
        }

        for(auto iter = target_indexes.begin(); iter != target_indexes.end(); iter++){
            bool success = true;
            for(int i=*iter+1; i<N; i++){
                if(A[*iter] >= A[i]) success = false;
            }
            if(success) answer_count++;
        }
        cout << "Case #" << test_case << endl;
        cout << answer_count << endl;
    }

    return 0;
}