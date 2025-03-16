#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int s, x, d=2; 
    cin >> s; // Read the initial number from the user
    set<int> a;
    a.insert(s); // Insert the initial number into the set

    while(1) { // Start an infinite loop
        if(s%2==0){ // Check if the current number is even
            x = s/2; // Halve the number
            if(a.find(x)!=a.end()) { // Check if the halved number has been encountered before
                cout << d << endl; // Output the current step count and terminate the program
                return 0;
            }
            a.insert(x); // Insert the halved number into the set
        } else { // The current number is odd
            x = 3*s + 1; // Triple the number and add one
            if(a.find(x)!=a.end()) { // Check if the new number has been encountered before
                cout << d << endl; // Output the current step count and terminate the program
                return 0;
            }
            a.insert(x); // Insert the new number into the set
        }
        s = x; // Update the current number to the new number
        d++; // Increment the step count
    }

    cout << d << endl; // Output the step count (this line will never be reached)

    return 0;
}

