#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Data represents a single data entry with a string field.
struct Data {
    std::string X;
};

// Comparator function to sort Data based on the string field X.
bool compareData(const Data &a, const Data &b) {
    return a.X < b.X;
}

int main() {
    int N, L;
    std::cin >> N >> L; // Read the number of data entries and an additional integer (not used further)

    std::vector<Data> s(N); // Create a vector of Data with size N

    // Read N strings into the vector s
    for (int i = 0; i < N; i++) {
        std::cin >> s[i].X; // Populate each Data entry with a string
    }

    // Sort the vector of Data entries
    std::sort(s.begin(), s.end(), compareData);

    // Concatenate all strings in the sorted vector into a single result
    std::string ans;
    for (int i = 0; i < N; i++) {
        ans += s[i].X; // Append each string to ans
    }

    std::cout << ans << std::endl; // Print the concatenated result
    return 0;
}

// <END-OF-CODE>
