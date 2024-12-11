// Here's the equivalent code in C++ with comments:

#include <iostream>
#include <stack>
using namespace std;

// function to check if the parentheses in a string are
// balanced
int check(string str)
{
	stack<char> s;
	for (auto i : str) {
	
		if (i== '(') {
			s.push('(');
		}
		else if (c == ')') {
			if (s.empty()) {
				return 0;
			}
			else {
				char p = s.top();
				if (p == '(') {
					s.pop();
				}
				else {
					return 0;
				}
			}
		}
	}
	if (s.empty()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	string str = "()(())()";
	if (check(str) == 0) {
		cout << "Invalid" << endl;
	}
	else {
		cout << "Valid" << endl;
	}
	return 0;
}
