import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import static java.lang.Integer.parseInt;

/**
 * Point Card
 */
public class Main {

    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        String[] words;

        // Read the first line of input which contains N and M
        line = br.readLine();

        // Parse N (the target points) and M (the number of entries)
        int N, M;
        N = parseInt(line.substring(0, line.indexOf(' '))); // Extract N from the input
        M = parseInt(line.substring(line.indexOf(' ') + 1)); // Extract M from the input

        // Initialize an array to hold the shortage of points for each entry
        int[] shortage = new int[M];

        // Loop through each entry to calculate the shortage of points
        for (int i = 0; i < M; i++) {
            line = br.readLine(); // Read the next line of input
            int A = parseInt(line.substring(0, line.indexOf(' '))); // Extract the current points A
            // Calculate the shortage: if N > A, store the difference; otherwise store 0
            shortage[i] = N > A ? N - A : 0;
        }

        // Sort the shortage array to facilitate further calculations
        Arrays.sort(shortage);

        // Initialize a variable to hold the total shortage points
        int ans = 0;

        // Sum up the shortages, excluding the last entry
        for (int i = 0; i < M - 1; i++) {
            ans += shortage[i]; // Accumulate the shortage points
        }

        // Output the total shortage points
        System.out.println(ans);
    }
}
