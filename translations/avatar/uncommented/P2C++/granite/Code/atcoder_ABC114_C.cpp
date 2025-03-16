
#include <iostream>
#include <set>
#include <string>
using namespace std;

int N;

int aaa(string n) {
    if (stol(n) > N) {
        return 0;
    }
    int ans = 1;
    if (set<char>(n.begin(), n.end())!= set<char>({'7', '5', '3'})) {
        ans = 0;
    }
    for (char i : "753") {
        ans += aaa(n + i);
    }
    return ans;
}

int main() {
    cin >> N;
    cout << aaa("0") << endl;
    return 0;
}
//END-OF-CODE