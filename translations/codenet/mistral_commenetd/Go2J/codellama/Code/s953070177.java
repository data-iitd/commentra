
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Open the standard input as a file
        File fp = new File("/dev/stdin");
        // If there is an argument, open the file with that name instead
        if (args.length > 0) {
            fp = new File(args[0]);
        }

        // Create a new Scanner from the file pointer
        Scanner scanner = new Scanner(fp);

        // Create a new PrintWriter for output
        PrintWriter writer = new PrintWriter(System.out);

        // Read the first integer from the input
        int n = scanner.nextInt();

        // Initialize an array 'aa' of size 'n+2'
        int[] aa = new int[n+2];
        // Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
        int sum = 0;

        // Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
        for (int i = 0; i < n; i++) {
            // Read the next integer from the scanner and store it in 'aa[i+1]'
            aa[i+1] = scanner.nextInt();
            // Calculate the absolute difference between the current and previous elements and add it to the sum
            sum += Math.abs(aa[i+1] - aa[i]);
        }
        // Calculate the absolute difference between the last two elements and add it to the sum
        sum += Math.abs(aa[n+1] - aa[n]);

        // Iterate through the array 'aa' and print the answer for each subarray
        for (int i = 1; i < n+1; i++) {
            // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
            int ans = sum - Math.abs(aa[i+1]-aa[i]) - Math.abs(aa[i]-aa[i-1]) + Math.abs(aa[i+1]-aa[i-1]);
            // Write the answer to the output writer
            writer.println(ans);
        }

        // Flush the buffer to write all the data to the output
        writer.flush();
    }

    // Function to calculate the absolute value of an integer
    public static int absint(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }
}

