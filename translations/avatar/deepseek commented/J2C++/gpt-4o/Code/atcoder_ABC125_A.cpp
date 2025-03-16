#include <iostream> // Including the iostream library for input and output operations.
using namespace std;

int main() {
    int sec, per_num;
    double max_sec;

    cin >> sec; // Reading the first integer input which seems to be a time interval.
    cin >> per_num; // Reading the second integer input which is a number to be added per iteration.
    cin >> max_sec; // Reading the third integer input.
    max_sec += 0.5; // Adding 0.5 to max_sec.

    int ans_num = 0; // Initializing the variable to store the result of additions.

    // Loop to iterate from 'sec' to 'max_sec' in steps of 'sec' and add 'per_num' to 'ans_num' each time.
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }

    cout << ans_num << endl; // Printing the final result after the loop completes.
    
    return 0; // Indicating that the program ended successfully.
}

// <END-OF-CODE>
