#include <bits/stdc++.h>
using namespace std;

int main () {
    // Take a string as input from the user
    string S;
    cin >> S;

    // Import the Counter function from the collections module to count the frequency of each character in the string
    #include <bits/extc++.h>
    using namespace __gnu_cxx;

    // Create a set Sa from the list of characters in the string S
    set < char > Sa ( S.begin(), S.end() );

    // Check if the length of the set Sa is equal to 2
    if ( Sa.size()!= 2 ) {
        // If not, print "No" and exit the program
        cout << "No" << endl;
        return 0;
    }

    // Create a Counter object c to count the frequency of each character in the string S
    map < char, int > c;
    for ( char i : S ) {
        c [ i ]++;
    }

    // Iterate through each character i in the set Sa
    for ( char i : Sa ) {
        // For each character i, check if its frequency in the string S is equal to 2 using the Counter dictionary c
        if ( c [ i ]!= 2 ) {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            cout << "No" << endl;
            return 0;
        }
    }

    // If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
    cout << "Yes" << endl;

    return 0;
}

