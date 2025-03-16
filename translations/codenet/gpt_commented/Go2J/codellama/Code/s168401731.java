
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Initialize file pointers for input and output.
        File fp = new File("input.txt");
        File wfp = new File("output.txt");

        // Check for command line arguments to open input and output files.
        if (args.length > 0) {
            fp = new File(args[0]); // Open input file if provided.
            if (args.length > 1) {
                wfp = new File(args[1]); // Create output file if provided.
            }
        }

        // Create a scanner for reading input and a writer for output.
        Scanner scanner = new Scanner(fp);
        PrintWriter writer = new PrintWriter(wfp);

        // Read the number of integers to process.
        int n = scanner.nextInt();

        // Initialize the answer as "second" and check for odd integers.
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt(); // Read the next integer.
            if (a % 2 == 1) { // Check if the integer is odd.
                ans = "first"; // If odd, set answer to "first".
                break; // Exit the loop early if an odd integer is found.
            }
        }

        // Write the result to the output.
        writer.println(ans);
        writer.flush(); // Ensure all buffered data is written to the output.
    }
}

