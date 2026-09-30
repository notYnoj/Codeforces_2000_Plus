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
const int mod =  998244353;
const int n = 3005;
ll dp[n][n]; //min, max
ll fac[n], twos[n];
void precomp(){
    for(int i = 0; i<n; i++){
        fac[i] = 1;
    }

    fac[1] = 3100;
    for(int i = 2; i<n; i++){
        if(fac[i] == 1){
            for(int j = i; j<n; j+=i){
                fac[j]*=i;
            //need primes
            }
        }
    }

    twos[0] = 1;
    for(int i = 1; i<n; i++){
        dp[i][i] = i;
        twos[i] = (twos[i-1] * 2LL) % mod;
    }
    for(int i = 1; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(i % fac[j] == 0){
                dp[i][j] = dp[i-1][j-1]; //has to happen
            }else{
                dp[i][j] = dp[i][j-1]; //will get us the max
            }
        }
    }
}

void solve(){
    int nt;
    cin>>nt;
    vi a(nt);
    cin>>a;
    vi count(nt+1);
    vi pref(nt+1, 0);

    for(int i = 0; i<nt; i++){
        count[a[i]]++;
    }
    for(int i = 1; i<=nt; i++){
        pref[i] = pref[i-1] + count[i];
    }
    //needs at least one of i and one of j then rest can be any of the ones
    //2^count[i] -1 * 2^count[j] -1 * (2^(pref[j-1] - pref[i]) ) * dp[i][j]
    //2^count[i] -1 * dp[i][i]
    ll ans = 0;
    for(int i = 1; i<=nt; i++){
        for(int j = i; j<=nt; j++){
            if(i == j){
                //6 + 3  =61
                ll res = (twos[count[i]] - 1) * dp[i][j];
                ans+=(res%mod);
                ans%=mod;
            }else{
                //needs to have at least one of the end points, int he middle can be anything
                ll res = (twos[count[i]] - 1) * (twos[count[j]] - 1) % mod;
                res *= (twos[pref[j-1] - pref[i]]);
                res%=mod;
                res*=dp[i][j];
                res%=mod;
                ans+=(res%mod);
                ans%=mod;
            }
        }
    }
    cout<<(ans%mod)<<nl;
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    precomp();
    cin>>t;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
