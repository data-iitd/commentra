#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <complex.h>
#include <stdbool.h>

bool solve(){
	int maxsize=0;
	int maxcnt=0;
	int ans_num;
	int ans_num2;
	char **str_v;
	int str_v_size = 0;
	char in[100];
	
	str_v = (char **)malloc(100 * sizeof(char *));
	for(int i = 0; i < 100; i++) {
		str_v[i] = (char *)malloc(100 * sizeof(char));
	}
	
	while(scanf("%s", in) != EOF){
		strcpy(str_v[str_v_size], in);
		if(maxsize < strlen(in)){
			maxsize = strlen(in);
			ans_num = str_v_size;
		}
		str_v_size++;
	}
	for(int i=0;i<str_v_size;i++){
		int cnt=0;
		for(int j=0;j<str_v_size;j++){
			if(strcmp(str_v[i], str_v[j]) == 0) cnt++;
		}
		if(maxcnt < cnt){
			maxcnt = cnt;
			ans_num2 = i;
		}
	}
	
	printf("%s %s\n", str_v[ans_num2], str_v[ans_num]);
	
	for(int i = 0; i < 100; i++) {
		free(str_v[i]);
	}
	free(str_v);
	
	return true;
}

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	solve();

	return 0;
}

