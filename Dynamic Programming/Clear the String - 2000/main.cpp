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


void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a;
    for(int i = 0; i<n-1; i++){
        if(s[i] != s[i+1]){
            a.pb(s[i] - 'a');
        }
    }
    a.pb(s[n-1]-'a');
    //at any point we can just take the entire thing
    int m = a.size();
    vvi dp(m, vi(m, INT_MAX));
    for(int i = 0; i<m; i++){
        dp[i][i] = 1; //single letters take one delete
    }
    for(int i = 0; i<m-1; i++){
        dp[i][i+1] = 2; //letters right next to each other can only ever take 2 deletes
    }
    for(int len = 3; len<=m; len++){
        for(int l = 0; l<=m-len; l++){
            ll r = l+len-1;
            dp[l][r] = 1+dp[l+1][r]; //dont incldue itself
            //at any point we can choose to insert l or r 
            for(int idx = l+1; idx<=r; idx++){
            
                if(a[idx] == a[l]){
                    dp[l][r] = min(dp[l][r], dp[l+1][idx] + (idx+1 <= r ? dp[idx+1][r] : 0));
                    //abacac
                }
            }

            //0, 2, 4, 6
            //solve everything within a range + 1
            //or solve all subranges +1,
            //or solve a subrange then solve eveyrthing seperately -> solve 1+dp[1][1] + dp[3][3], then dp[4][6]
            //or solve same thing backwards
          //the idea here is that some parts of the array should be grouped together. to find the optimal grouping we note that groups should have the same letter and thus can be used on the same operation
          //so we can define the range dp[l][r] be such that at every point we have optimal of runs from a[l][r] where a is just the collapsed version of the string (note that any best order will jsut always include the full range here so we can collapse it down to practically 1)
          //now if a[l]==a[idx] we will never have to pay the oepration of dp[l+1][idx] since here we can just use the same operation that edeleted idx to delete l. otherwise if we dont take any idx we must +1 for deleteing l

        }
    }
    cout<<dp[0][m-1]<<nl; 
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t =1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
