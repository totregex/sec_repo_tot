#include<bits/stdc++.h>
using namespace std;
double recPow(double x,double k,int n,int i=1){
        if(i==n-1) return x*k;
        if(i==n+1) return x/k;
        recPow(x*x,k,n,i*2);
}
double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        if(n==0) return 1;
        if(n==1) return x;
        // double pow=1;
        // if(n<0){
        //    x=1/x;
        // }
        // while(n!=0){
        //     if(n%2) pow*=x;
        //     x*=x;
        //     n/=2;
        // }
        
        // return pow;
        return recPow(x,x,n);
}
int main(){
    cout<<myPow(9,4);
    return 0;
}