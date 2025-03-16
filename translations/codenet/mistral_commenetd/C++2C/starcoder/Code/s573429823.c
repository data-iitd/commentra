#include <stdio.h>

int main(void)
{
    unsigned long n;
    bool flg = false;

    scanf("%lu", &n);

    if( n<4 ) {
        printf("No\n");
        return 0;
    }

    for( int i=0; i<=(n/4); i++ ) {
        for( int j=0; j<=(n/7); j++ ) {
            if( (i*4+j*7)==n ) {
                flg = true;
                break;
            }
        }
        if(flg) break;
    }

    if(flg) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
