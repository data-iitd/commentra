#include <stdio.h>
#include <string.h>

int main() {
	char s1[100],s2[100],s3[100];
	scanf("%s %s %s",s1,s2,s3);

	char *s1s[100];
	char *s2s[100];
	char *s3s[100];

	s1s = strsplit(s1," ");
	s2s = strsplit(s2," ");
	s3s = strsplit(s3," ");

	printf("%c%c%c",s1s[0][0],s2s[0][0],s3s[0][0]);
}

char **strsplit(char *s, char *delim) {
	char **ret = malloc(sizeof(char*)*100);
	int i = 0;
	char *p = s;
	while(1) {
		char *q = strstr(p,delim);
		if(q == NULL) {
			ret[i] = malloc(sizeof(char)*(strlen(p)+1));
			strcpy(ret[i],p);
			break;
		}
		ret[i] = malloc(sizeof(char)*(q-p+1));
		strncpy(ret[i],p,q-p);
		ret[i][q-p] = '\0';
		i++;
		p = q+1;
	}
	return ret;
}

