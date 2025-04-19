#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

void solve(){
    priority_queue<ll> pq;
    ll n, k;
    cin>>n>>k;
    //taking the best sushi at every k+1 interval becuase we know there is always something after that no matter what (just take it optimally)
  //if there are n items n-i is teh amount of items to the right add 1 becuase u can also take on that time
  //we know that we kneed at least k+1 items to take 1. 
  //take the best number at that tiem to the left
    vector<ll> time(n+1);
    ll ans = 0;
    for(ll i =1; i<=n; i++){
        cin>>time[i];
        pq.push(time[i]);
        if((n-i+1)%(k+1) == 0){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
