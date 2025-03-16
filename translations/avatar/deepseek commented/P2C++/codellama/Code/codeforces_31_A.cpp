
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int y;
    cin >> y;
    vector<int> arr;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            arr.push_back(s[i] - '0');
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < arr.size(); k++) {
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    cout << k + 1 << " " << j + 1 << " " << i + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

