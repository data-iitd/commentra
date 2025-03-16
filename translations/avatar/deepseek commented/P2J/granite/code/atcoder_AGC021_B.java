
import java.io.*;
import java.util.*;

public class atcoder_AGC021_B{
    public static void main(String[] args) throws Exception {
        // Step 1: Reading Input
        // The code reads the number of points N and the coordinates of the points XY from the standard input.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] split = br.readLine().split(" ");
        double[] X = new double[N];
        double[] Y = new double[N];
        for (int i = 0; i < N; i++) {
            X[i] = Double.parseDouble(split[2 * i]);
            Y[i] = Double.parseDouble(split[2 * i + 1]);
        }

        // Step 2: Processing Coordinates
        // The coordinates are grouped into pairs and stored in the list XY.
        List<double[]> XY = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            XY.add(new double[]{X[i], Y[i]});
        }

        // Step 3: Calculating Angles
        // For each point, the code calculates the angles to all other points using atan2.
        for (int i = 0; i < N; i++) {
            // Calculate the angles for each point relative to others
            List<Double> D = new ArrayList<>();
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                double x = XY.get(j)[0] - X[i];
                double y = XY.get(j)[1] - Y[i];
                D.add(Math.atan2(y, x));
            }

            // Step 4: Handling Circular Angles
            // The angles are adjusted to handle the circular nature of angles (0 to 2π).
            Collections.sort(D);
            D.add(D.get(0) + 2 * Math.PI);

            // Step 5: Finding the Maximum Gap
            double ans = 0;
            for (int j = 0; j < D.size() - 1; j++) {
                if (D.get(j + 1) - D.get(j) >= Math.PI) {
                    ans = Math.max(ans, D.get(j + 1) - D.get(j) - Math.PI);
                }
            }

            // Step 6: Calculating the Fraction
            // The fraction of the circle covered by the maximum gap is calculated and printed.
            System.out.println(ans / (2 * Math.PI));
        }
    }
}

Translate the above Java code to C++ and end with comment "