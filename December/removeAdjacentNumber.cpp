//1047. Remove All Adjacent Duplicates In String

//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
   string removeDuplicates(string s) {

        int i=0;

        for(int j=0; j < s.length(); j++, i++){
            s[i] = s[j];
            if( (i > 0) && (s[i] == s[i-1]) ){
                i -= 2;
            }
        }        

        return s.substr(0, i);
    }
};

int main(){
    Solution solution;
    string s="aabbaac";
   cout<< solution.removeDuplicates(s);
    return 0;
}