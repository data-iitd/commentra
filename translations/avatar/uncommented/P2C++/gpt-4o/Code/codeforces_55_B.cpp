#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void rememberTheNumber(vector<int>& nums, int i, vector<char>& operations, vector<long long>& ans) {
    if (i >= 3) {
        return;
    }
    for (int j = 0; j < 4; j++) {
        for (int k = j + 1; k < 4; k++) {
            if (nums[j] != -1 && nums[k] != -1) {
                int s = nums[j];
                nums[j] = -1;
                int t = nums[k];
                if (operations[i] == '+') {
                    nums[k] = s + t;
                } else if (operations[i] == '*') {
                    nums[k] = s * t;
                }
                if (i == 2 && nums[k] < ans[0]) {
                    ans[0] = nums[k];
                }
                rememberTheNumber(nums, i + 1, operations, ans);
                nums[j] = s;
                nums[k] = t;
            }
        }
    }
}

int main() {
    vector<int> nums(4);
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }
    vector<char> operations(3);
    for (int i = 0; i < 3; i++) {
        cin >> operations[i];
    }
    vector<long long> ans(1, numeric_limits<long long>::max());
    rememberTheNumber(nums, 0, operations, ans);
    cout << ans[0] << endl;
    return 0;
}

// <END-OF-CODE>
