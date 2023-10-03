#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {

        int n = mat.size();
        // int  r1 =0,c1=0;
        int c2 = n-1;
        int sum =0;

        for(int i =0;i<n;i++){
            sum+=mat[i][i] + mat[i][c2-i];
        }
        if(n%2!=0){
            sum = sum - mat[n/2][n/2];
        }
        return sum;
        
    }
};





int main() {
    // Example input matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution solution;
    int result = solution.diagonalSum(mat);
    
    cout << "Diagonal sum: " << result << endl;

    return 0;
}