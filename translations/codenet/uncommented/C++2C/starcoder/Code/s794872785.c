
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define MAX_STR_LEN 100000

int main(){
	char in[MAX_STR_LEN];
	int maxsize=0;
	int maxcnt=0;
	int ans_num;
	int ans_num2;
	int str_v_size=0;
	char **str_v;
	
	while(scanf("%s",in)!=EOF){
		str_v_size++;
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = str_v_size-1;
		}
	}
	str_v = (char**)malloc(sizeof(char*)*str_v_size);
	for(int i=0;i<str_v_size;i++){
		str_v[i] = (char*)malloc(sizeof(char)*MAX_STR_LEN);
	}
	for(int i=0;i<str_v_size;i++){
		scanf("%s",in);
		strcpy(str_v[i],in);
	}
	for(int i=0;i<str_v_size;i++){
		int cnt=0;
		for(int j=0;j<str_v_size;j++){
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

