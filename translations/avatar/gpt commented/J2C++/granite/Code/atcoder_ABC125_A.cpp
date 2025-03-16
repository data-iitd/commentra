
#include <iostream> // Importing the cin and cout objects for user input and output

using namespace std;

int main() {
    // Creating variables to hold the number of seconds, items per interval, and maximum time limit
    int sec, per_num, max_sec;
    
    // Reading the number of seconds from user input
    cin >> sec;
    
    // Reading the number of items per interval from user input
    cin >> per_num;
    
    // Reading the maximum time limit, adding 0.5 to ensure proper rounding
    cin >> max_sec;
    
    // Initializing a variable to hold the total count of items
    int ans_num = 0;
    
    // Looping from'sec' to'max_sec' in increments of'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    cout << ans_num << endl;
    
    return 0;
}
