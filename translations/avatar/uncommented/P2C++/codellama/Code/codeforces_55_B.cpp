#include <iostream>
using namespace std;
void rememberTheNumber ( int nums [ ] , int i , char operations [ ] , int ans [ ] ) {
    if ( i >= 3 ) {
        return;
    }
    for ( int j = 0 ; j < 4 ; j++ ) {
        for ( int k = j + 1 ; k < 4 ; k++ ) {
            if ( nums [ j ] != - 1 and nums [ k ] != - 1 ) {
                int s = nums [ j ];
                nums [ j ] = - 1;
                int t = nums [ k ];
                if ( operations [ i ] == '+' ) {
                    nums [ k ] = s + t;
                } else if ( operations [ i ] == '*' ) {
                    nums [ k ] = s * t;
                }
                if ( i == 2 and nums [ k ] < ans [ 0 ] ) {
                    ans [ 0 ] = nums [ k ];
                }
                rememberTheNumber ( nums , i + 1 , operations , ans );
                nums [ j ] = s;
                nums [ k ] = t;
            }
        }
    }
}
int main ( ) {
    int nums [ ] = { 1 , 2 , 3 , 4 };
    char operations [ ] = { '+' , '*' , '+' , '*' };
    int ans [ ] = { 10000000000000000000000000 };
    rememberTheNumber ( nums , 0 , operations , ans );
    cout << ans [ 0 ] << endl;
    return 0;
}



