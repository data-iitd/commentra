import java.util.*;
import java.io.*;

// Define a constant for the maximum size of the strings
final int M=1010;

// Declare character arrays to hold the input strings
char[] a=new char[M];
char[] b=new char[M];

// Declare variables for the lengths of the strings and the minimum answer
int n, m, ans=M+10;

public static void main(String[] args)
{
    // Read the first string into array 'a' starting from index 1
    Scanner in=new Scanner(System.in);
    String s=in.next();
    for(int i=0;i<s.length();i++)
        a[i+1]=s.charAt(i);
    n=s.length();
    
    // Read the second string into array 'b' starting from index 1
    s=in.next();
    for(int i=0;i<s.length();i++)
        b[i+1]=s.charAt(i);
    m=s.length();
    
    // Iterate over all possible starting positions in 'a' where 'b' can fit
    for(int i=1;i+m-1<=n;i++)
    {
        // Initialize a variable to count the number of mismatches
        int sum=0;
        
        // Compare the substring of 'a' with 'b' character by character
        for(int j=1;j<=m;j++)
            // Increment the mismatch count if characters do not match
            if(a[i+j-1]!=b[j])
                sum++;
        
        // Update the minimum number of mismatches found
        ans=Math.min(ans, sum);
    }
    
    // Output the minimum number of mismatches
    System.out.println(ans);
}

