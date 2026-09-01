#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define nl '\n'
#include <chrono>
using namespace std;
int t;
// Everything Else thats new :D
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::pair<T, T> p){
    os<<p.first<<' '<<p.second<<endl;
    return os;
}
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << ' ';
    }
    return os;
}
/*
Entire idea is to go backwards starting from an ending node. Then look at its parent. if this ending node is def lose the parent is def win cuz parent can play onto this move. otehrwise if its def win we can subtract 1
if parent at this pos has no moves aka 0 we say its def lose. then we just keep going. anything that goes into an infiite loop just has more than 1 so we can just not push onto bfs
  */

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}

void solve(){
    int n;
    cin>>n;
    int k1;
    cin>>k1;
    vi rick(k1);
    cin>>rick;
    int k2;
    cin>>k2;
    vi mort(k2);
    cin>>mort;
    queue<pii> pq;
    pq.push({0, 0});
    pq.push({1, 0});
    vvi dp(2, vi(n)); //0 = rick, 1 = mmort
    for(int i = 0; i<n; i++){
        dp[0][i] = k1; //rick has k1 options 
    }
    for(int i = 0; i<n; i++){
        dp[1][i] = k2; //morty has k2 options
    }
    dp[0][0] = 0; //0 is lose
    dp[1][0] = 0;
    while(!pq.empty()){
        auto tp = pq.front();
        pq.pop();
        int parent = tp.first^1;
        vi &moves = parent ? mort : rick;
        for(ll i : moves){
            ll cur_look_at = ((tp.second - i)+n)%n;
            if(cur_look_at == 0) continue;
            if(dp[parent][cur_look_at] == 0) continue;
            if(dp[parent][cur_look_at] == INT_MAX) continue;
            if(dp[tp.first][tp.second] == 0){ 
                dp[parent][cur_look_at] = INT_MAX; //if the other player can get to here they are winning
                pq.push({parent, (int)cur_look_at});  
            }else{
                dp[parent][cur_look_at]--; //1 less option to get to from her 
                if(dp[parent][cur_look_at] == 0) pq.push({parent, (int)cur_look_at});
            }
        }
    }
    for(int i = 1; i<n; i++){
        if(dp[0][i] == INT_MAX) cout<<"Win";
        else if(dp[0][i] == 0) cout<<"Lose";
        else cout<<"Loop";
        cout << " \n"[i==n-1];
    }
    for(int i = 1; i<n; i++){
        if(dp[1][i] == INT_MAX) cout<<"Win";
        else if(dp[1][i] == 0) cout<<"Lose";
        else cout<<"Loop";
        cout << " \n"[i==n-1];
    }
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
