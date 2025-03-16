#include <iostream>  // Including necessary header for input and output
#include <string>    // Including necessary header for string manipulation
#include <algorithm> // Including necessary header for algorithm functions

using namespace std;

int main() {
    int h, w, n;  // Variables for height, width, and number of steps
    cin >> h >> w >> n;  // Reading the height, width, and number of steps from the console

    int sr, sc;  // Variables for starting row and column of the safe zone
    cin >> sr >> sc;  // Reading the starting position of the safe zone from the console

    string s, t;  // Strings for up/down and left/right movements
    cin >> s >> t;  // Reading the sequences of movements

    bool end = false;  // Initializing a boolean variable to keep track of whether the safe zone is valid
    int usafe = 1;  // Initializing two variables to keep track of the upper and lower boundaries of the safe zone
    int dsafe = h;

    // The first for loop is to check the vertical boundaries of the safe zone based on the sequence 's'
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {  // If the current character in the sequence 's' is 'U', increase the upper boundary by 1
            usafe++;
        } else if (s[i] == 'D') {  // If the current character in the sequence 's' is 'D', decrease the lower boundary by 1
            dsafe--;
        }
        if (usafe > dsafe) {  // If the upper boundary is greater than the lower boundary, the safe zone is not valid
            end = true;
            break;
        }
        if (i > 0) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
            if (t[i - 1] == 'U') {
                dsafe = min(dsafe + 1, h);  // If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
            } else if (t[i - 1] == 'D') {
                usafe = max(usafe - 1, 1);  // If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1
            }
        }
    }

    int lsafe = 1;  // Initializing two variables to keep track of the left and right boundaries of the safe zone
    int rsafe = w;

    // The second for loop is to check the horizontal boundaries of the safe zone based on the sequence 't'
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 'L') {  // If the current character in the sequence 't' is 'L', increase the left boundary by 1
            lsafe++;
        } else if (t[i] == 'R') {  // If the current character in the sequence 't' is 'R', decrease the right boundary by 1
            rsafe--;
        }
        if (lsafe > rsafe) {  // If the left boundary is greater than the right boundary, the safe zone is not valid
            end = true;
            break;
        }
        if (i > 0) {  // If the current index is greater than 0, check the previous character in the sequence 's' to update the boundaries accordingly
            if (s[i - 1] == 'L') {
                rsafe = min(rsafe + 1, w);  // If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
            } else if (s[i - 1] == 'R') {
                lsafe = max(lsafe - 1, 1);  // If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1
            }
        }
    }

    // Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe && !end) {
        cout << "YES" << endl;  // Output "YES" if the safe zone is valid
    } else {
        cout << "NO" << endl;   // Output "NO" if the safe zone is not valid
    }

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
