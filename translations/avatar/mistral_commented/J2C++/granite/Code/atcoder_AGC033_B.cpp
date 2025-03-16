

#include <iostream>  // Including necessary C++ utility libraries
#include <string>

using namespace std;

int main() {
    int h, w, n, sr, sc;
    string s, t;
    cin >> h >> w >> n >> sr >> sc >> s >> t;  // Reading input from the console

    int usafe = 1, dsafe = h;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') {
            usafe++;
        } else if (s[i] == 'D') {
            dsafe--;
        }
        if (usafe > dsafe) {
            cout << "NO" << endl;  // If the upper boundary is greater than the lower boundary, the safe zone is not valid
            return 0;
        }
        if (i > 0) {
            if (t[i - 1] == 'U') {
                dsafe = min(dsafe + 1, h);  // If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
            } else if (t[i - 1] == 'D') {
                usafe = max(usafe - 1, 1);  // If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1
            }
        }
    }

    int lsafe = 1, rsafe = w;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'L') {
            lsafe++;
        } else if (s[i] == 'R') {
            rsafe--;
        }
        if (lsafe > rsafe) {
            cout << "NO" << endl;  // If the left boundary is greater than the right boundary, the safe zone is not valid
            return 0;
        }
        if (i > 0) {
            if (t[i - 1] == 'L') {
                rsafe = min(rsafe + 1, w);  // If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
            } else if (t[i - 1] == 'R') {
                lsafe = max(lsafe - 1, 1);  // If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1
            }
        }
    }

    if (sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe) {  // Checking if the starting position of the safe zone is within the safe zone boundaries
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

These comments should provide a clear understanding of the logic behind each part of the code.