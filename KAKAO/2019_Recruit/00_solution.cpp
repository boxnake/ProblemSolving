#include <vector>
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool solution(vector<int> arr)
{
    bool answer = true;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    int vec_size = arr.size();
    bool* isNotSeen = new bool[vec_size+1];
    memset((void*)isNotSeen, (int)true, sizeof(bool));
    
    for(int i=0; i<vec_size; i++){
        if(arr[i]<=vec_size && arr[i]>=1 && isNotSeen[arr[i]]){
            isNotSeen[arr[i]] = false;
            continue;
        }
        answer = false;
        break;
    }
    
    return answer;
}