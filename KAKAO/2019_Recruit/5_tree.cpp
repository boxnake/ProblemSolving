#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class TreeNode{
public:

    int x;
    int y;
    int num;
    TreeNode* left;
    TreeNode* right;

    TreeNode::TreeNode(int _x, int _y, int _num){
        x = _x;
        y = _y;
        num = _num;
        left = NULL;
        right = NULL;
    };
};

bool compare_tree(TreeNode *i, TreeNode *j){
    return (i->y) < (j->y) || (i->x) > (y->x);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<TreeNode*> trees;

    int num = 1;
    for(auto iter=nodeinfo.begin(); iter<nodeinfo.end(); iter++){
        trees.push_back(new TreeNode((*iter)[0],(*iter)[1], num++));
    }
    stable_sort(trees.begin(), trees.end(), compare_tree);
    return answer;
}
