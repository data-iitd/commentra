#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<double> arr(2 * n);
    int non_int = 0;
    double sum_before = 0, sum = 0;

    for (int i = 0; i < 2 * n; i++) {
        double num;
        ss >> num;
        sum_before += num;
        if (fabs(num - floor(num)) > 1e-9) non_int++;
        sum += floor(num);
        arr[i] = num;
    }

    double max_sum = min(n, non_int) + sum;
    double min_sum = max(0, non_int - n) + sum;
    double ans;

    if (min_sum > sum_before) {
        ans = min_sum - sum_before;
    } else if (max_sum < sum_before) {
        ans = sum_before - max_sum;
    } else {
        double x = sum_before - floor(sum_before);
        ans = min(fabs(x - 1), fabs(x));
    }

    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
