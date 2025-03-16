#include <iostream>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    int n, k, z;
    cin >> n >> k;
    
    // Increment n by 1
    n++;
    
    // Initialize a variable z to store the adjustment needed to make n divisible by k
    z = 0;
    
    // Check if n is not divisible by k
    if (n % k != 0) {
        // Calculate the adjustment needed to make n divisible by k
        z = k - n % k;
    }
    
    // Output the final result, which is n plus the adjustment z
    cout << n + z << endl;
    
    return 0;
}

