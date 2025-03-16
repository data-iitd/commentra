#include <iostream>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    int sec, per_num, max_sec, ans_num;
    cin >> sec >> per_num >> max_sec;
    
    // Initializing a variable to hold the total count of items
    ans_num = 0;
    
    // Looping from'sec' to'max_sec' in increments of'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    cout << ans_num << endl;
    
    return 0;
}

