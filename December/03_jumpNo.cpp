#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    int sum = 0;
    while (arr.size() > 1) {
        int idx = arr.size() - 1;
        if (arr.size() % 2 == 0) {
            idx--;
        }
        for (int i = idx; i >= 0; i -= 2) {
            sum += arr[i];
            arr.erase(arr.begin() + i);
        }
    }

    cout << sum << endl;

    return 0;
}
