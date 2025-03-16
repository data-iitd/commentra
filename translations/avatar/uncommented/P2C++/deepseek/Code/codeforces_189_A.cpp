#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cutRibbon() {
    vector<int> arr;
    int length;

    // Read input and store in arr
    string input;
    getline(cin, input);
    size_t pos = 0;
    string token;
    while ((pos = input.find(' ')) != string::npos) {
        token = input.substr(0, pos);
        arr.push_back(stoi(token));
        input.erase(0, pos + 1);
    }
    arr.push_back(stoi(input));

    length = arr[0];
    sort(arr.begin() + 1, arr.begin() + 4, less<int>());

    if (length % arr[0] == 0) {
        cout << length / arr[0] << endl;
        return;
    }

    int ans = 0;
    if (arr[0] == arr[1]) {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; ++i) {
            int check = length - i * arr[2];
            if (check >= 0 && check % arr[0] == 0) {
                k = check / arr[0];
                ans = max(ans, k + i);
            }
        }
    } else {
        int k = 0;
        for (int i = 0; i <= length / arr[2]; ++i) {
            for (int j = 0; j <= length / arr[1]; ++j) {
                int check = length - i * arr[2] - j * arr[1];
                if (check >= 0 && check % arr[0] == 0) {
                    k = check / arr[0];
                    ans = max(ans, k + i + j);
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cutRibbon();
    return 0;
}
