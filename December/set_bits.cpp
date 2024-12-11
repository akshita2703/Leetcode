
#include<iostream>
using namespace std;

int setKthBit(int N, int K){
    int number = 1;
    while(K!=0){
        number = number * 2;
        K--;
    }
    return (N | number);
}
int main() {
    int result = setKthBit(5, 0);
    cout<<result;
    return 0;
}