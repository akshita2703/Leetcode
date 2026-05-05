https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int countdays(vector<int>& weights,int m){
        int count = 1;
        int sum =0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=m){
                sum+=weights[i];
            }
            else {
                count++;
                sum=weights[i];
            }
            
        }
        return count ;
    }
    int findMinHour(vector<int>& weights, int days,int s,int e){
        int possibleans = 0;
        int m = 0;
        while (s<=e){
            m = s+(e-s)/2;
            if(countdays(weights,m)<=days){
                possibleans = m;
                e=m-1;
            }
            else{
                s = m+1;
            }
        }
        return possibleans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxi =0;
        for(int i =0;i<weights.size();i++){
            maxi = max(maxi,weights[i]);
            sum+=weights[i];
        }
        int minhour = findMinHour(weights,days,maxi,sum);
        return minhour;
        
    }
};