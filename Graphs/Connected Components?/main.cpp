#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5+5;
int par[mxN], sizes[mxN];
set<int> grid[mxN];
int find(int a){
    if(par[a] == a){
        return a;
    }else{
        return par[a] = find(par[a]);
    }
}
void merge(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x<y){
        sizes[x] += sizes[y];
        par[y] = x;
    }else{
        sizes[y]+=sizes[x];
        par[x] = y;
    }
}
void dfs(int u, set<int>& st){
    stack<int> stk;
    stk.push(u);
    st.erase(u);

    while(!stk.empty()) {
        int node = stk.top();
        stk.pop();
        for (auto i = st.begin(); i != st.end();) {
            if (grid[node].count(*i)) {
                i++;
            } else {
                merge(node, *i);
                stk.push(*i);
                st.erase(i++);
            }
        }
    }


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    set<int> st;
    for(int i =0; i<n; i++){
        st.insert(i);
        par[i] = i;
        sizes[i] = 1;
    }

    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        grid[a].insert(b);
        grid[b].insert(a);
    }
    for(int i = 0; i<n; i++){
        if(st.count(i)){
            dfs(i, st);
        }
    }

    int a = 0;
    vector<int> b;
    vector<bool> seen(n, false);
    for(int i = 0; i<n; i++){
        if(!seen[find(i)]){
            a++;
            b.push_back(sizes[find(i)]);
            seen[find(i)] = true;
        }
    }
    assert(a == b.size());
    cout<<a<<"\n";
    sort(b.begin(), b.end());
    for(int i : b){
        cout<<i<<' ';
    }
}
