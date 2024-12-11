#include <bits/stdc++.h>
using namespace std;

// this was my initial approach during the contest.(text me if anyone can help me here)

// class Solution {
// public:
//     int findMinimumTime(vector<int>& strength, int K) {
//         int n = strength.size();
//         int x =1;
//         int time =0;
//         long long energy=0;
//         map<int,int> mp;
//         for(int i =0;i<n;i++){
//             mp[strength[i]]++;
//         }
//         while(!mp.empty()){
//             energy +=x;
//            // cout<<"Energy"+energy<<endl;
//             auto it = mp.upper_bound(energy);
//             if(it!=mp.begin()){
//                 --it;
             
//                 if(--it->second==0){
//                       mp.erase(it);
//                 }
//                 energy=0;
//                 x+=K;
//                    // cout<<"X"+x << endl;
//             }
           
//             time++;//cout<<"time"+time << endl; 
//         }
//         return time;
        
//     }
// };

// mne solution dekha usme brute force use hua h (check for every permutation and store the minimum time )
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        sort(strength.begin(), strength.end());
        int res = INT_MAX; // minimum time is required
        int n = strength.size();
        vector<int> permutation(n, 0);
        for (int i = 0; i < n; i++) {
            permutation[i] = i;
        }
        do {
            int time = 0;
            int x = 1;
            for (int i = 0; i < n; i++) {
                int s = strength[permutation[i]];
                time += ceil((double)s / (double)x); // to calculate time for this order 
                x += K;
            }
            res = min(res, time);
        } while (std::next_permutation(permutation.begin(), permutation.end()));
        return res;
    }
};

int main() {
    // Example input
    vector<int> strength = {3, 5, 7, 2}; // Example strengths
    int K = 2; // Example value of K
    
    Solution solution;
    int result = solution.findMinimumTime(strength, K);
    
    cout << "Minimum time: " << result << endl;

    return 0;
}