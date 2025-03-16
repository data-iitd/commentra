

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 1010 // maximum size of strings a and b
char a[M],b[M]; // strings a and b
int n,m,ans=M+10; // n is the length of string a, m is the length of string b, ans is the minimum number of differences between strings a and b

int main()
{
	// read string a from standard input
	scanf("%s",a+1);
	n=strlen(a+1); // get the length of string a

	// read string b from standard input
	scanf("%s",b+1);
	m=strlen(b+1); // get the length of string b

	// iterate through all possible substrings of string a that have the same length as string b
	for(int i=1;i+m-1<=n;i++)
	{
		// initialize sum to 0, it will be used to count the number of differences between the i-th substring of string a and string b
		int sum=0;

		// iterate through each character in the substring of string a and compare it with the corresponding character in string b
		for(int j=1;j<=m;j++)
			// if the characters are different, increment sum by 1
			if(a[i+j-1]!=b[j])
				sum++;

		// update the minimum number of differences if a smaller number is found
		ans=sum<ans?sum:ans;
	}

	// print the minimum number of differences to standard output
	printf("%d\n",ans);

	// terminate the program with exit code 0
	return 0;
}

