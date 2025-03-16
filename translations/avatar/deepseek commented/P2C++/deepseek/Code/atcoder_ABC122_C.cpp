#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;

    vector<int> problems(q, 0);
    for (int i = 0; i < q; ++i) {
        cin >> problems[i] >> problems[i];
    }

    // Define a function to count occurrences of 'AC' in the string
    auto count = [](int total, int i) {
        if (s.substr(i-1, 2) == "AC") {
            return total + 1;
        } else {
            return total;
        }
    };

    // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
    vector<int> cumsum(n+1, 0);
    iota(cumsum.begin(), cumsum.end(), 0);
    partial_sum(cumsum.begin(), cumsum.end(), cumsum.begin(), count);

    // Iterate over the queries and print the difference in cumulative sums
    for (int i = 0; i < q; ++i) {
        int l = problems[2*i];
        int r = problems[2*i+1];
        cout << cumsum[r-1] - cumsum[l-1] << endl;
    }

    return 0;
}
