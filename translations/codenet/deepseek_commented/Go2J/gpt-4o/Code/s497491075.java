import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Run(System.in, System.out);
    }

    // Run function reads input from the reader, processes it, and writes the output to the writer.
    public static void Run(InputStreamReader input, PrintWriter output) throws IOException {
        BufferedReader reader = new BufferedReader(input);
        StringTokenizer st = new StringTokenizer(reader.readLine());
        
        // Read the first line which contains two integers N and D.
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());

        // Initialize a counter to keep track of points within the given distance.
        int count = 0;

        // Read the next N lines which contain pairs of integers representing points.
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            // Calculate the Euclidean distance of the point from the origin.
            double distance = Math.sqrt(x * x + y * y);
            // Check if the distance is within the given limit.
            if (D >= distance) {
                count++;
            }
        }

        // Write the count of points within the distance to the writer.
        output.println(count);
        output.flush();
    }
}

// <END-OF-CODE>
