#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> even, odd;
    for (int i = 0; i < s.length(); i += 2) {
        even[s[i]]++;
    }
    for (int i = 1; i < s.length(); i += 2) {
        odd[s[i]]++;
    }
    cout << min(s.length() - (even['0'] + odd['1']), s.length() - (even['1'] + odd['0'])) << endl;
    return 0;
}

