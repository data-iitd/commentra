#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define MAX_V 100001
#define MOD 1000000007
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
