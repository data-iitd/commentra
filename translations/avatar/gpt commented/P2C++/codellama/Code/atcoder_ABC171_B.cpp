#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += numbers[i];
    }

    cout << sum << endl;

    return 0;
}

