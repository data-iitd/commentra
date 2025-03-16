#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a variable to read input
    int n;
    
    // Read the number of elements
    cin >> n;
    
    // Initialize sums of subsets
    int a = 0, b = 0, c = 0;
    
    // Sum all n elements
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a += num;
    }
    
    // Sum n-1 elements
    for (int i = 0; i < n - 1; i++) {
        int num;
        cin >> num;
        b += num;
    }
    
    // Sum n-2 elements
    for (int i = 0; i < n - 2; i++) {
        int num;
        cin >> num;
        c += num;
    }
    
    // Calculate the differences
    int x = a - b;
    int y = b - c;
    
    // Output the results
    cout << x << endl;
    cout << y << endl;

    return 0;
}

// <END-OF-CODE>
