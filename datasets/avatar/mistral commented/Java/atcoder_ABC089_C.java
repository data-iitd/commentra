
import java.io.OutputStream; // Output stream to write output
import java.io.IOException; // For handling I/O related exceptions
import java.io.InputStream; // Input stream to read input
import java.util.Arrays; // For using Arrays.fill() method
import java.util.Scanner; // For reading input

public class Main {
    // Main method to start the program
    public static void main(String[] args) {
        InputStream inputStream = System.in; // Input stream from standard input
        OutputStream outputStream = System.out; // Output stream to standard output
        Scanner in = new Scanner(inputStream); // Initialize scanner for reading input
        PrintWriter out = new PrintWriter(outputStream); // Initialize print writer for writing output

        TaskC solver = new TaskC(); // Create an instance of the TaskC class
        solver.solve(1, in, out); // Call the solve method with test number, input scanner, and output print writer

        out.close(); // Close the output print writer
    }

    static class TaskC {
        // Class to solve the problem

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // Method to solve the problem

            int n = in.nextInt(); // Read the number of test cases

            long[] cnt = new long[5]; // Initialize an array of size 5 to store counts

            Arrays.fill(cnt, 0); // Initialize all elements of the array to zero

            for (int i = 0; i < n; ++i) {
                // Loop through each test case

                String str = in.next(); // Read a string from input

                if (str.charAt(0) == 'M') {
                    // If the first character of the string is 'M', increment the count of 'M'
                    cnt[0]++;
                } else if (str.charAt(0) == 'A') {
                    // If the first character of the string is 'A', increment the count of 'A'
                    cnt[1]++;
                } else if (str.charAt(0) == 'R') {
                    // If the first character of the string is 'R', increment the count of 'R'
                    cnt[2]++;
                } else if (str.charAt(0) == 'C') {
                    // If the first character of the string is 'C', increment the count of 'C'
                    cnt[3]++;
                } else if (str.charAt(0) == 'H') {
                    // If the first character of the string is 'H', increment the count of 'H'
                    cnt[4]++;
                }
            }

            long res = cnt[0] * cnt[1] * cnt[2] + // Calculate the first product
                    cnt[0] * cnt[1] * cnt[3] + // Calculate the second product
                    cnt[0] * cnt[1] * cnt[4] + // Calculate the third product
                    cnt[0] * cnt[2] * cnt[3] + // Calculate the fourth product
                    cnt[0] * cnt[2] * cnt[4] + // Calculate the fifth product
                    cnt[0] * cnt[3] * cnt[4] + // Calculate the sixth product
                    cnt[1] * cnt[2] * cnt[3] + // Calculate the seventh product
                    cnt[1] * cnt[2] * cnt[4] + // Calculate the eighth product
                    cnt[1] * cnt[3] * cnt[4] + // Calculate the ninth product
                    cnt[2] * cnt[3] * cnt[4]; // Calculate the tenth product

            out.println(res); // Write the result to the output
        }
    }
}

