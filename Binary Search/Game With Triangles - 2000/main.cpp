#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define pqI priority_queue<ll,vector<ll>, greater<int>>
#define pqD priority_queue<ll>
using namespace std;
template<typename Tval>
ostream& operator<<(ostream& os, const vector<Tval>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
//i actually didn't solve this one I was trying some really wonky stuff at first.
//sometimes the best thing to do is to take a math approach and js see where it goes from there
//fr
//take ones from the middle on either end and just add the most profitable ones
// aka l r
// shift l+1, r-1 and mark the other middle one on the other as used
//if l>=r this is bad end
//or if either of the goons is == used then just move
//if l==r then we can still take at max one from the opposite side
//down is good its js that if size%2 then we can take one more from the other side
//as long as other side has >=2 ops afterwards
//the best op here is going to be the l-r of the other side

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vi a(n);
        vi b(m);
        for(int i = 0; i<n; i++ ) cin>>a[i];
        for(int i = 0; i<m; i++) cin>>b[i];
        sort(all(a));
        sort(all(b));
        vi pref(n+1, 0);
        vi pref2(m+1, 0);
        for(int i = 1; i<=n; i++) pref[i] = pref[i-1] + (a[n-i] - a[i-1]);
        for(int i = 1; i<=m; i++) pref2[i] = pref2[i-1] + (b[m-i] - b[i-1]);
        vector<ll> ans;
        int kmax = 0;
        //function that takes x operations from a y operations from b
        //given that this is so we can take for f(k)
        //ft(x, k-x)
        //find the max along this range
        //this is bounded by x>=0 y>=0 2x+y<=n,
        //doing so with x we can find such number that 2x+k-x <=n 2(k-x) +x <= m
        //for any given x x<=n-k or x>= 2k-m
        //or k>=x or x>= 0
        //thus max(0, 2k-m) <= x <= min(n-k, k)
        for(int k = 1; 2*k-m<=n-k; k++){
            int L = max(0, 2*k-m);
            int R = min(n-k, k);
            if(L>R) break;
            //our x has to be around this range
            //such that that the above inequality is always true
            auto search = [&](int& L, int& R){
                int LM  = (L*2+R)/3;
                int RM = (L+R*2)/3;
                //such that we know that this always going to end at the max

                //return such that
                if((pref[LM] + pref2[k-LM])>(pref[RM] + pref2[k-RM])){ //approach the peak
                    R = RM;
                }else {
                    L = LM;
                }
            };
            while(R-L>3){
                search(L, R);
            }
            ll ans2 = 0;
            for(int i = L; i<=R; i++){
                ans2 = max(ans2, pref[i] + pref2[k-i]);

            }
            ans.pb(ans2);
        }

        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
}

