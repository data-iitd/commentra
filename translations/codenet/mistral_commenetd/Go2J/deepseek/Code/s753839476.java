import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

        // Read input values
        int n = Integer.parseInt(reader.readLine());
        double t = Double.parseDouble(reader.readLine());
        double a = Double.parseDouble(reader.readLine());

        // Initialize variables for heights and minimum difference
        String[] heightsStr = reader.readLine().split(" ");
        double[] heights = new double[n];
        for (int i = 0; i < n; i++) {
            heights[i] = Double.parseDouble(heightsStr[i]);
        }

        double minDiff = Math.abs(t - heights[0] * 0.006);
        int minIdx = 0;

        // Iterate through the remaining heights and find the minimum difference
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006);

            // Update minimum difference and index if the current difference is smaller
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }

        // Print the result
        writer.println(minIdx + 1);
        writer.flush();
    }
}

