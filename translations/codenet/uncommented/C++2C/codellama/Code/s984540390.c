#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e8,cnt=1;

int main(){
	ll h;
	scanf("%lld",&h);
	while(h!=1){
		if(h%2!=0) h--;
		h/=2;
		cnt*=2;
		ans+=cnt;
	}
	printf("%lld\n",ans+1);
}

