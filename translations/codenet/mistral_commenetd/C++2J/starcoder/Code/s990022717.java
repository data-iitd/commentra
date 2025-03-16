import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input from stdin
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        // Initialize sum variable to 0
        int sum = 0;

        // Iterate through numbers from 1 to n
        for(int i=1;i<=n;i++){
            // If the current number i is greater than k, add y to the sum
            if(i>k)sum+=y;
            // Otherwise, add x to the sum
            else sum+=x;
        }

        // Output the final sum value to the standard output
        System.out.println(sum);
    }
}
