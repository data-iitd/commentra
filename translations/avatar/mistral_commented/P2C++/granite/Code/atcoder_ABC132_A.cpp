
#include <bits/stdc++.h>
using namespace std;

int main () {
    // Take a string as input from the user
    string S;
    cin >> S;

    // Create a map m to store the frequency of each character in the string S
    map < char, int > m;

    // Iterate through each character i in the string S
    for ( char i : S ) {
        // Increment the frequency of the character i in the map m
        m [ i ] += 1;
    }

    // Create a set Sa from the keys of the map m
    set < char > Sa ( m.begin (), m.end () );

    // Check if the size of the set Sa is equal to 2
    if ( Sa.size ()!= 2 ) {
        // If not, print "No" and exit the program
        cout << "No" << endl;
        return 0;
    }

    // Iterate through each character i in the set Sa
    for ( char i : Sa ) {
        // Check if the frequency of the character i in the map m is equal to 2
        if ( m [ i ]!= 2 ) {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            cout << "No" << endl;
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
    cout << "Yes" << endl;

    return 0;
}
