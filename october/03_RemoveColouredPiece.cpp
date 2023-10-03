// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/?envType=daily-question&envId=2023-10-02

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> c;
        for (auto it = colors.begin(); it != colors.end();) {
            char x = *it;
            auto t = it;
            while (t != colors.end() && *t == x) {
                t++;
            }
            c[x] += max(int(distance(it, t) - 2), 0);
            it = t;
        }
        if (c['A'] > c['B']) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string input;
    
    // Input the colors string
    cout << "Enter the colors string (e.g., 'AAABBB'): ";
    cin >> input;

    bool result = solution.winnerOfGame(input);

    if (result) {
        cout << "Player A wins!" << endl;
    } else {
        cout << "Player B  win." << endl;
    }

    return 0;
}
