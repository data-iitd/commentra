
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<assert.h>
#include<limits.h>
#include<stdarg.h>
#include<algorithm>
#include<numeric>
#include<functional>
#include<utility>
#include<bitset>
#include<set>
#include<map>

#define REP(i,n) for(int i=0;i<n;i++)
#define REPN(i,n) for(int i=1;i<=n;i++)
#define FORD(i,a,b) for(int i=a;i<=b;i++)
#define FORU(i,a,b) for(int i=a;i>=b;i--)
#define FORDIN(i,a,b) for(int i=a;i>=b;i--)
#define FORUIN(i,a,b) for(int i=a;i<=b;i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define FORITR(i,m) for(__typeof((m).rbegin())i=(m).rbegin();i!=(m).rend();i++)

#define mp make_pair
#define pb push_back
#define fill(a,v) memset(a, v, sizeof(a))
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i!= (c).end(); i++)
#define present(c,x) ((c).find(x)!= (c).end())
#define cpresent(c,x) (find(all(c),x)!= (c).end())

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
/*Main Code*/
#define EXIT_SUCCESSFULLY 0

int main(){
    map<int,int>m;
    for(int i=0;i*200<5001;i++){
        for(int j=0;j*300<5001;j++){
            for(int k=0;k*500<5001;k++){
                int w=i*200+j*300+k*500;
                int p=i/5*5*380*0.8+i%5*380
                     +j/4*4*550*0.85+j%4*550
                     +k/3*3*850*0.88+k%3*850;
                if(m[w])m[w]=min(m[w],p);
                else m[w]=p;
            }
        }
    }
    int n;
    while(scanf("%d",&n),n){
        printf("%d\n",m[n]);
    }
    return EXIT_SUCCESSFULLY;
}
