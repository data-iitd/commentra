#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
 // Initializing the Scanner object to read input from the console
 int n;
 cin >> n;

 // Creating a vector 'a' of size 'n' to store the input elements
 vector<int> a(n);

 // Initializing the XOR result to 0
 int r = 0;

 // Reading the elements of the vector 'a' from the user input and performing XOR operation
 for (int i = 0; i < n; i++) {
 // Reading the next integer from the user input
 cin >> a[i];

 // Performing XOR operation between 'r' and the current element 'a[i]' and updating the value of 'r'
 r ^= a[i];
 }

 // Printing the XOR result
 for (int i = 0; i < n; i++) {
 // If it's not the first element, print a space before the current element
 if (i != 0)
 cout << " ";

 // Printing the XOR result of 'r' and the current element 'a[i]'
 cout << (r ^ a[i]);
 }

 cout << endl;

 return 0;
}

