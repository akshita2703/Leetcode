#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                std::reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
        std::reverse(s.begin() + i, s.end());

        return s;
    }
};

int main() {
    using namespace std;

    Solution solution;
    string input = "Hello World";
    string reversed = solution.reverseWords(input);

    cout << "Original: " << input << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}
