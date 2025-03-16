
#include <stdio.h>

int main(){
	// Declare two string variables s and t
	char s[100], t[100];
	
	// Read input from the user and store it in s and t
	scanf("%s %s", s, t);
	
	// Print the concatenated result of t and s
	printf("%s%s\n", t, s);
	
	return 0;
}
