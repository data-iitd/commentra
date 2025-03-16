import java.io.*;
import java.util.*;

public class Main {
    // Function to read the next string from the scanner
    private static String getNextString(Scanner scanner) {
        return scanner.next();
    }

    // Function to read the next integer from the scanner
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner));
    }

    // Function to read the next long from the scanner
    private static long getNextInt64(Scanner scanner) {
        return Long.parseLong(getNextString(scanner));
    }

    // Function to calculate the absolute value of an integer
    private static int absint(int a) {
        return a < 0 ? -a : a;
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Use standard input or a file if provided as an argument
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }
        Scanner scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        // Read the first integer from the input
        int n = getNextInt(scanner);

        // Initialize an array 'aa' of size 'n+2'
        int[] aa = new int[n + 2];
        // Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
        int sum = 0;

        // Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
        for (int i = 0; i < n; i++) {
            // Read the next integer from the scanner and store it in 'aa[i+1]'
            aa[i + 1] = getNextInt(scanner);
            // Calculate the absolute difference between the current and previous elements and add it to the sum
            sum += absint(aa[i + 1] - aa[i]);
        }
        // Calculate the absolute difference between the last two elements and add it to the sum
        sum += absint(aa[n + 1] - aa[n]);

        // Iterate through the array 'aa' and print the answer for each subarray
        for (int i = 1; i < n + 1; i++) {
            // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
            int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
            // Write the answer to the output writer
            writer.println(ans);
        }

        // Flush the writer to write all the data to the output
        writer.flush();
        scanner.close();
    }
}
// <END-OF-CODE>
