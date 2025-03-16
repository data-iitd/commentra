
#include <iostream> // Include the necessary libraries for input/output

using namespace std; // Use the standard namespace for convenience

int sub(int a, int b) {
    int min = min(a, b);
    int max = max(a, b);
    int result = 0;
    
    while (min > 0) {
        result += max / min;
        max = max % min;
        int curr_min = min(min, max);
        int curr_max = max(min, max);
        min = curr_min;
        max = curr_max;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n; // Read the number of test cases from user input
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b; // Read two integers a and b from user input
        
        cout << sub(a, b) << endl; // Call the sub method and print the result
    }
    
    return 0;
}

