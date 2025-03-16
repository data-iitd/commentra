#include<stdio.h>
#include<string.h>
#define M 1010 // Step 2: Define constant for string length
char a[M],b[M]; // Step 2: Define arrays to store input strings
int n,m,ans=M+10; // Step 2: Define variables for string lengths and minimum differences

int main()
{
    // Step 3: Read input strings
    scanf("%s",a+1); n=strlen(a+1); // Read and store the length of string a
    scanf("%s",b+1); m=strlen(b+1); // Read and store the length of string b
    
    // Step 4: Calculate the minimum number of differences
    for(int i=1; i+m-1<=n; i++) // Iterate over possible starting positions
    {
        int sum=0; // Initialize sum of differences for current starting position
        for(int j=1; j<=m; j++) // Compare each character of b with corresponding character in a
            if(a[i+j-1]!=b[j]) // Check if characters are different
                sum++; // Increment sum if characters are different
        ans=min(ans,sum); // Update minimum differences
    }
    
    // Step 5: Output the result
    printf("%d\n",ans); // Print the minimum number of differences
    
    return 0;
}
