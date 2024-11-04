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
    for(int i = 1; i<=n; i++){
        c[i] += c[i-1];
    }
    for(int i = 1; i<=n; i++){
        // we need to find the smallest MIDDLE number, thus there must be at least n/2 numbers to the left
        //so we check the number of mods fr!
        int l = 0;
        int r = i;
        while(l<r){
            int mid = (l+r)/2;
            int cnt = 0;
            for(int mod_n = 1; mod_n<=mod_n*i; mod_n++){
                cnt+=c[min(i*mod_n+mid, n)] - (i*mod_n-1>0?c[i*mod_n-1]:0);
            }
            if(cnt-1>=n/2){
                r=mid;
            }else{
                l = mid+1;
            }
            ans[i] = l;

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
