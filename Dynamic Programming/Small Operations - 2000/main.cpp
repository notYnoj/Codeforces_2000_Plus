#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<int>>
using namespace std;
    
// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
/*namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem << " ";
        }
        return os;
    }
}
using namespace IO;
//for macos^^
*/
template <typename T, std::size_t N> //custom output stream operator for array
std::ostream& operator<<(std::ostream& os, const T (&arr)[N]) {
    for (std::size_t i = 0; i < N; ++i) {
        os << arr[i] << " ";
    }
    return os;
}
ll findMinComposites(const ll t, const ll k){
  //lets analyze this dp
    if(t == 1){ //ofc just having 0 means nothing
        return 0;
    }
    vi divs; //now lets analyze the divsiors of t (its gonna be less than like 240 apparently)
    for(int i = 1; i*i<=t; i++){
        if(t%i == 0){
            divs.pb(i);
            divs.pb(t/i);
        }
    }
    sort(all(divs));
    vi dp(divs.size(), INT_MAX);
  //dp i contains the amount of ops required to get to divsior i (with final one being t)
    dp[0] = 0;
  //teh first divisor 1 takes 0 
    for(int i = 1; i<divs.size(); i++){
        for(int j = i-1; j>=0; j--){
          //to get from dp[i] from dp[j] we can simply analyze first:
          //is it possible to multiply by some number less than k to get to this?
          //if so then multiply it 
            if(divs[i]/divs[j] > k) break; //if its bigger than k we can't ever get from that j to i in one move
            if(divs[i]%divs[j] == 0){ //otherwise we can get to it from one move by mutiplying by some i (that is less than k) so we add it
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp.back();
}
void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    //prime factor x,y
    //need to do like x*y/x
    ll divide = x/gcd(x,y); //its going to be like divide out all of x that isnt important
    ll multiply = y/gcd(x,y); // multiply everything in y that isnt important
    ll tz = findMinComposites(divide, k);  //ops can be found with dp
    ll ty = findMinComposites(multiply, k); 
    if(tz == INT_MAX || ty == INT_MAX) cout<<-1<<endl;     else cout<<tz+ty<<endl;

    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
