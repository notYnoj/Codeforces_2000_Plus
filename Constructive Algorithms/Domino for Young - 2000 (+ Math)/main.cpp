#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    /*
      We can transform the field into a chess board like pattern followed by black and white squares
      now we can pick all squares as long as we use black and white pattern. Theres always a way to pick black and white
      now if we have more black than white tho we are limited by white. thus we are limited by smaller black or white
      thus work by this and solve the problem!
    */
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i<n; i++) cin>>a[i];
    ll guarentee = 0;
    ll w = 0; ll b = 0;
    for(ll i = 0; i<n; i++){
        if(i%2){
            if(a[i]%2){
                w++;
            }
        }else{
            if(a[i]%2){
                b++;
            }
        }
        guarentee+=a[i]/2;
    }
    ll ans = guarentee+min(w,b);
    cout<<ans;
}
