#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a;
    cin >> a;
    if (a.find("1") == string::npos) {
        cout << 0 << endl;
    } else {
        vector<int> counts;
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '1') {
                counts.push_back(count);
                count = 0;
            } else {
                count++;
            }
        }
        counts.push_back(count);
        cout << accumulate(counts.begin(), counts.end(), 1, multiplies<int>()) << endl;
    }
    return 0;
}

