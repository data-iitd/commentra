import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        // Step 3: Read input strings
        Scanner sc=new Scanner(System.in);
        String a=sc.next();
        String b=sc.next();
        int n=a.length(),m=b.length(); // Step 2: Define variables for string lengths and minimum differences
        
        // Step 4: Calculate the minimum number of differences
        for(int i=1; i+m-1<=n; i++) // Iterate over possible starting positions
        {
            int sum=0; // Initialize sum of differences for current starting position
            for(int j=1; j<=m; j++) // Compare each character of b with corresponding character in a
                if(a.charAt(i+j-1)!=b.charAt(j)) // Check if characters are different
                    sum++; // Increment sum if characters are different
            ans=Math.min(ans,sum); // Update minimum differences
        }
        
        // Step 5: Output the result
        System.out.println(ans); // Print the minimum number of differences
    }
}
