#include <iostream>
#include <vector>
using namespace std;

const long long INF = 9999999;

//aは書き換える必要があるので参照渡し,bは比較するだけで書き換える必要がないため値渡し
template<class T> void chmin(T& a, T b){
    if(a > b){
        a = b;
    }
}

int main(){
    int i, j, n;
    cin >> n;
    vector <long long> h(n);
    for (i = 0; i < n; i++){
        cin >> h[i];
    }

    vector<long long> dp(n, INF);

    dp[0] = 0;
    //帰納法的な考え方
    for (j = 1; j < n; j++){
        chmin(dp[j], dp[j - 1] + abs(h[j] - h[j - 1]));
        if(i > 1){
            chmin(dp[j], dp[j - 2] + abs(h[j] - h[j - 2]));
        }
    }
    cout << dp[n - 1] << endl;
}
