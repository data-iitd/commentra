

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::string run(std::string s, std::string t) {
    // Define the run function that takes two arguments, s and t
    std::map<char, int> counter_s;
    // Create a map to store the count of each character in s
    for (char c : s) {
        counter_s[c]++;
    }
    // Iterate over the characters in s and increment their counts in the map
    std::vector<int> values_s(counter_s.begin(), counter_s.end());
    // Create a vector to store the values of the map
    std::sort(values_s.begin(), values_s.end());
    // Sort the values in the vector in ascending order
    std::map<char, int> counter_t;
    // Create a map to store the count of each character in t
    for (char c : t) {
        counter_t[c]++;
    }
    // Iterate over the characters in t and increment their counts in the map
    std::vector<int> values_t(counter_t.begin(), counter_t.end());
    // Create a vector to store the values of the map
    std::sort(values_t.begin(), values_t.end());
    // Sort the values in the vector in ascending order
    if (values_s == values_t) {
        // Check if the sorted values of s and t are equal
        return "Yes";
    } else {
        // If not equal, return 'No'
        return "No";
    }
}

int main() {
    // Define the main function to get input and print the result
    std::string s;
    // Get input for s from the user
    std::cin >> s;
    // Read the input for s from the standard input
    std::string t;
    // Get input for t from the user
    std::cin >> t;
    // Read the input for t from the standard input
    std::cout << run(s, t) << std::endl;
    // Call the run function with s and t as arguments and print the result
    return 0;
}

