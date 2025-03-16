import java.util.*;
import java.io.*;

public class Main
{
    public static void main(String[] args)
    {
        // Read the first string into array 'a' starting from index 1
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        // Calculate the length of the first string
        int n = a.length();
        
        // Read the second string into array 'b' starting from index 1
        String b = sc.next();
        // Calculate the length of the second string
        int m = b.length();
        
        // Iterate over all possible starting positions in 'a' where 'b' can fit
        for(int i = 1; i + m - 1 <= n; i++)
        {
            // Initialize a variable to count the number of mismatches
            int sum = 0;
            
            // Compare the substring of 'a' with 'b' character by character
            for(int j = 1; j <= m; j++)
                // Increment the mismatch count if characters do not match
                if(a.charAt(i + j - 1)!= b.charAt(j))
                    sum++;
            
            // Update the minimum number of mismatches found
            ans = Math.min(ans, sum);
        }
        
        // Output the minimum number of mismatches
        System.out.println(ans);
    }
}
