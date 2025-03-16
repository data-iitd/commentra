
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <array>
#include <valarray>
#include <climits>
#include <cassert>
#include <regex>
#include <random>
#include <chrono>
#include <cstdlib>
#include <deque>
#include <ctime>

using namespace std;

int main() {
    // Determine the input source: standard input or a file specified as a command-line argument.
    ifstream fp;
    if (argc > 1) {
        fp.open(argv[1]);
    } else {
        fp.open("input.txt");
    }

    // Initialize the scanner for reading input.
    string line;
    getline(fp, line);
    stringstream ss(line);
    int n;
    ss >> n;

    // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
    int aa[n+2];
    int sum = 0;

    // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        getline(fp, line);
        stringstream ss(line);
        ss >> aa[i+1];
        sum += abs(aa[i+1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += abs(aa[n+1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i < n+1; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - abs(aa[i+1]-aa[i]) - abs(aa[i]-aa[i-1]) + abs(aa[i+1]-aa[i-1]);
        cout << ans << endl; // Output the result for the current element.
    }

    return 0;
}

