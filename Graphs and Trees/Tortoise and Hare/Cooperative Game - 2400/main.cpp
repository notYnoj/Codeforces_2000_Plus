#include <bits/stdc++.h>
using namespace std;
//distance travled mod n = meeting point thus travel n-(slow%n<- easily found) then js make all points reunite and done
int main(){
    auto query1 = [](string to_move) -> vector<string>{
        cout<<"next ";
        for(char c: to_move){
            cout<<c<<' ';
        }
        cout<<endl;
        int k;
        cin>>k;
        vector<string> ans;
        for(int i = 0; i<k; i++){
            string kt;
            cin>>kt;
            ans.push_back(kt);
        }
        return ans;
    };
    int ptr = 0;
    bool br = true;
    while(br){
        vector<string> ans;
        if(ptr%2){
            ans = query1("01");
        }else{
            ans = query1("1");
        }
        if(ptr != 0 && ans.size() == 2){
            br = false;
        }
        ptr++;
    }
    br = true;
    while(br){
        vector<string> ans;
        ans = query1("23456789");
        if(ans.size() == 1){
            br = false;
            break;
        }
    }
    cout<<"done"<<endl;
}
