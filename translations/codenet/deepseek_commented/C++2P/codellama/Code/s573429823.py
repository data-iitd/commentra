#include <iostream>
using namespace std;

int main(void)
{
    // Declare an unsigned long integer to store the input number
    unsigned long n;
    
    // Read the value of n from the standard input
    cin >> n;
    
    // Initialize a boolean variable to false
    bool flg = false;
    
    // Check if n is less than 4. If so, print "No" and exit.
    if(n < 4) {
        cout << "No" << endl;
    } else {
        // Check all possible combinations of 4s and 7s that sum up to n
        for(int i = 0; i <= (n / 4); i++) {
            for(int j = 0; j <= (n / 7); j++) {
                if((i * 4 + j * 7) == n) {
                    flg = true;
                    break;
                }
            }
            if(flg) break;
        }
        
        // Check the value of flg and print "Yes" or "No" accordingly
        if(flg) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

