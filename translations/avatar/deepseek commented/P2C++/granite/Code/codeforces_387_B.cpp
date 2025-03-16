
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of elements in round_complexity and george_complexity
    int n, m;
    cin >> n >> m;
    
    // Read the complexities of the rounds
    vector<int> round_complexity(n);
    for (int i = 0; i < n; i++) {
        cin >> round_complexity[i];
    }
    
    // Read the complexities of George's challenges
    vector<int> george_complexity(m);
    for (int i = 0; i < m; i++) {
        cin >> george_complexity[i];
    }
    
    // Initialize counters for both lists
    int i = 0, j = 0;
    
    // Loop through both lists to compare complexities
    while (i < n && j < m) {
        // Increment i if the current round complexity is less than or equal to George's complexity
        i += (round_complexity[i] <= george_complexity[j])? 1 : 0;
        
        // Increment j to move to the next element in george_complexity
        j += 1;
    }
    
    // Print the number of rounds George can solve
    cout << n - i << endl;
    
    return 0;
}

// Check if the script is run as the main program
int main() {
    // Call the main function from the Python code
    main();
    
    return 0;
}

