#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    string input;
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n
    getline(cin, input);

    int max = -1;
    vector<int> msgLength;
    int count = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == '.' || c == '?' || c == '!') {
            msgLength.push_back(++count);
            if (count > max) max = count;
            i++;
            count = 0;
        } else count++;
    }

    if (max > n) {
        cout << "Impossible" << endl;
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < msgLength.size(); i++) {
        int l = msgLength[i];

        while (i < msgLength.size() - 1 && l + msgLength[i + 1] + 1 <= n) {
            l += msgLength[i + 1] + 1;
            i++;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}

