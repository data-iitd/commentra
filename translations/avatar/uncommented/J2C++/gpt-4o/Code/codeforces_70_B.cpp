#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n
    string input;
    getline(cin, input);
    
    int max = -1;
    vector<int> msgLength(input.length() / 2);
    int count = 0;
    int idx = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == '.' || c == '?' || c == '!') {
            msgLength[idx++] = ++count;
            if (count > max) max = count;
            i++; // Skip the punctuation
            count = 0;
        } else {
            count++;
        }
    }

    if (max > n) {
        cout << "Impossible" << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < idx; i++) {
            int l = msgLength[i];
            while (i < idx - 1 && l + msgLength[i + 1] + 1 <= n) {
                l += msgLength[i + 1] + 1;
                i++;
            }
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}

// <END-OF-CODE>
