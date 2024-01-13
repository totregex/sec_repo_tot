#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N,X;cin>>N>>X;
    vector<int> ans(N);
    if(X==0){
        for(int i=1;i<=N;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    int k=(N-X)/2;
    if((N-X)%2 || k==0 || N==0){
        cout<<-1<<endl;
    }
    else if(k<0){
        cout<<-1<<endl;
    }
    else{
        for(int i=1;i<=N;i++){
            ans[i-1]=i;
        }
        reverse(ans.end()-k,ans.end());
        reverse(ans.begin(),ans.end()-k);
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main() {
	int t;cin>>t;
	while(t--){
	    solve();
	}

}
