#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
public:
    FastReader() {}

    string next() {
        string s;
        cin >> s;
        return s;
    }

    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastReader in;
    int n = in.nextInt();
    set<int> left;
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++) {
        left.insert(i);
    }

    int q = in.nextInt();
    while (q-- > 0) {
        int l = in.nextInt() - 1;
        int r = in.nextInt() - 1;
        int win = in.nextInt();

        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            int curr = *it;
            answer[curr] = win;
            it = left.erase(it); // Remove current and get next iterator
        }
        answer[win - 1] = 0;
        left.insert(win - 1);
    }

    stringstream ans;
    for (int i = 0; i < n; i++) {
        ans << answer[i];
    }
    cout << ans.str() << endl;

    return 0;
}

// <END-OF-CODE>
