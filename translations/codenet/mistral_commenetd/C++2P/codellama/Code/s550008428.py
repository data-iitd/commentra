
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int s, x, d=2; // Initialize variables s, x, and d with initial values

    cin >> s; // Read an integer value from the standard input and assign it to variable s
    set<int> a; // Create an empty set named a
    a.insert(s); // Add the value of s to the set a

    while(1) { // Start an infinite loop
        if(s%2==0){ // Check if s is even
            x = s/2; // Calculate the half of s and assign it to x
            if(a.find(x)!=a.end()) { // Check if x is already in the set a
                cout << d << endl; // If yes, print the value of d and exit the program
                return 0;
            }
            a.insert(x); // If not, add x to the set a and assign it to s for the next iteration
        } else { // If s is odd
            x = 3*s + 1; // Calculate 3s + 1 and assign it to x
            if(a.find(x)!=a.end()) { // Check if x is already in the set a
                cout << d << endl; // If yes, print the value of d and exit the program
                return 0;
            }
            a.insert(x); // If not, add x to the set a and assign it to s for the next iteration
        }
        s = x; // Update the value of s with the new value of x
        d++; // Increment the value of d for each iteration
    }

    cout << d << endl; // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the set

    return 0; // Exit the program with a return value of 0
}

