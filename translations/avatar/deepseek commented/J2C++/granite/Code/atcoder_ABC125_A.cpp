
#include <iostream> // Importing the iostream library for input/output operations.

using namespace std; // Using the standard namespace for input/output operations.

int main() {
    int sec, per_num, max_sec, ans_num = 0; // Declaring and initializing the variables.
    
    cin >> sec >> per_num >> max_sec; // Reading the input values using cin.
    
    // Loop to iterate from'sec' to'max_sec' in steps of'sec' and add 'per_num' to 'ans_num' each time.
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    
    cout << ans_num << endl; // Printing the final result after the loop completes.
    
    return 0; // Returning 0 to indicate successful execution of the program.
}

