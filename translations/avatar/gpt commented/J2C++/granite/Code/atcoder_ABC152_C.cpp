
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    priority_queue<int> q;
    for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);
        if (arr[i] <= q.top()) {
            sum++;
        }
    }

    return sum;
}

int main() {
    // Call the solve method and print the result
    cout << solve() << endl;
    return 0;
}

