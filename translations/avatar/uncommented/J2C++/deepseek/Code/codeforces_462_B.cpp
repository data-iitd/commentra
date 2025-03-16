#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class c462b {
public:
    int left = 0;
    int compareTo(const c462b& other) const {
        return left - other.left;
    }
};

int main() {
    // ifstream f("input.txt");
    // ofstream out("output.txt");
    stringstream f;
    f << "3 2\nABC"; // Example input
    ofstream out("output.txt");
    string s;
    getline(f, s);
    int n = stoi(s.substr(0, s.find(' ')));
    int k = stoi(s.substr(s.find(' ') + 1));
    vector<c462b> cards(26);
    getline(f, s);
    for (int i = 0; i < n; ++i) {
        cards[s[i] - 'A'].left++;
    }
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        sort(cards.begin(), cards.end());
        long long change = min(cards[25].left, k - i);
        ans += change * change;
        cards[25].left -= change;
        i += change - 1;
    }
    out << ans << endl;
    out.close();
    return 0;
}
