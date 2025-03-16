#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

int main(){
	int h;
	scanf("%d",&h);
	while(h!=1){
		if(h%2!=0) h--;
		h/=2;
	}
	printf("%d\n",h+1);
}

