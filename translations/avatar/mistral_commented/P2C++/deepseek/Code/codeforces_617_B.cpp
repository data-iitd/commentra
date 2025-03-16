#include <iostream>
#include <string>
#include <vector>
#include <numeric> // for std::accumulate
#include <sstream>

using namespace std;

int main() {
    string a;
    getline(cin, a);

    // Check if the string contains any '1' character
    if (a.find('1') == string::npos) {
        // If it doesn't, print 0 and exit the program
        cout << 0 << endl;
        return 0;
    }

    // Remove leading and trailing zeros
    a.erase(0, a.find_first_not_of('0'));
    a.erase(a.find_last_not_of('0') + 1);

    // Split the string by '1' and calculate the product of the number of zeros in each segment
    vector<string> segments;
    stringstream ss(a);
    string segment;
    while (getline(ss, segment, '1')) {
        if (!segment.empty()) {
            segments.push_back(segment);
        }
    }

    vector<int> zeros_count;
    for (const auto& seg : segments) {
        zeros_count.push_back(count(seg.begin(), seg.end(), '0') + 1);
    }

    int product_of_zeros = accumulate(zeros_count.begin(), zeros_count.end(), 1, multiplies<int>());

    // Finally, print the result
    cout << product_of_zeros << endl;

    return 0;
}
