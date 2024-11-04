#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

// Everything Else thats new :D
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n), b(q), c(n+1, 0LL), ans(n+1);
    for(int i = 0; i<n; i++){ cin>>a[i]; c[a[i]]++;}
    for(int i = 0; i<q; i++){
        cin>>b[i];
    }
    for(int i = 1; i<=n; i++){
        c[i] += c[i-1];
    }
    for(int i = 1; i<=n; i++){
        //we need to find the smallest MIDDLE number, thus there must be at least n/2 numbers to the left
        //so we check the number of mods fr! becuase after the operations the smallest number for any a[x] will be a[x] mod i
        int l = 0;
        int r = i; //max that it can be is the current biggest mod
        while(l<r){
            int mid = (l+r)/2;
            int cnt = 0;
          //modn is js like Mod_n * i + mid right so mid = our middle number
          //becuz we know it has to be less than n we can js count the number o numbers that are less than middle cuz we know that it will be i after everything is subtracted
          //so we prefix sum it. count the amount of ones that have 0-mid (mod_n*i<=n and at these intervals of mod_n*i we get the first 0,1,2...mid terms.
          //we know we need at least n/2+1 if we get that then its good
            for(int mod_n = 0; mod_n*i<=n; mod_n++){
                cnt+=c[min(i*mod_n+mid, n)] - (i*mod_n-1>0?c[i*mod_n-1]:0);
            }
            if(cnt-1>=n/2){
                r=mid;
            }else{
                l = mid+1;
            }
        }
        ans[i] = l;
    }

    for(int i = 0; i<q; i++){
        cout<<ans[b[i]]<<" ";
    }
    cout<<'\n';


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
