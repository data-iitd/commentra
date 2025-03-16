#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        istringstream ss(s);
        vector<int> l1;
        int x;
        while (ss >> x) {
            l1.push_back(x);
        }
        if (accumulate(l1.begin(), l1.end(), 0) > 1) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}

