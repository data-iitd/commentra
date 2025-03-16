#include <stdio.h>
#include <string.h>
#include <math.h>
int main ( ) {
    int N;
    char S[100000];
    scanf ( "%d", &N );
    scanf ( "%s", S );
    int calculate ( int n , char s[] ) {
        int arr[100000];
        int rNum = 0;
        int gNum = 0;
        int bNum = 0;
        int sum = 0;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( s[i] == 'R' ) {
                rNum++;
            } else if ( s[i] == 'G' ) {
                gNum++;
            } else if ( s[i] == 'B' ) {
                bNum++;
            }
        }
        for ( int step = 1 ; step <= ( int ) ceil ( n / 2 ) ; step++ ) {
            for ( int i = 0 ; i < n - 2 * step ; i++ ) {
                char s[3];
                s[0] = s[i];
                s[1] = s[i + step];
                s[2] = s[i + step * 2];
                if ( strcmp ( s , "RGB" ) == 0 || strcmp ( s , "RBG" ) == 0 || strcmp ( s , "BGR" ) == 0 || strcmp ( s , "BRG" ) == 0 || strcmp ( s , "GBR" ) == 0 || strcmp ( s , "GRB" ) == 0 ) {
                    sum++;
                }
            }
        }
        printf ( "%d\n" , rNum * gNum * bNum - sum );
    }
    calculate ( N , S );
    return 0;
}
