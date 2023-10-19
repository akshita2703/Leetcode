#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool sameStack(stack<int> stack1, stack<int> stack2) {
        bool flag = true;
        if (stack1.size() != stack2.size()) {
            return false;
        }
        while (stack1.empty() == false) {
            if (stack1.top() == stack2.top()) {
                stack1.pop();
                stack2.pop();
            } else {
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool backspaceCompare(string s, string t) {
        stack<int> stack1;
        stack<int> stack2;
        if (s[0] == '#' || t[0] == '#') {
            return true;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                stack1.push(s[i]);
            } else {
                if (stack1.empty()) {
                    continue;
                }
                stack1.pop();
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                stack2.push(t[i]);
            } else {
                if (stack2.empty()) {
                    continue;
                }
                stack2.pop();
            }
        }
        bool ans = sameStack(stack1, stack2);
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "ab#c";
    string t = "ad#c";
    bool result = solution.backspaceCompare(s, t);
    if (result) {
        cout << "The two strings are equal after applying backspace." << endl;
    } else {
        cout << "The two strings are not equal after applying backspace." << endl;
    }
    return 0;
}
