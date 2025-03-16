#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

// Define a function calculate that takes two arguments: an integer n and a string s
void calculate(int n, const string& s) {
    // Create a map to count occurrences of each color
    unordered_map<char, int> colorCount;
    colorCount['R'] = 0;
    colorCount['G'] = 0;
    colorCount['B'] = 0;

    // Count the number of occurrences of each color in the string s
    for (char c : s) {
        colorCount[c]++;
    }

    // Store the counts in variables
    int rNum = colorCount['R'];
    int gNum = colorCount['G'];
    int bNum = colorCount['B'];

    // Initialize a variable sum to 0
    int sum = 0;

    // Use a for loop to iterate through each step from 1 to the ceiling of N/2
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Check each triplet of characters in the string
        for (int i = 0; i <= n - 3; i++) {
            string triplet = s.substr(i, 3);
            // Check if the triplet is one of the six possible color combinations
            if (triplet == "RGB" || triplet == "RBG" || triplet == "BGR" || 
                triplet == "BRG" || triplet == "GBR" || triplet == "GRB") {
                sum++;
            }
        }
    }

    // Print the result of the calculation: rNum * gNum * bNum - sum
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    // Take an integer input N and a string input S from the user
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Call the calculate function with the input values N and S
    calculate(N, S);

    return 0;
}

// <END-OF-CODE>
