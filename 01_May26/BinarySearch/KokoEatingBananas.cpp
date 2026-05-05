https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:

    int findMax(vector<int>& piles){
        int n = piles.size();
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi,piles[i]); 
        }
        return maxi;
    }

    int minpossiblespeed(int s , int e,vector<int>& piles,int h){
        int n = piles.size();
        int m = 0;
        int possiblespeed = 0;
        while (s<=e){
            m = s + (e-s)/2;
            long long hsum = 0;
            for(int i =0;i<n;i++){
                hsum+= ceil((1.0 * piles[i])/(1.0*m));
            }
            if(hsum<=h){
                possiblespeed=m;
                e = m-1;
            }
            else {
                s = m+1;
            }
        } 
        return possiblespeed;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = findMax(piles);
        int m = minpossiblespeed(1,maxi,piles,h);
        return m;
        
    }
};