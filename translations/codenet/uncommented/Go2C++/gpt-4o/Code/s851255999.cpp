#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Work {
    int time;
    int limit;
};

bool compare(const Work &a, const Work &b) {
    return a.limit < b.limit;
}

int main() {
    int n;
    cin >> n;
    vector<Work> works(n);
    
    for (int i = 0; i < n; i++) {
        cin >> works[i].time >> works[i].limit;
    }
    
    sort(works.begin(), works.end(), compare);

    long long sum = 0;
    for (const auto &w : works) {
        sum += w.time;
        if (sum > w.limit) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

// <END-OF-CODE>
