
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 0; i < n; i++) {
        vector<int> l1(3);
        cin >> l1[0] >> l1[1] >> l1[2];
        if (l1[0] + l1[1] + l1[2] > 1) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}

