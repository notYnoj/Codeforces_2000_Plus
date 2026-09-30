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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s+=s[0];
    vi pref0(n, 0); //00
    vi pref1(n, 0); //11
    vi pref2(n, 0); //10
    for(int i = 0; i<n-1; i++){
        if( s.substr(i, 2) == "00"){
            pref0[i+1]++;
        }else if( s.substr(i, 2) == "11"){
            pref1[i+1]++;
        }else if(s.substr(i,2) == "10"){
            pref2[i+1]++;
        }
        pref0[i+1] += pref0[i];
        pref1[i+1] += pref1[i];
        pref2[i+1] += pref2[i];
    }
    auto wrk = [](int x, int y,int a){
        if(a >= x && a >= y){
            return (a-x) + (a - y);
        }else if(a >= x && a < y){
            int d = ((y - a + 1)/2);
            return d + (y - a) % 2 + (d + a - x);
        }else{
            //try making y to x
            //then make y and x go down till a is greater
            //add y and x until a is not greate 
            int d1 = (y - x);
            if(a + d1 == x && a + d1 == (y-d1)) return d1;
            else{
                if(a+d1 > x && a+d1 > (y-d1)){
                    //some place it was in the middle
                    int ret = x-a;
                    int y_prime = y - (ret);
                    int a_prime = x;
                    int d = (y_prime - a_prime +1)/2;
                    return ret + d + (y_prime - a_prime)% 2 + (d + a_prime - x);
                }else{
                    //never was in the midlde
                    int ret = d1;
                    //t steps ceil((x-a+2)/3) = t
                    int steps = (x-(a+d1))/3;
                    int x_prime = x- steps;
                    ret+= (2*steps);
                    //where a is at right now is a + d1 + 2 * steps - x_prime gets us difference
                    int y_prime = x-steps;
                    ret+= 2*( (x_prime - (a + d1 + 2*steps)) % 3 );
                    return ret;
                }
            }
            //if before y = x, x <= a <y use formula
            //that means y
        }
    };
    for(int i = 0; i<q; i++){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int x = pref0[r] - (pref0[l]) + (s[l] == s[r] && s[l] == '0');
        int y = pref1[r] - (pref1[l]) + (s[l] == s[r] && s[l] == '1');
        if(x > y) swap (x,y);
        int a = pref2[r] - (pref2[l]) + (s[l] != s[r] && s[l] == '0'); //this counts  10 so this should be fine
        cout<<wrk(x, y , a)<<nl;
    }
}
int main(){
    #ifdef DEBUG
    auto start = std::chrono::high_resolution_clock::now();
    #endif
    
    t = 1;
    while(t--){solve();}
    
    #ifdef DEBUG
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\n-----------------------------" << endl;
    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
    #endif
}
