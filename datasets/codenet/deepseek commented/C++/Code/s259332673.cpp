#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
    // Declare integer variables to store input values
    int h1, h2, m1, m2, k;
    
    // Read input values for h1, m1, h2, m2, and k from the standard input
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    
    // Calculate the difference in minutes between h2:m2 and h1:m1
    int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
    
    // Print the result of subtracting k from the calculated difference
    cout << ans - k << endl;
    
    return 0;
}
