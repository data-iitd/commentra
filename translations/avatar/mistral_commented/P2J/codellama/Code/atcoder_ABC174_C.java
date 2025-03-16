
// Import necessary libraries
import java.util.*;
import java.lang.*;
import java.io.*;

// Define constants
class Codechef
{
    static int mod = 1000000007;

    public static void main (String[] args) throws java.lang.Exception
    {
        // Set recursion limit to avoid stack overflow errors
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(1000000007);
        System.setProperty("stack", stack.toString());

        // Read an integer from standard input and return it
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine().trim());

        // Initialize a variable t to 0
        int t = 0;

        // Loop from 1 to k
        for (int i = 1; i <= k; i++)
        {
            // Calculate the value of t using the current value of i and k
            t = ( (t % k) * 10 + 7 ) % k;

            // Check if t is a multiple of k
            if (t == 0)
            {
                // Print the value of i and break out of the loop
                System.out.println(i);
                break;
            }
        }

        // If the loop completes without finding a multiple of k, print -1
        if (t != 0)
        {
            System.out.println(-1);
        }
    }
}

