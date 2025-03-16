#include <iostream>
#include <cmath>
using namespace std;
int twos_in_factorial ( int n ) {
    return n - floor ( log2 ( n ) );
}
bool parity_of_nCr ( int n , int i ) {
    return twos_in_factorial ( n ) - twos_in_factorial ( n - i ) - twos_in_factorial ( i ) > 0;
}
int main ( ) {
    int n;
    cin >> n;
    int nums[n];
    bool no_one = false;
    for ( int i = 0 ; i < n ; i++ ) {
        cin >> nums[i];
        if ( nums[i] == 1 ) {
            no_one = true;
        }
    }
    bool is_odd = false;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( !parity_of_nCr ( n - 1 , i ) && nums[i] & 1 ) {
            is_odd ^= 1;
        }
    }
    if ( !is_odd ) {
        cout << 0 << endl;
    } else {
        cout << pow ( 2 , no_one ) << endl;
    }
    return 0;
}



