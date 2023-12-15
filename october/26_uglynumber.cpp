#include <iostream>
#include <stack>
#include <bits/stdc++.h> // This includes all necessary C++ standard library headers.
using namespace std;

class Solution {
public:
    vector<int> primes = {2, 3, 5};
    
    bool isUgly(int n) {
        if (n < 1) return false;
        
        for (int p : primes) 
            while (n % p == 0) 
                n /= p;
        
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n = 2;
    cout<<solution.isUgly(n);
    
    return 0;
}
