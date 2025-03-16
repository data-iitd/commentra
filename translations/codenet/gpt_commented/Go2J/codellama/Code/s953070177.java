
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Determine the input source: standard input or a file specified as a command-line argument.
        BufferedReader fp = new BufferedReader(new InputStreamReader(System.in));
        if (args.length > 0) {
            fp = new BufferedReader(new FileReader(args[0]));
        }

        // Initialize the scanner for reading input.
        Scanner scanner = new Scanner(fp);

        // Create a buffered writer for output.
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of elements from the input.
        int n = scanner.nextInt();

        // Initialize an array to hold the elements and a variable to store the total sum of absolute differences.
        int[] aa = new int[n+2];
        int sum = 0;

        // Read the elements into the array and calculate the total sum of absolute differences between consecutive elements.
        for (int i = 0; i < n; i++) {
            aa[i+1] = scanner.nextInt();
            sum += Math.abs(aa[i+1] - aa[i]);
        }
        // Include the difference between the last element and the element before it.
        sum += Math.abs(aa[n+1] - aa[n]);

        // Calculate and print the result for each element.
        for (int i = 1; i < n+1; i++) {
            // Calculate the new sum of absolute differences if the i-th element is removed.
            int ans = sum - Math.abs(aa[i+1]-aa[i]) - Math.abs(aa[i]-aa[i-1]) + Math.abs(aa[i+1]-aa[i-1]);
            writer.write(ans + "\n"); // Output the result for the current element.
        }

        // Flush the buffered writer to ensure all output is written.
        writer.flush();
    }

    // absint returns the absolute value of an integer.
    public static int absint(int a) {
        if (a < 0) {
            return -a;
        }
        return a;
    }
}

