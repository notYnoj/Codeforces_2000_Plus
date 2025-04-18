#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> //custom output stream operator for vector
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}
int main(){
    ll n,k;
    cin>>n>>k;
    priority_queue<ll> pq;
    for(ll i =0; i<=k; i++){
        pq.push(0); // can make it 0 again k times --- [our ranges] 0 ----
    }
    vector<ll> A(n);
    for(ll& a:A){
        cin>>a;
    }
    sort(A.begin(), A.end(), greater<ll>());
    ll score = 0;
    //we want to greedily take the numbers but there are also some partions
    //the only time these partions matter is when its negative
    //if its ever negative we would want to take a new one so that it isnt as negative
    //add to the one that has the least (cuzt hen u have to take the least) then push that other hoe and call it a day :D
    for(ll i = 0; i<n; i++){
        ll top = pq.top();// always js take the top! its the one that either subtracts least or adds most :D
      //otherwise we push it to the back of our ittle thing (remmeber its like taking the prefix of our thing [afterwards<- which makes sense why we add first], so this is perfectly okay!) 
        score+=top; //add the top prefix 
        pq.pop();
        pq.push(top+A[i]); //push the luh top prefix back in
        //then js take the biggest one so that u etiher add the most or subtract the least at any given moment
        //this will make sure that everything is sorted within our splits (n-1)*ai frfr
        //
    }
    cout<<score<<"\n";
    //we want to greedily
    //we want to greedily take the best one that makes our score better
    //if its pos we want to add it to our score
    //js take the biggest one!


    //say we have k things to place which will add
    //ci to the pref sum at ci+
    //all positve numbers will be taken
    //
}
