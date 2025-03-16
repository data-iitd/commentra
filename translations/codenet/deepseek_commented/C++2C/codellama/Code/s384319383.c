#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(), (v).end() // Corrected the macro to use proper syntax
#define INF 1e9
#define MOD 1e9+7
typedef long long llong;

int main(){
	int n;
	scanf("%d", &n); // Read the number of characters
	int *cnt = (int*)malloc(26*sizeof(int)); // Initialize a vector to count occurrences of each letter, starting with 1 for each
	char *s = (char*)malloc(n*sizeof(char)); // Vector to store the characters
	REP(i, n){
		scanf("%c", &s[i]); // Read each character
		cnt[s[i] - 'a']++; // Increment the count for the corresponding letter
	}

	llong ans = cnt[0]; // Initialize the answer with the count of the first letter
	for(int i = 1; i < 26; ++i){ // Loop through the counts of other letters
		ans *= cnt[i]; // Multiply the answer by the count of the current letter
		ans %= (int)MOD; // Take the modulo to prevent overflow
	}

	printf("%lld\n", ans - 1); // Output the result, subtracting 1 because we don't count the empty set
	return 0;
}
