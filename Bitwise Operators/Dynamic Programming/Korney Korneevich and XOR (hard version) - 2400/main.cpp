#include <bits/stdc++.h>
using namespace std;
const int mxN = 8193;
template <typename T>
//
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& elem : vec) {
        os << elem << " ";
    }
    return os;
}

// what are we doing->
//were picking from a subarray and saying here lets pick this number and see if we can make something more
//
vector<vector<bool>> ok(5005, vector<bool>(mxN, false)); //optimizing if we have seen this number before in the dp if we have then we can break out as we know that all other numbers above have it
//other than that it also saves time in checking things within the dp
//very good!
//other than that its simple dp, since its increasing lets say we have the final number in the array by arr[i] now for all numbers bigger than this add this one to the dp so they can be checked
//also js add all of the ones weve seen to a seen array and output the answer there


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> dp(mxN);
    vector<bool> seen(mxN);
    seen[0] = true;
    for(int i = 0; i<n; i++ ){ cin>>arr[i]; if(dp[arr[i]].empty()) dp[arr[i]].push_back(0);} //only push 0 back once

    for(int i = 0; i<n; i++){
        int cur = arr[i];
        for(int j = 0; j<dp[cur].size(); j++){
            int nw = dp[cur][j]^cur;
            seen[nw] = true;
            for(int z = cur+1; z<=5001; z++){
                if(ok[z][nw]){break;}
                ok[z][nw] = true;
                dp[z].push_back(nw); //push back
            }
        }
        dp[cur].clear(); //clear so that if we find the same number dont do it again
    }
    int ans = 0;
    vector<int> ans2;
    for(int i = 0; i<mxN; i++){
        if(seen[i]){
            ans++;
            ans2.push_back(i);
        }
    }
    cout<<ans<<endl;
    cout<<ans2<<endl; //cout stuff

  //really easy question only thing that made it hard was optimizing!

}
