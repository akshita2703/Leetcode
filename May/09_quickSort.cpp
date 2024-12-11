#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low , int high){
//{10,7,8,9,1,5}  pivot = 5 i = -1 
//{1,5 ,8,9,10,7} pivot = 7 i = 1
//{1,5,7,9,10,8} pivot = 8 i = 2 
// {1 5 7 8 10 9 } pivot = 9 i = 3

    int pivot = arr[high]; 
    int i =low-1;
    for(int j = low;j<=high;j++){
        if(arr[j]<pivot){
            i++; // 0 
            swap(arr[i],arr[j]); //{1,7,8,9,10,5}
        }

    }
    swap(arr[i+1],arr[high]);  // {{1}......,{5},......{8,9,10,7}}
    //{1 5} {7} { 9 10 8 }
    // {1 5 7 8 10 9 }    return 3 krenge
    // {1 5 7 8 9 10}
    return i+1;

}

void quickSort(int arr[],int i , int n){
    if(i>n)return ;

    
    int p = partition(arr,i,n);  //{} 0 5 p= 1  ... p = 2 
    quickSort(arr,i,p-1);  // arr 0,0
    quickSort(arr,p+1,n); // arr 2 5 
   

    
}

int main(){
    int arr[]={10,7,8,9,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}