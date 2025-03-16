#include <iostream>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    int T, S, q, previous, answer;
    cin >> T >> S >> q;
    previous = S;
    answer = 0;
    
    // Loop until 'previous' is less than 'T'
    while (previous < T) {
        answer++;
        previous *= q;
    }
    
    // Output the final count of how many times 'previous' was multiplied before reaching 'T'
    cout << answer << endl;
    
    return 0;
}

