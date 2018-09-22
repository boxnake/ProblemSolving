// B번 문제 : 인형들 
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

double N,K;
double average;
vector<double> v;
vector<double> devs;

double get_average(int start){
    average = 0.0;
    int i=0;
    for(auto iter=v.begin()+start; i<K; iter++,i++){
        average += *iter;
    }
    average = average / K;
    return average;
}

double sq(double input){
    return input*input;
}

void get_deviations(){
    int start, last;
    start = 0, last = K-1;
    for( ; last <= N-1; start++,last++){
        double part_avg = get_average(start);
        double part_sum = 0.0;
        auto iter = v.begin();
        for(int _K=K; start+_K-1 <= N-1; _K++){
            part_sum=0.0;
            for(int i=0; i<_K; i++){
                part_sum += sq(*(iter+start+i)-part_avg);
            }
            part_sum /= _K;
            part_sum = sqrt(part_sum);
            devs.push_back(part_sum);
        }
    }
}

double get_minimum_deviation(){
    get_deviations();
    stable_sort(devs.begin(), devs.end());

    return *(devs.begin());
}

int main(int argc, char** argv){
    cin >> N >> K;
    double num;

    for(int i=0; i<N; i++){
        cin >> num;
        v.push_back(num);
    }
    cout << get_minimum_deviation() << endl;
    return 0;
}