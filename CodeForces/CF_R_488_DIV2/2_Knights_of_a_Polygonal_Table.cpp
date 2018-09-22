#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n, k;
int *p, *c;
long long *result;
const int INF = 1000*1000*1000;

class Knight{
public:
    int idx;
    int power;
    int coin;
};

bool compare_power(Knight *i, Knight *j){
    return (i->power) < (j->power);
}

bool compare_coin(Knight *i, Knight *j){
    return (i->coin) > (j->coin);
}


int main(int argc, char** argv){
    vector<Knight*> v;
    multiset<int> bestset;
    cin >> n;
    cin >> k;
    long long sum = 0;

    result = new long long[n];
    p = new int[n];
    c = new int[n];

    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    for(int i=0; i<n; i++)
        cin >> c[i];
    
    for(int i=0; i<n; i++){
        Knight *knight = new Knight();
        knight->idx = i;
        knight->power = p[i];
        knight->coin = c[i];
        v.push_back(knight);
    }
    stable_sort(v.begin(), v.end(), compare_power);

    for(int i=0; i<k; i++){
        sum += v[i]->coin;
        result[v[i]->idx] = sum;
        bestset.insert(v[i]->coin);
    }

    for(int i=k; i<n; i++){
        result[v[i]->idx] = sum + v[i]->coin;
        if(!bestset.empty()){
            int tmp = *bestset.begin();
            if(v[i]->coin > tmp){
                sum -= tmp;
                sum += v[i]->coin;
                bestset.erase(bestset.begin());
                bestset.insert(v[i]->coin);
            }
        }
    }

    //print result
    for(int i=0; i<n; i++){
        cout << result[i];
        if(i != n-1)
            cout << " ";
    }
    
    return 0;
}
