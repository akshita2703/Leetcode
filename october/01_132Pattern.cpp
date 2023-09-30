#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int length = nums.size();
        // check if the array has less than 3 elements 
        if (length < 3)
            return false;
        // stack to keep track of decreasing elements
        stack<int> decreasingStack;
        // Maximum value of the third element in the 132 pattern
        int maxThirdelement = INT_MIN;
        // Traverse the array from the right to left 
        for (int i = length - 1; i >= 0; i--) {
            int currentNumber = nums[i];

            // check for 132 pattern
            if (currentNumber < maxThirdelement)
                return true;
            // maintain the stack with decreasing elements
            while (!decreasingStack.empty() && decreasingStack.top() < currentNumber) {
                maxThirdelement = decreasingStack.top();
                decreasingStack.pop();
            }

            // push the current element onto the stack 
            decreasingStack.push(currentNumber);
        }
        return false;
    }
};

int main() {
    // Example usage of the find132pattern function
    vector<int> nums = {3, 1, 4, 2};
    Solution solution;
    bool result = solution.find132pattern(nums);

    if (result) {
        cout << "The 132 pattern exists in the array." << endl;
    } else {
        cout << "The 132 pattern does not exist in the array." << endl;
    }

    return 0;
}
