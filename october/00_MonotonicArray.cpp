#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) inc = false;
            if (nums[i] < nums[i + 1]) dec = false;
            if (dec == false && inc == false) return false;
        }
        return true;
    }
};



int main() {
    std::vector<int> nums = {1, 2, 2, 3}; // Replace this with your input
    Solution solution;
    bool result = solution.isMonotonic(nums);
    if (result) {
        cout << "The array is monotonic." << endl;
    } else {
        cout << "The array is not monotonic." << endl;
    }
    return 0;
}