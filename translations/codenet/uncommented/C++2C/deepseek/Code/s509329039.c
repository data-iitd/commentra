#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<vi>
#define vll vector<vl>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	int n,m;
    scanf("%d %d",&n,&m);
    int s[m],c[m];
    FOR(i,0,m){
        scanf("%d %d",&s[i],&c[i]);
        s[i]--;
    }
    FOR(i,0,1000){
        char st[10];
        sprintf(st,"%d",i);
        if (strlen(st)!=n){
            continue;
        }
        int f=1;
        FOR(j,0,m){
            if(st[s[j]]==c[j]+'0'){

            }else{
                f=0;
            }
        }
        if(f){
            printf("%d\n",i);
            return 0;
        }

    }
    printf("-1\n");

}
