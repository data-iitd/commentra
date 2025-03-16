#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    vector<int> g(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i] >> g[i];
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i] == g[j]) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}

