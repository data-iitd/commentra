#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int prevWinner=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                if(prevWinner==0)
                    prevWinner=2;
            }
            if(prevWinner==2 || prevWinner==0){
                if((arr[i]-1)%2==0)
                    printf("2\n");
                else
                    printf("1\n");
                prevWinner=2;
            }
            else{
                if((arr[i]-1)%2==0)
                    printf("1\n");
                else
                    printf("2\n");
                prevWinner=1;
            }
        }
    }
    return 0;
}
