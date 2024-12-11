
//1582. Special Positions in a Binary Matrix - https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

#include <iostream>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans=0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row_s(m);
        vector<int> col_s(n);

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
               row_s[i]+=mat[i][j];
               col_s[j]+=mat[i][j];
            }
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(mat[i][j]==1 && row_s[i]==1 && col_s[j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<vector<int>> vec = {{1,0,0},{0,0,1},{0,0,0}};
    cout<<obj.numSpecial(vec);
}