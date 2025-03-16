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
        return 0;
    }

    int product_of_zeros = 1;
    vector<string> segments;
    string segment;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '1') {
            if (segment.size() > 0) {
                segments.push_back(segment);
                segment = "";
            }
        } else {
            segment += a[i];
        }
    }
    if (segment.size() > 0) {
        segments.push_back(segment);
    }

    for (int i = 0; i < segments.size(); i++) {
        product_of_zeros *= (segments[i].size() + 1);
    }

    cout << product_of_zeros << endl;

    return 0;
}

