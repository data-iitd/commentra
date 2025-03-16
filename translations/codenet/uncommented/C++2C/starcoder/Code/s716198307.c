#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void){
    int n,a[100];
    double avg=0,s,ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        avg+=a[i];
    }
    avg/=n;
    s=abs(a[0]-avg);
    ans=0;
    for(int i=1;i<n;i++){
        if(s>abs(a[i]-avg)){
            s=abs(a[i]-avg);
            ans=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
