#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
template <typename T, T mod> class Mint{
private: 
    T val;
    T modinv(T a, T m) {
        T m0=m, t, q;
        T x0=0, x1=1;
        while (a>1) {
            q = a/m;
            t = m;
            m = a%m;
            a = t;
            t=x0;
            x0=x1-q*x0;
            x1=t;
        }
        if (x1<0) x1 += m0;
        return x1;
    }
public:
    Mint() : val(0){}
    Mint(T val) : val((val%mod+mod)%mod){}
    //overload +, -, *, 
    friend std::ostream& operator<<(std::ostream& os, const Mint& m) {
        os<<m.val;
        return os;
    }
    Mint operator+(const Mint& other) const{
        return Mint((other.val + val)%mod);
    }
    Mint operator-(const Mint& other) const{
        return Mint((val - other.val+mod)%mod);
    }
    Mint operator*(const Mint& other) const{
        return Mint((val*other.val)%mod);
    }
    Mint operator/(const Mint& other) const{
        return Mint(((val * modinv(other.val, mod)) + mod ) % mod);
    }
    Mint& operator+=(const Mint& other){
        val = (val+ other.val)%mod;
        return *this;
    }
    Mint& operator-=(const Mint& other){
        val = (val - other.val+mod)%mod;
        return *this;
    }
    Mint& operator*=(const Mint& other){
        val = (val * other.val)%mod;
        return *this;
    }
    Mint& operator/=(const Mint& other){
        val = ((val * modinv(other.val))+mod)%mod;
        return *this;
    }
    bool operator==(const Mint& other) const {return val==other.val;}
    bool operator!=(const Mint& other) const {return val!=other.val;}
    bool operator>(const Mint& other) const {return val>other.val;}
    bool operator<(const Mint&other) const {return val<other.val;}
    bool operator>=(const Mint&other) const {return val>=other.val;}
    bool operator<=(const Mint&other) const {return val<=other.val;} 
};

#define mint Mint<int, mod>
#define mll Mint<ll, (ll)mod>
//mod int/ll implementation! :D
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> pref(n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        pref[i+1] = pref[i]^a[i];
    }
    map<int, mll> dp;
    dp[0] = 1;
    for(int i = 0; i<n; i++){
      //the thought process here was: if every operation has to result in two numbers that are equal to each other, their xor wil cancel out
      //meaning that a1^a2^a3... = p^q^r meaning that the pref xor of everything has to be equal to one number
      //this means that we can use pref xor
      //how many ways are there to get from state i to state i+1?
      //well we can always xor the original number to move foward, so we can ignore that
      //however if we choose to not do this then we must xor one of the other two numbers meaning that they must be prefi-1 or prefi (becuz there can be like prefi-1, prefi, prefi) as well!
      //or there can be prefi-1, prefi-1, prefi-1 (this is becuz only these two cases will lead to us having at least 1 prefi alongside two other prefi-1 to xor out with
      //there are 3 ways to chose from prefi-1 to get to prefi (1,2,3) and there are two ways to get from prefi (2,3)
      //thus:
      
        dp[pref[i]] = mll(3)*dp[pref[i]] + mll(2)*dp[pref[i+1]];
    }
    mll ans = 0;
    for(auto i: dp){
        ans+=i.second;
    } //add em all up 
    cout<<ans<<endl;




}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
