

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int main(int argc, char *argv[]){
	int maxsize=0;
	int maxcnt=0;
	int ans_num;
	int ans_num2;
	char *str_v[1000];
	
	char in[1000];
	while(scanf("%s",in)){
		str_v[maxsize] = (char *)malloc(strlen(in)+1);
		strcpy(str_v[maxsize],in);
		maxsize++;
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = maxsize-1;
		}
	}
	for(int i=0;i<maxsize;i++){
		int cnt=0;
		for(int j=0;j<maxsize;j++){
			if(strcmp(str_v[i],str_v[j])==0) cnt++;
		}
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}
	
	printf("%s %s\n",str_v[ans_num2],str_v[ans_num]);
	
	return 0;
}

 

