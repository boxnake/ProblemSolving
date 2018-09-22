#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char buf[1000];

class TreeNode{
public:
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
    TreeNode* fourth;
};

int main(int argc, char** argv){
    int C;
    cin >> C;
    for(int test_case=0; test_case<C; test_case++){
        cin >> buf;
        string s(buf);
        if(s[0] != 'x'){
            cout << s << endl;
            continue;
        }
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'x'){
                
            }
        }
    }
    return 0;
}