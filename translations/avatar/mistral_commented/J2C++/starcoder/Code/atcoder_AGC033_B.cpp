
#include <bits/stdc++.h>

using namespace std ;

int main ( ) {
    int h, w, n, sr, sc, usafe, dsafe, lsafe, rsafe ;
    bool end = false ;
    string s, t ;

    cin >> h >> w >> n ;
    cin >> sr >> sc ;
    cin >> s >> t ;

    usafe = 1 ;
    dsafe = h ;

    // The first for loop is to check the vertical boundaries of the safe zone based on the sequence's'
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        if ( s[i] == 'U' ) {  // If the current character in the sequence's' is 'U', increase the upper boundary by 1
            usafe ++ ;
        } else if ( s[i] == 'D' ) {  // If the current character in the sequence's' is 'D', decrease the lower boundary by 1
            dsafe -- ;
        }
        if ( usafe > dsafe ) {  // If the upper boundary is greater than the lower boundary, the safe zone is not valid
            end = true ;
            break ;
        }
        if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
            if ( t[i - 1] == 'U' ) {
                dsafe = min ( dsafe + 1, h ) ;  // If the previous character is 'U', increase the lower boundary by 1 to the minimum of the height
            } else if ( t[i - 1] == 'D' ) {
                usafe = max ( usafe - 1, 1 ) ;  // If the previous character is 'D', decrease the upper boundary by 1 to the maximum of 1
            }
        }
    }

    lsafe = 1 ;
    rsafe = w ;

    // The second for loop is to check the horizontal boundaries of the safe zone based on the sequence 't'
    for ( int i = n - 1 ; i >= 0 ; i -- ) {
        if ( s[i] == 'L' ) {  // If the current character in the sequence's' is 'L', increase the left boundary by 1
            lsafe ++ ;
        } else if ( s[i] == 'R' ) {  // If the current character in the sequence's' is 'R', decrease the right boundary by 1
            rsafe -- ;
        }
        if ( lsafe > rsafe ) {  // If the left boundary is greater than the right boundary, the safe zone is not valid
            end = true ;
            break ;
        }
        if ( i > 0 ) {  // If the current index is greater than 0, check the previous character in the sequence 't' to update the boundaries accordingly
            if ( t[i - 1] == 'L' ) {
                rsafe = min ( rsafe + 1, w ) ;  // If the previous character is 'L', increase the right boundary by 1 to the minimum of the width
            } else if ( t[i - 1] == 'R' ) {
                lsafe = max ( lsafe - 1, 1 ) ;  // If the previous character is 'R', decrease the left boundary by 1 to the maximum of 1
            }
        }
    }

    if ( sr >= usafe && sr <= dsafe && sc >= lsafe && sc <= rsafe &&! end ) {  // Checking if the starting position of the safe zone is within the safe zone boundaries and the safe zone is valid
        cout << "YES" << endl ;
    } else {
        cout << "NO" << endl ;
    }

    return 0 ;
}

