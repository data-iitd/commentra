import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Call the run method with standard input and output streams
        Run(System.in, System.out);
    }

    // Function Run calculates the number of points within a square with side length D and center at (0,0)
    public static void Run(InputStreamReader r, PrintWriter w) throws IOException {
        // Initialize a new scanner object to read input
        BufferedReader br = new BufferedReader(r);
        StringTokenizer st = new StringTokenizer(br.readLine());

        // Read the first line of input containing N and D
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        // Read N lines of input and store them in a list called lines
        List<int[]> lines = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            lines.add(new int[]{x, y});
        }

        // Initialize a counter variable count to 0
        int count = 0;

        // Iterate through each line in the lines list
        for (int[] line : lines) {
            // Calculate the Euclidean distance of the current line from the origin (0,0)
            double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);

            // If the distance of the current line is less than or equal to D, increment the counter
            if (D >= d) {
                count++;
            }
        }

        // Write the final result to the output writer
        w.println(count);
        w.flush();
    }
}

// <END-OF-CODE>
