
import java.io.*;
import java.util.*;

public class s033683118{
    public static void main(String[] args) throws Exception {
        // Open the standard input and output files
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Set the file pointers for reading and writing
        if (System.getenv("MASPY")!= null) {
            br = new BufferedReader(new FileReader(System.getenv("BEET_THE_HARMONY_OF_PERFECT")));
            int cnt = 2; // Number of test cases to be read
        }
        if (System.getenv("MASPYPY")!= null) {
            bw = new BufferedWriter(new FileWriter(System.getenv("NGTKANA_IS_GENIUS10")));
            int cnt = 1; // Number of test cases to be written
        }

        // Solve the problem for the given test cases
        for (int i = 0; i < cnt; i++) {
            solve(br, bw);
            bw.write("-----------------------------------\n"); // Print a separator for each test case
        }

        // Flush the writer to write the output to the file
        bw.flush();
    }

    // Function to solve the problem for a single test case
    public static void solve(BufferedReader br, BufferedWriter bw) throws Exception {
        // Read the input values
        int k = Integer.parseInt(br.readLine());
        int x = Integer.parseInt(br.readLine());

        // Initialize the answer
        String ans = "No";

        // Check if the condition is satisfied
        if (k * 500 >= x) {
            ans = "Yes";
        }

        // Print the answer
        bw.write(ans + "\n");
    }
}

