#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;

int main(void){
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // cout << fixed << setprecision(20);
    int n;scanf("%d",&n);
    int *a = (int*)malloc(sizeof(int)*n);
    REP(i,n)scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    REP(i,n-1){
        if(a[i] == a[i+1]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
        
    return 0;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

