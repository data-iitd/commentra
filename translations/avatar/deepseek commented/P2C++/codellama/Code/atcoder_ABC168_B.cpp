
#include <iostream>
using namespace std;
int main ( ) {
    // Read the value of K from the user
    int K;
    cin >> K;
    // Read the string S from the user
    string S;
    cin >> S;
    // Check if the length of S is less than or equal to K
    if ( S.length ( ) <= K ) {
        // If the length of S is less than or equal to K, return S as it is
        return S;
    }
    // If the length of S is greater than K, return the first K characters of S followed by '...'
    return S.substr ( 0, K ) + "...";
}
