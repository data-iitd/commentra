
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;
    vector<int> counter;

    if (s == "") {
        return 0;
    }
    counter.push_back(0);
    vector<char> li(s.begin(), s.end());

    for (char c : li) {
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            count++;
        } else {
            counter.push_back(count);
            count = 0;
        }
    }

    counter.push_back(count);
    sort(counter.begin(), counter.end());
    cout << counter[counter.size() - 1] << endl;

    return 0;
}
