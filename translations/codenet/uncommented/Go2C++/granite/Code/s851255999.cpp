
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct work {
    int time, limit;
};

bool compare(const work& w1, const work& w2) {
    return w1.limit < w2.limit;
}

int main() {
    // Your code here!
    int n;
    cin >> n;
    vector<work> ws(n);
    for (int i = 0; i < n; i++) {
        int a, n;
        cin >> a >> n;
        ws[i] = {a, n};
    }
    sort(ws.begin(), ws.end(), compare);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ws[i].time;
        if (sum > ws[i].limit) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

