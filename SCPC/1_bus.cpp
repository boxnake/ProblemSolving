#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>

#define ull unsigned long long
#define ll long long

int Answer;
int N,K;


using namespace std;

class PlayerSortCriterion{
public:
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) const {
        return (p1.second < p2.second);
    }
};

bool are_they_not_friend(const pair<int,int>& p1, const pair<int,int>& p2){
    int diff = abs(p1.second-p2.second);
    return (diff <= K);
}

int main(int argc, char** argv){
    int T, test_case;
    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> K;
        vector<pair<int,int>> players;
        vector<set<pair<int,int>, PlayerSortCriterion>> buses;
        set<pair<int,int>, PlayerSortCriterion> bus;
        buses.push_back(bus);
        Answer = 1;

        for(int i=0; i<N; i++){
            int num;
            pair<int, int> player;
            cin >> num;
            player.first = i;
            player.second = num;
            players.push_back(player);
        }

        for(int player_num=0; player_num<N; player_num++){
            bool insert_success=false;
            for(int bus_num=0; bus_num<Answer; bus_num++){
                bool can_insert_bus=true;
                set<pair<int,int>,PlayerSortCriterion>::iterator bus_iter;
                for(bus_iter = buses[bus_num].begin(); bus_iter != buses[bus_num].end(); bus_iter++){
                    if(are_they_not_friend(players[player_num], *bus_iter)){
                        can_insert_bus=false;
                        break;
                    }
                }
                if(can_insert_bus){
                    pair<int,int> player;
                    player.first = player_num;
                    player.second = players[player_num].second;
                    buses[bus_num].insert(player);
                    insert_success = true;
                    break;
                }
            }
            if(!insert_success){
                set<pair<int,int>, PlayerSortCriterion> tmp_bus;
                pair<int,int> tmp_player;
                tmp_player.first = player_num;
                tmp_player.second = players[player_num].second;
                tmp_bus.insert(tmp_player);
                buses.push_back(tmp_bus);
                Answer++;
            }
        }

        Answer = buses.size();

        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}