import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the input values for n and k from the standard input
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();

        // Initialize a variable to store the sum of the results
        long sum = 0;

        // Iterate through all possible block sizes from 1 to n
        for(int b = 1; b <= n; b++){
            // Calculate the number of blocks of size b that can fit into n+1
            int cnt = (n+1)/b;

            // Calculate the remainder of n+1 when divided by b
            int md = (n+1)%b;

            // Add the number of blocks of size b that cover k or more numbers to the sum
            sum+=cnt*Math.max(b-k,0)+Math.max(md-k,0);

            // If k is 0, subtract 1 from the sum (since an empty block doesn't contribute to the sum)
            if(k==0) sum--;
        }

        // Print the result to the standard output
        System.out.println(sum);
    }
}

