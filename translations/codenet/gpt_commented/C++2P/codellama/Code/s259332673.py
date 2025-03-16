#include <iostream>

# Macro to simplify loop creation
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    # Declare variables to hold the input values
    h1, h2, m1, m2, k = 0, 0, 0, 0, 0

    # Read input values: start time (h1:m1), end time (h2:m2), and a duration k
    cin >> h1 >> m1 >> h2 >> m2 >> k

    # Calculate the total minutes from the start time to the end time
    ans = h2 * 60 + m2 - (h1 * 60 + m1)
    
    # Output the result after subtracting the duration k from the total minutes
    cout << ans - k << endl

    return 0 # Indicate that the program ended successfully
}

