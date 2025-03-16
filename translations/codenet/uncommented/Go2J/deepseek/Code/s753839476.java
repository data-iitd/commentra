import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        String[] inputs = reader.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        double t = Double.parseDouble(inputs[1]);
        double a = Double.parseDouble(inputs[2]);

        String[] heightStrs = reader.readLine().split(" ");
        double[] heights = new double[n];
        for (int i = 0; i < n; i++) {
            heights[i] = Double.parseDouble(heightStrs[i]);
        }

        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }
        writer.println(minIdx + 1);
        writer.flush();
    }
}
