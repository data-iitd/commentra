
#include<stdio.h>
#include<string.h>

// Define a constant for the maximum size of the strings
#define M 1010

// Declare character arrays to hold the input strings
char a[M], b[M];

// Declare variables for the lengths of the strings and the minimum answer
int n, m, ans=M+10;

int main()
{
    // Read the first string into array 'a' starting from index 0
    scanf("%s", a);
    // Calculate the length of the first string
    n = strlen(a);
    
    // Read the second string into array 'b' starting from index 0
    scanf("%s", b);
    // Calculate the length of the second string
    m = strlen(b);
    
    // Iterate over all possible starting positions in 'a' where 'b' can fit
    for(int i = 0; i + m - 1 <= n; i++)
    {
        // Initialize a variable to count the number of mismatches
        int sum = 0;
        
        // Compare the substring of 'a' with 'b' character by character
        for(int j = 0; j < m; j++)
            // Increment the mismatch count if characters do not match
            if(a[i + j]!= b[j])
                sum++;
        
        // Update the minimum number of mismatches found
        ans = ans < sum? ans : sum;
    }
    
    // Output the minimum number of mismatches
    printf("%d\n", ans);
    
    return 0; // End of the program
}
