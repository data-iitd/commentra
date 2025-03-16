#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    char ans[100];
    if (a == 1 || b == 1){
        if (a == 1 && b == 1){
            strcpy(ans, "Draw");
        } else if (a == 1){
            strcpy(ans, "Alice");
        } else {
            strcpy(ans, "Bob");
        }
    } else {
        if (a == b){
            strcpy(ans, "Draw");
        } else if (a > b){
            strcpy(ans, "Alice");
        } else {
            strcpy(ans, "Bob");
        }
    }
    printf("%s\n", ans);



    return 0;
}
