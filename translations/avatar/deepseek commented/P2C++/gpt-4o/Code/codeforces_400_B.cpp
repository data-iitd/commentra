#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m; // Read the dimensions of the grid (n: number of rows, m: number of columns)

    std::set<int> c; // Set to store the differences
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s; // Read each row as a string
        int indexS = s.find('S'); // Find index of 'S'
        int indexG = s.find('G'); // Find index of 'G'
        c.insert(indexS - indexG); // Calculate the difference and insert into the set
    }

    // Check if there is any negative difference in the set 'c'
    bool hasNegative = false;
    for (int a : c) {
        if (a < 0) {
            hasNegative = true;
            break;
        }
    }

    if (hasNegative) {
        std::cout << -1 << std::endl; // Print '-1' if any negative difference exists
    } else {
        std::cout << c.size() << std::endl; // Print the number of unique non-negative differences
    }

    return 0;
}
// <END-OF-CODE>
