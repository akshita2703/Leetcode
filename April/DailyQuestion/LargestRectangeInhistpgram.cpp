#include<bits/stdc++.h>
using namespace std;

 int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    stack<int> st;
    int leftArr[n],rightArr[n];
    for(int i =0;i<n;i++){
        while (!st.empty() && heights[st.top()]>=heights[i])
        {
           st.pop();
        }
        

        if(st.empty()) leftArr[i]=0;
        else{
            leftArr[i] = st.top()+1;
        }
        st.push(i);
    }
    while(!st.empty()) st.pop();

    for(int i =n-1;i>=0;i--){
        while (!st.empty() && heights[st.top()]>=heights[i])
        {
           st.pop();
        }
        

        if(st.empty()) rightArr[i]=n-1;
        else{
            rightArr[i] = st.top()-1;
        }
        st.push(i);
    }
    int ans =0;
    for(int i =0;i<n;i++){
        int area = (rightArr[i]-leftArr[i]+1)*heights[i];
        ans = max(ans,area);

    }
    return ans;
 }

int main(){
    int n;
    cin>>n;
    vector<int> heights;
    for(int i =0;i<n;i++){
        int k ;
        cin>>k;
        heights.push_back(k);
    }
    int ans = largestRectangleArea(heights);
    cout<<ans<<endl;

    return 0;

}