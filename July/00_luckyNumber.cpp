// after so long i was doing dsa daily question , i was able to solve without taking any help , it feels good altough it was a easy question .

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n);
        vector<int> col(m);
        for(int i =0;i<n;i++){
            int mini = INT_MAX;
            for(int j = 0;j<m;j++){
                mini = min(mini,matrix[i][j]);
            }
            row[i] = mini;
        }
        for(int i =0;i<m;i++){
            int maxi = INT_MIN;
            for(int j = 0;j<n;j++){
                maxi = max(maxi,matrix[j][i]);
            }
            col[i] = maxi;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(row[i]==col[j]){
                    ans.push_back(row[i]);
                }
            }
        }
        return ans;

    }
};