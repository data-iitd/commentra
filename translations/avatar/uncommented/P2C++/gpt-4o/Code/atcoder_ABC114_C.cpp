#include <iostream>
#include <set>
#include <string>

using namespace std;

int N;

int aaa(string n) {
    if (stoi(n) > N) {
        return 0;
    }
    set<char> digits(n.begin(), n.end());
    int ans = (digits == set<char>{'7', '5', '3'}) ? 1 : 0;
    for (char i : {'7', '5', '3'}) {
        ans += aaa(n + i);
    }
    return ans;
}

int main() {
    cin >> N;
    cout << aaa("0") << endl;
    return 0;
}

// <END-OF-CODE>
