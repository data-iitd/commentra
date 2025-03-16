#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
using namespace std;

int main(void){
    int n;scanf("%d", &n);
    int a[n];REP(i,n)scanf("%d", &a[i]);
    std::sort(a, a + n);
    REP(i,n-1){
        if(a[i] == a[i+1]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
        
    return 0;
}
