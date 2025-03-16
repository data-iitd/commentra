#include <iostream>

using namespace std;

int main()
{
    // Read two integers from input: S (the strength) and W (the weight)
    int S, W;
    cin >> S >> W;
    
    // Check if the strength S is less than or equal to the weight W
    // If it is, print "unsafe"; otherwise, print "safe"
    if (S <= W)
        cout << "unsafe" << endl;
    else
        cout << "safe" << endl;
    
    return 0;
}

