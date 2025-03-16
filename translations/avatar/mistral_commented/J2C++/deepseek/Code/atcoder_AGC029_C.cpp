#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

class Main {
private:
 int n; // Number of elements in the array 'a'
 vector<int> a; // Array of integers
 map<int, int> s; // Sorted map to store the count of each element

public:
 static void main(string[] args) {
 Main m = Main(); // Create an instance of Main class
 m.solve(); // Call the solve method to find the solution
 }

private:
 void set() {
 string line;
 getline(cin, line); // Read the first line containing the number of elements 'n'
 n = stoi(line); // Parse the string to integer 'n'
 getline(cin, line); // Read the second line containing the elements of the array 'a'
 a = parseArray(line); // Parse the string to an integer array 'a'
 s.clear(); // Initialize an empty map 's'
 }

 vector<int> parseArray(string line) {
 vector<int> arr;
 stringstream ss(line);
 string token;
 while (getline(ss, token, ' ')) {
 arr.push_back(stoi(token));
 }
 return arr;
 }

 void solve() {
 set(); // Call the set method to read the input
 int ng = 0; // Initialize the lower bound of the search range
 int ok = n; // Initialize the upper bound of the search range

 while (ok - ng > 1) { // Run the while loop until the search range is narrowed down to a single element
 int k = (ng + ok) / 2; // Calculate the middle index of the search range
 if (isPossible(k)) { // If the middle index 'k' is a valid solution, update the upper bound
 ok = k;
 } else { // Otherwise, update the lower bound
 ng = k;
 }
 }

 cout << ok << endl; // Print the solution
 }

 bool isPossible(int k) {
 s.clear(); // Clear the map 's' before processing the new condition
 int current = 0; // Initialize the current index in the array 'a'

 for (int ai : a) { // Iterate through each element in the array 'a'
 if (ai <= current) { // If the current element is smaller than or equal to the previous one, check if the condition 'k' is valid
 if (k == 1) return false; // If 'k' is 1, return false as there is no possible solution

 while (!s.empty() && s.rbegin()->first >= ai) { // If there is an element greater than or equal to 'ai' in the map, remove it
 s.erase(prev(s.end()));
 }

 int p = ai - 1; // Calculate the previous index 'p'
 while (true) { // Find the previous index 'p' with the count 'k' in the map
 if (p < 0) return false; // If 'p' is out of the array bounds, return false

 s[p]++; // Update the count of 'p' in the map

 if (s[p] == k) { // If the count of 'p' is equal to 'k', remove it and move to the previous index
 s.erase(p);
 p--;
 } else { // Otherwise, break the loop
 break;
 }
 }
 }
 current = ai; // Update the current index
 }

 return true; // If all elements in the array 'a' are processed, return true as a valid solution is found
 }
};

