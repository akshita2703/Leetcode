
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarysearchfirst(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans1 = -1;
        while (s <= e) {
            int mid = s + ((e - s) / 2);
            if (nums[mid] == target) {
                ans1 = mid;
                e = mid - 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans1;
    }

    int binarysearchlast(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans2 = -1;
        while (s <= e) {
            int mid = s + ((e - s) / 2);
            if (nums[mid] == target) {
                ans2 = mid;
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans2;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = binarysearchfirst(nums, target);
        int last = binarysearchlast(nums, target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = solution.searchRange(nums, target);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

    return 0;
}


