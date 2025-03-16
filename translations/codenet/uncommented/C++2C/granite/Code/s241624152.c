
#include <stdio.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    char* ans;
    if (a == 1 || b == 1){
        if (a == 1 && b == 1){
            ans = "Draw";
        } else if (a == 1){
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    } else {
        if (a == b){
            ans = "Draw";
        } else if (a > b){
            ans = "Alice";
        } else {
            ans = "Bob";
        }
    }
    printf("%s\n",ans);

    return 0;
}


