#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_BITS = 29;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  //query making machine :D
    auto query = [&](ll a, ll b, int t) -> ll{
        if(t == 1){
            swap(a,b);
        }

        cout<<"? "<<a<<' '<<b<<endl;
        ll x;
        cin>>x;
        if(t == 1 && x!=0){
            (x==1?x = -1:x=1);
        }

        return x;
    };
  //beginning query to check for 3 cases a>b a<b and a==b
    ll t = query(0, 0, -2);
    if(t == 0){ //if a==b
        vector<ll> number(30, 0);
        ll new1 = 0;
        for(ll i = 0; i<=MAX_BITS; i++){
            ll z = query((new1+(1LL<<i)), new1, 0);
          //think about it like this, since bits are independent -> since they are equal we can check if it decreases (bit set + bit set = 0) that means bit set :D 
            if(z == -1){
                number[i] = 1;
                new1+=1LL<<i;
            }else{
                number[i] = 0;
            }
        }
        ll ans = 0;
        for(ll i = 0; i<=MAX_BITS; i++){
            ans+=number[i]<<i;
        }
        cout<<"! "<<ans<<' '<<ans;
        fflush(stdout);
        return 0;
    }else{
      //simlar logic follows here only that there is 4 cases small -> small -> small, small->big->small, small->big->big, small-> small -> big
      //by thinking about it if small->big->small this means 0,0 if small->small->small means 1,1, if small->big->big, 0,1 and small becomes big and big becomes small and finall that means that 0,1 stays same is the final case
        vector<ll> smaller(30); //1 more
        vector<ll> bigger(30); //1 more
        bool change = false; //to signify when small->big and big->small 
        for(ll bit = MAX_BITS; bit>=0; bit--){ //go thru each bit
            ll cur_sum = 0;
            ll cur_bigger_sum = 0; //current sums
            for(ll i = 29; i>bit; i--){
                cur_sum+=(smaller[i]<<i);
                cur_bigger_sum+=(bigger[i]<<i); //current sums
            }
            //changing it if bigger changes (!! <- this was commented before)
            (!change?cur_sum+=(1<<bit):cur_bigger_sum+=(1<<bit)); 
            ll cur = query(cur_sum, cur_bigger_sum, t);
            if(change){
                (cur==1?cur=-1:cur=1);
            }
            if(cur == 0) { //if its equal then we can just "brute force it" with similar idea to the first case just a little annoying
                (!change? smaller[bit] = 0:smaller[bit] =1 );
                (!change? bigger[bit] = 1:bigger[bit] = 0);
                cur_sum = 0;
                cur_bigger_sum = 0;
                for(ll i = MAX_BITS; i>=bit; i--){
                    cur_sum+=(smaller[i]<<i); //got it incrrecot cuz i had i as bit ....................................
                    cur_bigger_sum+=(bigger[i]<<i);
                }
                for(ll i = bit-1; i>=0; i--){
                    ll z = query(cur_sum+(1LL<<i), cur_bigger_sum,t);
                    if(z == -1){
                        bigger[i] = smaller[i] =  1;
                        cur_sum+=1LL<<i;
                        cur_bigger_sum+=1LL<<i;
                    }else{
                        bigger[i] = smaller[i] = 0;
                    }
                }
                break;
            }
            (!change?cur_bigger_sum+=(1<<bit):cur_sum+=(1<<bit));
            ll new_cur = query(cur_sum, cur_bigger_sum, t);
            if(change){
                (new_cur==1?new_cur=-1:new_cur=1);
            }
            //calm luh notebook (calm luh notebook [I did logic on notebook])
            if(cur == 1){
                if(new_cur == 1){
                    (!change?bigger[bit] = 1:bigger[bit]=0);
                    (!change?smaller[bit] = 0:smaller[bit] = 1);
                    change = !change;
                }else{
                    bigger[bit] =0;
                    smaller[bit] = 0;
                }
            }else{
                if(new_cur == 1){
                    (!change?bigger[bit] = 1:bigger[bit]=0);
                    (!change?smaller[bit] = 0:smaller[bit] = 1);
                }else{
                    bigger[bit] =1;
                    smaller[bit] = 1;
                }
            }
        }

        ll a = 0;
        ll b = 0;
        for(ll i = 0; i<=MAX_BITS; i++){
            a+=smaller[i]<<i;
            b+=bigger[i]<<i;
        }
        if (t == 1) {
            swap(a, b);
        } //answer!
        cout<<"! "<<a<<' '<<b<<endl;
    }
}
