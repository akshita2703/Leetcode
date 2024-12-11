#include<bits/stdc++.h>
using namespace std;
void funA(int n); // for error 
void funB(int n){
    if(n<=1) return ;
    cout<<n<<" ";
    funA(n/2);
}
void funA(int n){
    if(n<=0) return ;
    cout<<n<<" ";
    funB(n-1);
}
// nestedRecursion
int  fun(int n ){
    if(n>100)return n - 10;
    else{
        return fun(fun(n+11));
    }
    //return 0;
}

int main(){

    //funA(4);
    cout<< fun(95);
    //cout<< ans ;
    return 0;

}