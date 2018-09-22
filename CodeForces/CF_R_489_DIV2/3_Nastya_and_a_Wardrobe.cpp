#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 1000000007;

long long power(long long x, long long n){
    long long t;
    if(n == 0){
        return 1;
    }

    if(n == 1){
        return x % MOD;
    }
    t = power(x, n/2) % MOD;
    if(n % 2 == 0){
        return t * t % MOD;
    }
    else{
        return t%MOD * t%MOD * x % MOD;
    }
}

int main(int argc, char **argv){
    long long  n, k;
    cin >> n >> k;

    if(n == 0){
        cout << 0 << endl;;
        return 0;
    }
    if(n % MOD == 0){
        cout << (MOD - (power(2,k)-1)) % MOD << endl;
        return 0;
    }
    n %= MOD;
    cout << (2*n*power(2,k)-power(2,k)+1) % MOD << endl;;

    return 0;
}