#include <iostream>
#include <set>
#include <string>
#include <sstream>

int main() {
    // Read input
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore(); // To ignore the newline after reading integers

    // Initialize an empty set
    std::set<int> c;

    // Populate set c with differences between indices of 'S' and 'G' in each string
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::getline(std::cin, s);

        // Find the indices of 'S' and 'G' in the current string
        int index_S = s.find('S');
        int index_G = s.find('G');

        // Calculate the difference and add it to the set
        int difference = index_S - index_G;
        c.insert(difference);
    }

    // Check if there is any negative number in set c and print accordingly
    bool has_negative = false;
    for (const auto& a : c) {
        if (a < 0) {
            has_negative = true;
            break;
        }
    }

    std::cout << (has_negative ? -1 : c.size()) << std::endl;

    return 0;
}

// <END-OF-CODE>
