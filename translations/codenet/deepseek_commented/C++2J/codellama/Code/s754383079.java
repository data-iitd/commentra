// Step 1: Import required libraries
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // Step 2: Define constant for string length
        final int M=1010;
        
        // Step 3: Define arrays to store input strings
        char a[]=new char[M];
        char b[]=new char[M];
        
        // Step 4: Read input strings
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        String s2=sc.next();
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<n;i++)
            a[i+1]=s1.charAt(i);
        for(int i=0;i<m;i++)
            b[i+1]=s2.charAt(i);
        
        // Step 5: Calculate the minimum number of differences
        int ans=M+10;
        for(int i=1;i+m-1<=n;i++)
        {
            int sum=0;
            for(int j=1;j<=m;j++)
                if(a[i+j-1]!=b[j])
                    sum++;
            ans=Math.min(ans,sum);
        }
        
        // Step 6: Output the result
        System.out.println(ans);
    }
}
