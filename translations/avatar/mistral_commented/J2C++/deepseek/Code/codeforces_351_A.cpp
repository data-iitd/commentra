#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double num;
    string line;
    vector<double> arr;
    int non_int = 0;
    double sum_before = 0, sum = 0;

    getline(cin, line);
    n = stoi(line);

    getline(cin, line);
    stringstream ss(line);

    while (ss >> num) {
        sum_before += num;
        if (floor(num) != num) non_int++;
        sum += floor(num);
        arr.push_back(num);
    }

    double max_sum = min(n, non_int) + sum;
    double min_sum = max(0, non_int - n) + sum;

    double ans;
    if (min_sum > sum_before) ans = min_sum - sum_before;
    else if (max_sum < sum_before) ans = sum_before - max_sum;
    else {
        double x = sum_before - floor(sum_before);
        ans = min(1 - x, x);
    }

    cout << fixed << setprecision(3) << ans << endl;

    return 0;
}

