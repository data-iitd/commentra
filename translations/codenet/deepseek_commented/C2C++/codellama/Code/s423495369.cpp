#include <iostream>  // Step 1: Include the standard input/output library to use cout and cin functions.

using namespace std;  // Step 2: Use the namespace std to use cout and cin functions.

int main (void) {  // Step 3: Define the main function where the execution of the program begins.
  int A, B, C;  // Step 4: Declare three integer variables A, B, and C.

  cin >> A >> B >> C;  // Step 5: Use cin function to read three integers from the user and store them in variables A, B, and C.

  if (A < C && C < B) {  // Step 6: Check if the value of C is between A and B using if-else statements.
    cout << "Yes\n";  // Print "Yes" if the condition is true.
  } else if (A > C && C > B) {  // Check if the value of C is between A and B using if-else statements.
    cout << "Yes\n";  // Print "Yes" if the condition is true.
  } else {
    cout << "No\n";  // Print "No" if the condition is false.
  }
}

