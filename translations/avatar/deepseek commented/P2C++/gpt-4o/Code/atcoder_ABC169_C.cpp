#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    // Set the recursion limit (not applicable in C++)
    
    // Debugging function (not implemented in C++)
    
    // Read two inputs
    string sa, sb;
    cin >> sa >> sb;
    
    // Convert the first input to integer
    int a = stoi(sa);
    
    // Convert the second input to scaled integer
    int b = static_cast<int>(round(stod(sb) * 100));
    
    // Perform the calculation and print the result
    cout << (a * b) / 100 << endl;

    return 0;
}

// <END-OF-CODE>
