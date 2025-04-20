#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
int mod = 1e9+7;
ll nCk(ll totz){
    //2^titz
    ll ans = 1;
    ll base = 2;
    while(totz>0){
        if(totz&1){
            ans = (ans*base)%mod;
        }
        base = (base*base)%mod;
        totz>>=1;
    }
    return ans;

}
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<pair<ll, ll>> grid(k);
    map<pii, ll> check;
    for(ll i = 0; i<k; i++){ll z; cin>>grid[i].first>>grid[i].second>>z; check[grid[i]] = z+1;};
    //imaigne placing a black square, or any shape on a white plane.
    //each black edge corresponds to one opposite swtich
    //the permiter of any given shape like this will always be even
    //a black square has an even amount of edges a combination of black squares always subtracts by 2 edges
    //any combination will be even - 2*k attachments
    //this is always even
    //so for any side that has 4 in a plane or 2 in plane doesnt matter
    //thus it only matters that the ones that are on the edges with 3
    //within the cells there is 2^n*m-k options for the things
    //if the ones on the sides are good then its just going to be that otherwise
    //within any set there is there is going to be 2^n-m-k-1 <- this is becuase half are odd half are even
    //if i need the right most thing to switch its gonna have to be becuase there is odd amount inside
    //the odd amouynt happes half the time
    //if i dont ened it its even -> happesn half teh amount of time so k/2 amount for white k/2 amount of the other things
    //1/2 of all possible options
    ll totz = n*m-k;
    ll amnt = 0;
    vector<pii> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    map<pair<pii, pii>, bool> paired;
    ll numB = 0;
    ll numW = 0;
    for(ll i = 0; i<k; i++){

        if((grid[i].first == 1 && grid[i].second == m) || (grid[i].first == 1 && grid[i].second == 1) || (grid[i].first == n && grid[i].second == m)|| (grid[i].first == n && grid[i].second == 1)){
            continue;
        }
        if(grid[i].first == 1 || grid[i].first == n || grid[i].second == 1 || grid[i].second == m){
            if(check[grid[i]]){
                if(check[grid[i]] == 1){
                    numB++;
                }else{
                    numW++;
                }
            }
            amnt++;
        }
    }
        if(amnt == (2*n + 2*m -8)){
            if(numB%2 == 0) {
                cout << nCk(totz) << "\n";
            }
            else cout<<"0\n";
        }else{
            cout<<nCk(totz-1)<<"\n";
        }
    }

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
