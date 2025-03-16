import java.util.*;
import java.io.*;

public class AngleCalculation {
    public static void main(String[] args) throws IOException {
        // Read the input from standard input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        
        // Parse the number of points N and the coordinates
        int N = Integer.parseInt(input[0]);
        double[][] points = new double[N][2];
        
        for (int i = 0; i < N; i++) {
            points[i][0] = Double.parseDouble(input[2 * i + 1]); // x coordinate
            points[i][1] = Double.parseDouble(input[2 * i + 2]); // y coordinate
        }

        // Initialize the answer variable
        double ans = 0;

        // Iterate through each point
        for (int i = 0; i < N; i++) {
            List<Double> angles = new ArrayList<>();

            // Calculate angles with respect to the current point
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    double angle = Math.atan2(points[j][0] - points[i][0], points[j][1] - points[i][1]);
                    angles.add(angle);
                }
            }

            // Sort the angles
            Collections.sort(angles);
            // Wrap around the first angle
            angles.add(angles.get(0) + 2 * Math.PI);

            // Calculate the area of the corresponding sectors
            for (int k = 0; k < angles.size() - 1; k++) {
                double a = angles.get(k);
                double b = angles.get(k + 1);
                if (b - a >= Math.PI) {
                    ans += (b - a) - Math.PI;
                }
            }
        }

        // Print the answer, which is the total area of the sectors divided by the total possible area (2π)
        System.out.println(ans / (2 * Math.PI));
    }
}
// <END-OF-CODE>
