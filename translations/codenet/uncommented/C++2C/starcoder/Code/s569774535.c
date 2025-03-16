#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int ans=0;
    bool ok = true;
    while(ok){
        for(int i=0;i<n;i++){
            if(a[i]%2 == 1){
                printf("%d\n",ans);
                return 0;
            }
            else{
                a[i] /= 2;
            }
        }
        ans++;
    }

    printf("%d\n",ans);
}

