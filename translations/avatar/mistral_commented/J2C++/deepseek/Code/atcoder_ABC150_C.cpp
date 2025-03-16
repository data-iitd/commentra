#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to find permutations of a given string
vector<string> permutation(vector<string>& list, string target, string ans) {
 if (target.length() <= 1) { // Base case: if the target string length is less than or equal to 1
 list.push_back(ans + target); // Add the current permutation to the list
 } else {
 for (int i = 0; i < target.length(); i++) { // Iterate through each character in the target string
 permutation(list, target.substr(0, i) + target.substr(i + 1), ans + target[i]); // Recursive call to find permutations of the remaining string
 }
 }
 return list; // Return the list of permutations
}

// Main function to read user input and find the sum of the permutations
int main() {
 int n; // Declare an integer variable to store the number of test cases
 string number = ""; // Declare an empty string variable to store the number string

 // Read the number of test cases from the user
 cin >> n;

 // Create the number string by concatenating numbers from 1 to n
 for (int i = 1; i <= n; i++) {
 number += to_string(i);
 }

 vector<string> listA; // Declare an empty vector to store the permutations
 permutation(listA, number, ""); // Call the permutation function to find all permutations of the number string

 int sum = 0; // Declare an integer variable to store the sum of the indices of the matching permutations
 string line; // Declare a string variable to read each line from the user
 while (cin >> line) { // Read each line until end-of-file
 for (int i = 0; i < listA.size(); i++) { // Iterate through each permutation in the list
 if (listA[i] == line) { // Check if the current permutation matches the current line
 if (sum == 0) { // If this is the first matching permutation
 sum += i; // Add the index of the matching permutation to the sum
 } else { // If there is already a matching permutation in the sum
 sum -= i; // Subtract the index of the previous matching permutation from the sum
 }
 }
 }
 }

 cout << abs(sum) << endl; // Print the absolute value of the sum

 return 0;
}
