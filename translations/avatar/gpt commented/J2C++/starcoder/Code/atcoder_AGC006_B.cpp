#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Reading two integers from user input: n and x
    int n, x;
    cin >> n >> x;
    
    // Calling the print method with the inputs x and n
    print(x, n);
}

void print(int x, int n) {
    // Calculating the maximum value based on n
    int max = n * 2 - 1;
    
    // Checking if x is equal to 1 or max, if so, print "No" and exit the method
    if (x == 1 || x == max) {
        cout << "No" << endl;
        return; // Exit the method early
    }
    
    // If x is valid, print "Yes"
    cout << "Yes" << endl;
    
    // Prepare the line separator for formatting output
    string sep = "\n";
    
    // Generate a sequence of numbers based on the input x and n
    string ans = accumulate(
        IntStream.range(x + n - 1, x + n + max - 1)
           .mapToObj(e -> to_string(e % max + 1) + sep), // Adjusting the number to fit within the range
        "",
        [](string a, string b) { return a + b; }
    );
    
    // Print the generated sequence
    cout << ans;
}

