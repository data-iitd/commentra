
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Scanner {
private:
    string buf;
    int p;

public:
    Scanner() {
        buf = "";
        p = 0;
    }

    string next() {
        p = buf.find_first_of(" ");
        string res = buf.substr(0, p);
        buf = buf.substr(p + 1);
        return res;
    }

    string nextLine() {
        p = buf.size();
        string res = buf;
        buf = "";
        return res;
    }

    int nextInt() {
        string num = next();
        int res;
        stringstream ss;
        ss << num;
        ss >> res;
        return res;
    }
};

int main() {
    Scanner sc;
    int x = sc.nextInt();
    int y = sc.nextInt();

    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    int xt = -1;
    int yt = -1;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j] == x) {
                xt = i;
            }
            if (a[i][j] == y) {
                yt = i;
            }
        }
    }

    if (xt == yt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

