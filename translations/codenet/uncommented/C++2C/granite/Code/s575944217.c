
#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    int ans[n];
    for(int i=0;i<n-1;i++){
        int a;scanf("%d",&a);
        a--;
        ans[a]++;
    }
    for(int i=0;i<n;i++) printf("%d\n",ans[i]);
}


