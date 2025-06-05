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

namespace IO {
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        for (const auto& elem : vec) {
            os << elem << " ";
        }
        return os;
    }
}
using namespace IO;
void solve(){
    int n;
    cin>>n;
    vi a(n);
    vi prefmx(n+1, 0);

    for(int i = 0; i<n; i++){ 
        cin>>a[i];
        prefmx[i+1] = max(prefmx[i], a[i]);
    }
    //consider observing at x,y
    // xmody + ymodx WLOG assume x<y
    //then f(x,y) = x+ (y - floor(y/x)*x)
    //assuming this f(x,y)<=max(x,y)
    //thus we want to look at the biggest element in any given position
    vi dp(n, 0);
    dp[0] = 0;
    //f(x,x) = 0
    //if no change check only current element
    //otherwise we must find biggest wihtin previous n elements
    auto f = [&](const int& a, const int& b){
        return (ll)((a%b) + (b%a));  
    };
    //to find the best one find the nu,ebr that it s closest to floor(y/x) == 1
    //in which case this would be equal to y which is the max which we can possibly get
    //if this nuymebr doesnt exist we choose the next biggest?
    //4 + 3 
    set<int> seen;
    seen.insert(a[0]);
    for(int i = 1; i<n; i++){
        if(prefmx[i+1] == prefmx[i]){
            //check current number
            dp[i] = max(dp[i-1], f(prefmx[i+1], a[i]));
        }else if(prefmx[i+1]<prefmx[i]*2){
            dp[i] = prefmx[i+1];
        }else{
            for(auto it = seen.begin(); it!=seen.end(); it++){
                dp[i] = max(dp[i], f(*it, prefmx[i+1]));
            }
        }
        seen.insert(a[i]);
    }
    cout<<dp<<endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
