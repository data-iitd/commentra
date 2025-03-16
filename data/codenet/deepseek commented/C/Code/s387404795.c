#include <stdio.h>
#include <string.h>

int main(void) {
	char str[201], tmp[101];
	char p[101];
	int slen, plen;
	int i, j, flag;
	
	// Read two strings from the user
	scanf("%s %s", str, p);
	
	// Duplicate and concatenate the string
	strcpy(tmp, str);
	strcat(str, tmp);
	
	// Calculate the lengths of the strings
	slen = strlen(str);
	plen = strlen(p);
	
	// Initialize flag to 0 (not found)
	flag = 0;
	
	// Check if the pattern exists in the concatenated string
	for (i = 0; i < slen - plen; i++) {
		if (strncmp(&str[i], p, plen) == 0) flag = 1;
	}
	
	// Output the result
	if (flag) puts("Yes");
	else puts("No");
	
	return 0;
}
