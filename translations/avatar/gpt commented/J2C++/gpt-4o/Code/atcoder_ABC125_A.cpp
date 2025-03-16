#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Reading the number of seconds from user input
    int sec;
    cin >> sec;
    
    // Reading the number of items per interval from user input
    int per_num;
    cin >> per_num;
    
    // Reading the maximum time limit, adding 0.5 to ensure proper rounding
    double max_sec;
    cin >> max_sec;
    max_sec += 0.5; // Adding 0.5 for rounding
    
    // Initializing a variable to hold the total count of items
    int ans_num = 0;
    
    // Looping from 'sec' to 'max_sec' in increments of 'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    cout << ans_num << endl;

    return 0;
}

// <END-OF-CODE>
