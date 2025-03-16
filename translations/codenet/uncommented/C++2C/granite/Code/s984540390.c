
#include <stdio.h>

int main(){
	int h;
	scanf("%d",&h);
	while(h!=1){
		if(h%2!=0) h--;
		h/=2;
		cnt*=2;
		ans+=cnt;
	}
	printf("%d\n",ans+1);
}
