#include <stdio.h>

int main(void)
{
    // Your code here!
    unsigned long n;
    scanf("%lu", &n);
    int flg=0;
    if( n<4 ){
        printf("No\n");
    }else{
        for( int i=0; i<=(n/4); i++)
        {
            for( int j=0; j<=(n/7); j++ )
            {
                if( (i*4+j*7)==n )
                {
                    flg=1;
                    break;
                }
            }
            if(flg) break;
        }
        if(flg)
        {
            printf("Yes\n");
        }else{    
            printf("No\n");
        }
    }
}
