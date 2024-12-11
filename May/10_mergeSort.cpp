#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    int left = low;// starting of left array
    int right = mid+1;// starting of right array 
    vector<int> temp;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
    
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i =low;i<=high;i++){
        arr[i] = temp[i-low];
    }


}

void mergeSort(vector<int>&arr,int low , int high){
    if(low>=high) return ;
    int mid = (low+high)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    vector<int> arr = {2,4,3,1,0,6};
    mergeSort(arr,0,5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    
}
