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


template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec){
    //of size n
    for(T& elem: vec){
        is>>elem;
    }
    return is;
}

const ll mxN = 2e5+5;
ll subtree_size[mxN], sz[mxN], dp[mxN];
vvi graph;

void dp_func(ll i, ll p, ll n) {
    ll sum_c = 0;

    for (const auto& node: graph[i]) {
        if(p == node) continue;
        sum_c += sz[node];
    }
    
    dp[i] = sum_c + (p != -1 ? (dp[p] - sz[i] - subtree_size[i] + n) : 0);
    
    for (const auto& node: graph[i]) {
        if(node == p) continue;
        dp_func(node, i, n);
    }
}

void dfs(ll u, ll p){
    subtree_size[u] = 1;
    sz[u] = 0;
    for(const auto& node: graph[u]){
        if(node == p) continue;
        else{
            dfs(node, u);
            subtree_size[u]+=subtree_size[node];
            sz[u]+=sz[node];
        }
    }
    sz[u]+=subtree_size[u];
}
void solve(){
    ll n;
    cin>>n;
    graph.resize(n);
    for(ll i = 0; i<n-1; i++){
        ll l, r;
        cin>>l>>r;
        l--;
        r--;
        graph[r].pb(l);
        graph[l].pb(r);
    }
    dfs(0, -1);
    dp_func(0, -1, n);
    ll ans = INT_MIN;
    for(ll i = 0; i<n; i++) ans = max(ans, dp[i]);

    cout << ans + n << endl;

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
