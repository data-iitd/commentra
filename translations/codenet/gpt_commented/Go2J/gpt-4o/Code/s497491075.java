import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Call the run method with standard input and output
        new Main().run();
    }

    // Run method processes input and writes output
    private void run() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        // Read the first line of input and parse N (number of lines) and D (distance threshold)
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(tokenizer.nextToken());
        double D = Double.parseDouble(tokenizer.nextToken());

        // Initialize a counter for the number of points within the distance D
        int count = 0;

        // Read the next N lines of input, each containing a pair of integers
        for (int i = 0; i < N; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(tokenizer.nextToken());
            int y = Integer.parseInt(tokenizer.nextToken());

            // Calculate the Euclidean distance from the origin (0, 0)
            double distance = Math.sqrt(x * x + y * y);

            // Check if the distance is less than or equal to D
            if (distance <= D) {
                count++; // Increment the count if within distance
            }
        }

        // Output the total count of points within distance D
        writer.println(count);
        writer.flush();
    }
}
