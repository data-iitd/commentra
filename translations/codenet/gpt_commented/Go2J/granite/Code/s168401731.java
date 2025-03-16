
import java.io.*;
import java.util.*;

public class s168401731{
    public static void main(String[] args) throws IOException {
        // Initialize file pointers for input and output.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Check for command line arguments to open input and output files.
        if (args.length > 0) {
            br = new BufferedReader(new FileReader(args[0])); // Open input file if provided.
            if (args.length > 1) {
                bw = new BufferedWriter(new FileWriter(args[1])); // Create output file if provided.
            }
        }

        // Read the number of integers to process.
        int n = Integer.parseInt(br.readLine());

        // Initialize the answer as "second" and check for odd integers.
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(br.readLine()); // Read the next integer.
            if (a % 2 == 1) { // Check if the integer is odd.
                ans = "first"; // If odd, set answer to "first".
                break; // Exit the loop early if an odd integer is found.
            }
        }

        // Write the result to the output.
        bw.write(ans);
        bw.newLine();
        bw.flush(); // Ensure all buffered data is written to the output.

        bw.close();
    }
}
