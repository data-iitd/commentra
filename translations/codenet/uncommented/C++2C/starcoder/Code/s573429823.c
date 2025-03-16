#include <stdio.h>
int main(void)
{
    // Your code here!
    unsigned long n;
    scanf("%lu", &n);
    bool flg=false;
    if( n<4 ){
        printf("No\n");
    }else{
        for( int i=0; i<=(n/4); i++)
        {
            for( int j=0; j<=(n/7); j++ )
            {
                if( (i*4+j*7)==n )
                {
                    flg=true;
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
