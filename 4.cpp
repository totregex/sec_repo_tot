#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
//     int lengthOfLongestSubstring(string s){
//         if(s=="") return 0;
//         if(s.length()==1) return 1;
//         int cnt=0, mx=0;
//         map<char,int>mp;
//         int i=0;
//         while(i<s.length()){
//             if(mp[s[i]]!=1){
//                 ++mx;
//                 mp[s[i]]=1;
//                 ++i;
//             }
//             else if(mp[s[i]]==1){
//                 mp.clear();
//                 mx=0;
//                 char c=s[i];
//                 while(i>=0 && s[i-1]!=c){
//                     --i;
//                 }
//             }
//             cnt=max(cnt,mx);
//         }
//         return cnt;
//     }
//     int maxsum(int* arr,int n){
//         int sum=0,mx=0;
//         for(int i=0;i<n;i++){
//             mx+=arr[i];
//             sum=max(mx,sum);
//             if(mx<0) mx=0;
//         }
//         return sum;
//     }
};
void sort(int* arr,int n){
    for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int fib(long n,unordered_map<long,long> &mp){
    if(n<=2) return 1;
    if(n==0) return 0;
    if(mp.find(n)!=mp.end()) return mp[n];
    mp[n]=fib(n-1,mp) + fib(n-2,mp);
    return mp[n];
}
int fibb(int n){ 
    if(n<=2) return 1;
    if(n==0) return 0;
    return fibb(n-1) + fibb(n-2);
}

void rev(char* s,int n){
    int i=0;
    while(i<n/2){
        char temp=s[i];
        s[i]=s[n-i-1];
        s[n-i-1]=temp;
        ++i;
    }
}
bool canSum(int* arr,int n,int k,map<int,bool>& dp,vector<int>&vec){
    if(dp.find(n)!=dp.end()) return dp[n];
    if(n==0) return true;
    for(int i=0;i<k;i++){
        if(arr[i]<=n){
            if(canSum(arr,n-arr[i],k,dp,vec)){
                dp[n]=true;
                vec.push_back(arr[i]);
                return dp[n];
            }
        }
    }
    dp[n]=false;
    return dp[n];
}
bool canSumm(int* arr,int n,int k){
    if(n==0) return true;
    for(int i=0;i<k;i++){
        if(arr[i]<=n){
            if(canSumm(arr,n-arr[i],k)){
                return true;
            }
        }
    }
    return false;
}
bool howSum(int* arr,int n,int k,vector<int>& vec){
    vec.clear();
    if(n==0) return true;
    for(int i=0;i<k;i++){
        if(n>=arr[i]){
            if(howSum(arr,n-arr[i],k,vec)){
                vec.push_back(arr[i]);
                return true;
            }
        }
    }
    return false;
}
bool canReach(int* arr,int n,int index,map<int,bool> &dp){
    if(dp.find(index)!=dp.end()) return dp[index];
    if(index==n-1) return true;
    if(arr[index]==0){
        dp[index]=0;
        return dp[index];
    }
    for(int i=1;i<=arr[index];i++){
        if(canReach(arr,n,index+i,dp)){
            dp[index]=true;
            return dp[index];
        }
    }
    dp[index]=false;
    return dp[index];
}
int ways(int n){
    if(n==2) return 1;
    if(n==1) return 1;
    if(n<=0) return 0;
    int p=ways(n-1);
    int q=ways(n-2);
    int m=0;
    m+=p;
    int j=0;
    j+=q;
    return min(m,j);
}
vector<char>vec={};
bool contains(string a,string b){
    int p=a.length(),q=b.length();
    int i=0;
    while(i<p){
        if(a[i]==b[0]){
            int j=0,t=i,f=0;
            while(j<q && t<p){
                if(a[t]==b[j]){
                    cout<<a[t]<<"=="<<b[j]<<endl;
                    ++f;
                }
                ++j;
                ++t;
            }
            cout<<endl<<"*********"<<endl;
            if(f==q) return true;
        }
        ++i;
    }
    return false; 
}
int gridTraveller(int m,int n){
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;
    int p=gridTraveller(m-1,n) ;
    int q=gridTraveller(m,n-1);
    return p+q;
}
vector<vector<string>> allConstruct(string s,vector<string> vec){
    if(s=="") return {{}};
    vector<vector<string>> res={};
    for(size_t i=0;i<vec.size();i++){
        if(s.find(vec[i])==0){
            vector<vector<string>> p=allConstruct(s.substr(vec[i].length(),s.length()-vec[i].length()),vec);
            for(auto &j:p){
                j.push_back(vec[i]);
            }
            res.insert(res.end(),p.begin(),p.end());
        }
    }
    return res;
}
// vector<string> vec={"pu","rp","le","purp","purple"};
// string s="purple";
// vector<int> vec1={1,2,0,3,0};
// map<int,int>dp={};
// int arr[]={1,2,0,3,0};
// int s=sizeof(arr)/sizeof(int);
auto func(){
    vector<vector<int>> p={{1,2},{3,4},{5,6},{7,8}};
    for(vector<int> i: p){
        i.push_back(69);
    }
    return p;
}
void perms(string s, string a,size_t n,vector<string> &vec,map<string,bool>&mp){
    if(a.length()==n && mp[a]==false){
        mp[a]=true;
        vec.push_back(a);
        return;
    }
    for(size_t i=0;i<s.length();i++){
        string p=s;
        string l=a;
        l+=p[i];
        p.erase(i,1);
        perms(p,l,n,vec,mp);
    }
}
void swap(int i,int j,string &s){
    char temp=s[i];
    s[i]=s[j];
    s[j]=temp;
}
void solve(int n,string &s, vector<string>&vec){
    if(n==s.length()-1){
        vec.push_back(s);
    }
    for(int i=n;i<s.length();i++){
        swap(n,i,s);
        solve(n+1,s,vec);
        swap(n,i,s);
    }
}
vector<string> permutes(string s){
    vector<string>ans={};
    solve(0,s,ans);
    return ans;
}
string kSwaps(string s,int k){
    //This greedy approach falis for the input like 4577 so we switch to the below backtracking apporach(which we couldn't implement properly sorry
    int c=0;
    for(int i=0;i<s.length()-1;i++){
        int mx=s[i],mxi=i;
        for(int j=i+1;j<s.length();j++){
            if(s[j]>=mx) mx=s[j],mxi=j;
        }
        if(mxi!=i){
            swap(i,mxi,s);
            ++c;
        }
        if(c==k) break;
    }
    return s;
}
void solvee(string &s,int n,string &ans){
    if(n==s.length()-1){
        if(ans!=""){
            for(int i=0;i<ans.length();i++){
                if(s[i]>ans[i]){
                    ans=s;
                    return;
                }
            }
        }else{
            ans=s;
            return;
        }
    }
    for(int i=n+1;i<s.length();i++){
        if(s[i]>s[n]){
            swap(n,i,s);
            solvee(s,n+1,ans);
            swap(n,i,s);
        }
    }
}
string kSwapsBT(string &s){
    string ans="";
    solvee(s,0,ans); 
    return ans;
}
int myPow(int x,int n){
    int p=1;
    while(n){
        if(n%2){
        p*=x;
        }
        x*=x,n/=2;
    }
    return p;
}
int recPow(int x,int k,int n,int i=1){
    if(i==n-1) return x*k;
    if(n==n+1) return x/k;
    recPow(x*x,k,n,i*2);
}
void helper(vector<vector<int>> &res, vector<int> &temp, const vector<int> &nums, int idx,map<vector<int>,bool>&mp) {
        if(!mp[temp]) res.push_back(temp),mp[temp]=true;
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(res, temp, nums, i + 1,mp);
            temp.pop_back();
        }
}
vector<vector<int>> subsets(const vector<int> &nums) {
    map<vector<int>,bool>mp;
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, nums, 0,mp);
    return res;
}
void solve(vector<vector<int>>&ans,vector<int>&nums,int i,map<int,bool>&mp){
    if(i==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++){
        if(!mp[nums[j]]) mp[nums[j]]=true;
        else continue;
        swap(nums[i],nums[j]);
        solve(ans,nums,i+1,mp);
        swap(nums[i],nums[j]);
    }
}
vector<vector<int>> frazperms(vector<int>&nums){
    vector<vector<int>>ans={};
    map<int,bool>mp;
    solve(ans,nums,0,mp);
    return ans;
}
bool solve(string&s,int i,int e){
    if(i>=e) return true;
    if(s[i]!=s[e]) return false;
    return solve(s,i+1,e-1);
}
bool recpal(string s){
    return solve(s,0,s.length()-1);
}
void solver(vector<vector<int>>&ans,vector<int>&nums,int i,vector<int>&temp){
    if(i==nums.size()){
        if(find(ans.begin(),ans.end(),temp)==ans.end()) /*
        help me 
        I'm losing my patience level becuase i'm writing a code right now i speculate a lizard is hovering back my head!
        */ans.push_back(temp);
        return;
    }
    for(size_t j=0;j<nums.size();j++){
        //swap(nums[i],nums[j]);
        temp.push_back(nums[j]);
        solver(ans,nums,i+1,temp);
        temp.pop_back();
        //swap(nums[i],nums[j]);
    }
}
vector<vector<int>> myperms(vector<int>&vec){
    vector<vector<int>> ans={};
    vector<int>temp={};
    solver(ans,vec,0,temp);
    return ans;
}
void solvecomb(vector<vector<int>> &ans,vector<int>&temp,vector<int>&nums,int k,int i){
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    if(temp.size()+(nums.size()-i)<k) return;
    if(i==nums.size()){
        return;
    }
    temp.push_back(nums[i]);
    solvecomb(ans,temp,nums,k,i+1);
    temp.pop_back();
    solvecomb(ans,temp,nums,k,i+1);
}
vector<vector<int>> combs(vector<int>&nums,int k){
    vector<vector<int>>ans={};
    vector<int>temp={};
    solvecomb(ans,temp,nums,k,0);
    return ans;
}

void sol(vector<vector<int>>&ans,vector<int>&nums,vector<int>&temp,int sum,int i){
    if(sum<0) return;
    if(sum==0){
        ans.push_back(temp);
        return;
    }
    if(i==nums.size()){
        return;
    }
    temp.push_back(nums[i]);
    sol(ans,nums,temp,sum-nums[i],i);
    temp.pop_back();
    sol(ans,nums,temp,sum,i+1);
}

vector<vector<int>> sumCombs(vector<int>&nums,int sum) {
    vector<vector<int>>ans={};
    vector<int>temp={};
    sol(ans,nums,temp,sum,0);
    return ans;
}
void soll(vector<vector<int>>&ans,vector<int>&nums,vector<int>&temp,int i){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    i%=nums.size();
    temp.push_back(nums[i]);
    soll(ans,nums,temp,i);
}


vector<vector<int>> AllCombs(vector<int>&nums) {
    vector<vector<int>>ans={};
    vector<int>temp={};
    soll(ans,nums,temp,0);
    return ans;
}
void swap(char*a,char*b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

void solvecom(vector<string>&ans,string&s,int k,int i,string&temp,int p){
    if(temp.size()==k) {
        ans.push_back(temp);
        return;
    }
    if(i==p){
        return;
    }
    if(temp.size()+p-i<k) {
        cout<<endl<<"[%%% "<<temp<<i<<" %%%]"<<endl;
        return;
    }
    temp+=s[i];
    solvecom(ans,s,k,i+1,temp,p);
    temp.pop_back();
    solvecom(ans,s,k,i+1,temp,p);
}
vector<string> allcombs(string&s,int k){
    vector<string>ans={};
    string temp="";
    solvecom(ans,s,k,0,temp,s.length());
    return ans;

}
//Commented code for all the n^n combinations.
///Non-Commented code for all the n! permutations.
void solvepermutes(vector<string>&vec,string&s,string&temp,int k){
    if(temp.size()==k){
        vec.push_back(temp);
        return;
    }
    for(size_t i=0;i<s.length();i++){
        temp+=s[i];
        //s.erase(i,1);
        solvepermutes(vec,s,temp,k);
        //s.insert(i,1,temp[temp.size()-1]);
        temp.erase(temp.size()-1,1); 
    }
}
vector<string> permutess(string&s){
    vector<string>ans={};
    string temp="";
    solvepermutes(ans,s,temp,s.size());
    return ans;
}
void solvecomb3(int n,vector<vector<int>>&ans,int i,vector<int>&temp,int k){
    if(temp.size()==n){
        if(k==0){
            ans.push_back(temp);
        }
        return;
    }
    if(k<0) return;
    if(i>9) return;
    temp.push_back(i);
    solvecomb3(n,ans,i,temp,k-i);//for i+1 this will create vectors with all unique elements.
    temp.pop_back();
    solvecomb3(n,ans,i+1,temp,k);// here i+1 makes sure that the repeating elements are not pushed back into the combination because if we need the current element again then we would have gone the another way that is specified above as we only have two choices either to choose the current element(keeping the pointer to the current element only) or ignore it(move the pointer to the next element)
}
vector<vector<int>> comb3(int n,int k){
    vector<vector<int>> ans={};
    vector<int>temp={};
    solvecomb3(n,ans,1,temp,k);
    return ans;
}
void solvephone(vector<string>&ans,string&s,string&temp,int i){
    if(i==s.length()){
        ans.push_back(temp);  
        return;
    }
    int n=s[i]-'0';
    if(n!=9 && n!=7){
        for(size_t j=0;j<3;j++){
            temp+=((n-2)*3 + 'a' + j);
            solvephone(ans,s,temp,i+1);
            temp.pop_back();
        }
    }else if(n==9){
        for(size_t j=0;j<4;j++){
            temp+=((n-2)*3 + 'a' + j);
            solvephone(ans,s,temp,i+1);
            temp.pop_back();
        }
    }else if(n==7){
        for(size_t j=0;j<4;j++){
            temp+=((n-2)*3 + 'a' + j);
            solvephone(ans,s,temp,i+1);
            temp.pop_back();
        }
    }
}
vector<string> phonecombs(string&s){
    vector<string> ans={};
    string temp="";
    solvephone(ans,s,temp,0);;
    return ans;
}
/*A
BC
DEF
GHIJ
KLMNO*/
void print(int n){
    int c=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<char('A'+c);
            ++c;
        }
        cout<<endl;
    }
}
void bubble(int*arr,int n){
    for(size_t i=n-1;i>0;i--){
        for(size_t j=0;j<i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
map<int,bool>mp;
bool solveESP(vector<int>&nums,int k,int partSum,int fix,vector<int>&temp,vector<vector<int>>&ans,int i,int bucketNum,map<int,bool>&mp){
    if(partSum==0){
        if(bucketNum==k) return true;
        return solveESP(nums,k,fix,fix,temp,ans,0,bucketNum+1,mp);
    }
    if(bucketNum>k || partSum<0 || i>=nums.size()) return false;
    if(mp[nums[i]]){
        return solveESP(nums,k,partSum,fix,temp,ans,i+1,bucketNum,mp);
    }
    else{
        cout<<":"<<nums[i]<<":";
        mp[nums[i]]=true;
        if(solveESP(nums,k,partSum-nums[i],fix,temp,ans,i+1,bucketNum,mp)) return true;
        mp[nums[i]]=false;
        if(solveESP(nums,k,partSum,fix,temp,ans,i+1,bucketNum,mp)) return true;
        return false;
    }
}
bool equalSumPartitions(vector<int>&nums,int k){
    int sum=0;
    for(int i:nums)sum+=i;
    if(sum%k!=0) return false;
    vector<vector<int>> ans={};
    vector<int>temp={};
    int partSum=sum/k;
    int fix=partSum;
    return solveESP(nums,k,partSum,fix,temp,ans,0,1,mp);
}
bool overlap(vector<int>&chars,string&s){
    set<char>st;
    for(int i=0;i<s.size();i++){
        if(chars[s[i]-'a']==1) return true;
        if(!st.insert(s[i]).second) return true;
    }
    return false;
}

void solvecon(int i,int temp,vector<string>&strings,int* ans,vector<int>&chars){
    if(i==strings.size()){
        *ans=max(*ans,temp);
        return;
    }
    if(overlap(chars,strings[i])){
        solvecon(i+1,temp,strings,ans,chars);
    }
    else{
        for(int j=0;j<strings[i].size();j++){
            chars[(strings[i])[j]-'a']=1;
        }
        solvecon(i+1,temp+strings[i].size(),strings,ans,chars);
        for(int j=0;j<strings[i].size();j++){
            chars[(strings[i])[j]-'a']=0;
        }
        solvecon(i+1,temp,strings,ans,chars);
    }
}
int conct(vector<string>&strings){
    int ans=0;
    vector<int> chars(26,0);
    solvecon(0,0,strings,&ans,chars);
    return ans;
}

void solvegenPar(string&temp,vector<string>&ans,int O,int C){
    if(O==0 && C==0){
        ans.push_back(temp);
        return;
    }
    if(O==C){
        temp+='(';
        solvegenPar(temp,ans,O-1,C);
        temp.pop_back();
    }else{
        if(O!=0){
            temp+='(';
            solvegenPar(temp,ans,O-1,C);
            temp.pop_back();
        }
        if(C!=0){
            temp+=')';
            solvegenPar(temp,ans,O,C-1);
            temp.pop_back();
        }
    }
}
vector<string> genPar(int n){
    vector<string> ans={};
    string temp="";
    int O=n,C=n;
    solvegenPar(temp,ans,O,C);
    return ans;
}
void solveseq(vector<string>&ans,string&s,int i,int fix,char&save,string&temp){
    if(i>=fix){
        ans.push_back(temp);
        return;
    }
    temp+=s[i];
    solveseq(ans,s,i+1,fix,save,temp);
    temp.pop_back();
    solveseq(ans,s,i+1,fix,save,temp);
}
vector<string> subseq(string&s){
    vector<string>ans={};
    int fix=s.size();
    char save;
    string temp="";
    solveseq(ans,s,0,fix,save,temp);
    return ans;
}
bool solvep(vector<vector<char>>&board,int k,string&s,int i,int j){
    if(k==s.size()) return true;
    if(i<0 || j<0 || i==board.size() || j==board[0].size()) return false;
    if(board[i][j]!=s[k]) return false;
    bool c1= solvep(board,k+1,s,i+1,j);
    bool c2= solvep(board,k+1,s,i-1,j);
    bool c3= solvep(board,k+1,s,i,j+1);
    bool c4= solvep(board,k+1,s,i,j-1);
    return c1||c2||c3||c4;
}
bool present(vector<vector<char>>&board,string s){
    int i=0,j=0,f=0;
    for(i=0;i<board.size();i++){
        for(j=0;j<board[0].size();j++){
            if(board[i][j]==s[0]){
                f=1;
                break;
            }
        }
        if(f) break;
    }
    if(!f) return false;
    cout<<i<<j;
    return solvep(board,0,s,i,j);
}
void solverat(int i,int j,vector<vector<int>>&maze,vector<string>&ans,string&temp){
    if(i<0 || j<0 || i>=maze.size() || j>=maze[0].size() || maze[i][j]!=1) return ;
    if(i==maze.size()-1 && j==maze[0].size()-1) {
        ans.push_back(temp);
    }
    int save=maze[i][j];
    maze[i][j]=0;
    temp+='D';
    solverat(i+1,j,maze,ans,temp);
    temp.pop_back();
    temp+='R';
    solverat(i,j+1,maze,ans,temp);
    temp.pop_back();
    temp+='U';
    solverat(i-1,j,maze,ans,temp);
    temp.pop_back();
    temp+='L';
    solverat(i,j-1,maze,ans,temp);
    temp.pop_back();
    maze[i][j]=save;
}
vector<string> rat(vector<vector<int>>&maze){
    vector<string>ans={};
    string temp="";
    solverat(0,0,maze,ans,temp);
    return ans;
}

void solvenq(vector<vector<vector<int>>>&ans,vector<vector<int>>&temp,int rows,int cols,vector<int>&r,vector<int>&c,vector<int>&d1,vector<int>&d2,int n){
    if(cols==n) return;
    if(rows==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(c[i]==0 && d2[rows-i + n-1]==0 && d1[rows+i]==0){
            temp.push_back({rows,i});
            c[i]=d1[rows+i]=d2[rows-i + n-1]=1;
            solvenq(ans,temp,rows+1,i,r,c,d1,d2,n);
            temp.pop_back();
            c[i]=d1[rows+i]=d2[rows-i + n-1]=0;
        }
    }
}
vector<vector<vector<int>>> nqueen(int n){
    vector<vector<int>> temp={};
    vector<int> d1(2*n-1,0),d2(2*n -1,0),r(n,0),c(n,0);
    vector<vector<vector<int>>> ans={};
    solvenq(ans,temp,0,0,r,c,d1,d2,n);
    return ans;
}
void solverob(int&ans,vector<int>&loot,int i,map<int,int>&mp,int temp){
     if (mp.find(i) != mp.end()) {
        ans = 8;
        return;
    }
    if(i>=loot.size()){
        ans=max(temp,ans);
        return;
    }
    solverob(ans,loot,i+2,mp,temp+loot[i]);
    solverob(ans,loot,i+1,mp,temp);
    mp[i] = ans - temp;
}
int rob(vector<int>&loot){
    map<int,int>mp;
    int ans=0;
    vector<int>looted(loot.size(),0);
    solverob(ans,loot,0,mp,0);
    return ans;
}
void help(int& a,int n){
    cout<<&a<<endl;
    if(n==0) return;
    a+=1;
    help(a,n-1);
}

int longest(vector<int>&nums){
    int i=0;
    int mx=1,c=1;
    while(i+1<nums.size()){
        if(nums[i+1]>=nums[i]){
            c=1;
            while(i+1<nums.size() && nums[i+1]>nums[i]){
                c++;
                i++;
            }
            mx=max(mx,c);
            i--;
        }
        i++;
    }
    return mx;
}

// int longest(std::vector<int>& nums) {
//     if (nums.empty()) {
//         return 0; // Handle the case where the vector is empty
//     }

//     int n = nums.size();
//     std::vector<int> lis; // Longest Increasing Subsequence array

//     for (int i = 0; i < n; ++i) {
//         auto it = std::lower_bound(lis.begin(), lis.end(), nums[i]);
//         if (it == lis.end()) {
//             lis.push_back(nums[i]);
//         } else {
//             *it = nums[i];
//         }
//     }

//     return lis.size();
// }

int main(){
    vector<int> vec={4,3,2,5,6,7,8,9,4,5,6,7,2,3,4,0,1,2,3,4,5,6};
    cout<<longest(vec);
    // int k=9;
    // cout<<&k<<endl;
    // help(k,4);
    // cout<<&k<<endl;
    // cout<<k;

    // reverse(vec.end()-2,vec.end());
    // reverse(vec.begin(),vec.end()-2);
    // reverse(vec.begin(),vec.end());
    // for(auto i:vec) cout<<i<<" ";
    // vector<vector<int>>board={{1,1,1,1},{1,0,0,0},{1,1,1,1},{1,1,1,1}};
    // vector<string>ans=rat(board);
    // for(auto i:ans){
    //     cout<<"["<<i<<"] ";
    // }
    // vector<vector<vector<int>>> ans=nqueen(2);
    // for(auto vec:ans){
    //     for(auto out:vec){
    //         cout<<"[";
    //         for(int j=0;j<out.size();j++){
    //             cout<<out[j];
    //             if(j<out.size()-1) cout<<",";
    //         }
    //         cout<<"] ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}