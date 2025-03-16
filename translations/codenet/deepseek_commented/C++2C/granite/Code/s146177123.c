
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Array to represent the segments of the digits 0-9
int seg[][7]={
	{0,1,1,1,1,1,1}, // 0
	{0,0,0,0,1,1,0}, // 1
	{1,0,1,1,0,1,1}, // 2
	{1,0,0,1,1,1,1}, // 3
	{1,1,0,0,1,1,0}, // 4
	
	{1,1,0,1,1,0,1}, // 5
	{1,1,1,1,1,0,1}, // 6
	{0,1,0,0,1,1,1}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,0,1,1,1,1}  // 9
};

int main()
{
	int n,t; int st[7];
	while(scanf("%d",&n),~n){ // Read the number of digits and check if it's not zero
		// Initialize the state array to represent the current display state
		memset(st,0,sizeof(st));
		rep(i,n){
			scanf("%d",&t); // Read the next digit
			char ans[8]={0}; // Array to store the current display state
			rep(i,7){
				// Calculate the current segment state and store it in the answer array
				ans[i]=st[i]^seg[t][i]?'1':'0';
				// Update the state array with the current segment state
				st[i]=seg[t][i];
			}
			// Output the current display state
			puts(ans);
		}
	}
	
	return 0;
}

