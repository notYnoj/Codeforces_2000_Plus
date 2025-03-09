#include <bits/stdc++.h>

using namespace std;
#define ll long long

template <typename D>
class SegTree{
public:
    ll n;
    vector<D> tree;
    vector<ll> og;
    SegTree(ll size, vector<ll> o){
        n = size;
        tree.resize(4*n);
        og = move(o);
    }
    void build(ll l, ll r, ll u){
        //current node u
        if(l == r){
            D node;
            node.MXc1 = og[l]-l;
            node.MNc1 = og[l]-l;
            node.MXc2 = og[l]+l;
            node.MNc2 = og[l]+l;
            node.ans = 0;
            tree[u] = node;
        }else{
            int mid = (l+r)/2;
            build(l,mid,u*2);
            build(mid+1,r,u*2+1);
            //case 2( max on l)
            D node;
            node.MXc1 = max(tree[u*2].MXc1, tree[u*2+1].MXc1);
            node.MNc1 = min(tree[u*2].MNc1, tree[u*2+1].MNc1);
            node.MXc2 = max(tree[u*2].MXc2, tree[u*2+1].MXc2);
            node.MNc2 = min(tree[u*2].MNc2, tree[u*2+1].MNc2);
            node.ans = max(tree[u*2].ans, tree[u*2+1].ans);
            //Case 1 ( max on r)
            node.ans = max(node.ans, tree[u*2+1].MXc1 - tree[u*2].MNc1);
            //Case 2 (max on l)
            node.ans = max(node.ans, tree[u*2].MXc2 - tree[u*2+1].MNc2);
            tree[u] = node;
        }
    }
    void change(ll l, ll r, ll u, ll new_val, ll pos){
        if(l>pos || r<pos){
            return;
        }
        if(l == r && l == pos){
            //change the val
            D node;
            node.MXc1 = new_val-l;
            node.MNc1 = new_val-l;
            node.MXc2 = new_val+l;
            node.MNc2 = new_val+l;
            node.ans = 0;
            tree[u] = node;
        }else{
            ll tm = (l+r)/2;
            change(l, tm, u*2, new_val, pos);
            change(tm+1, r, u*2+1, new_val, pos);
            //lowk js run it back?
            D node;
            node.MXc1 = max(tree[u*2].MXc1, tree[u*2+1].MXc1);
            node.MNc1 = min(tree[u*2].MNc1, tree[u*2+1].MNc1);
            node.MXc2 = max(tree[u*2].MXc2, tree[u*2+1].MXc2);
            node.MNc2 = min(tree[u*2].MNc2, tree[u*2+1].MNc2);
            node.ans = max(tree[u*2].ans, tree[u*2+1].ans);
            //Case 1 ( max on r)
            node.ans = max(node.ans, tree[u*2+1].MXc1 - tree[u*2].MNc1);
            //Case 2 (max on l)
            node.ans = max(node.ans, tree[u*2].MXc2 - tree[u*2+1].MNc2);
            tree[u] = node;
        }

    }
    ll get(){
        return tree[1].ans;
    }


};

struct D{
    //CASE1:
    ll MXc1, MNc1;
    //CASE2:
    ll MXc2, MNc2;
    ll ans; // in order to have the best of both worlds frfr
};

void solve() {
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n+1);
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    //max(al,al+1,…,ar)−min(al,al+1,…,ar)−(r−l)
    //2 bigger 8 if theres a bigger or smaller number within the range js whip the pointer in and u subtract less
    //so the things are at the beginning or end. So best is at l or r
    //so the max is either on l or r and the min is on the opposite one
    /*
    if max on r
     (a[r] - r) - a[l]+l
     or
    CASE1: (a[r]-r) - (a[l]-l)
     we want info on both the min and max of these two.
     if we are taking the left side we want the minimum
     if we are taking the right side we want the maximum
     if max on l
    CASE2: (a[l]+l) - (a[r]+r)
     so we need data on
     if we are taking the left side we want the maximum
     if we are taking the right side we want the minimum
    */
    SegTree<D> sg(n, arr);
    sg.build(1, n, 1);
    cout<<sg.get()<<'\n';
    for(int i = 0; i<q; i++) {
        ll p,x;
        cin>>p>>x;
        sg.change(1, n, 1, x, p);
        cout<<sg.get()<<'\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
