

import java.util.Arrays;
import java.util.Scanner;

public class s876981782{

    public static void main(String[] args) {
        // Initialize variables
        int N;

        // Read input: number of values
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();

        // Allocate memory for N float64 values
        double[] values = new double[N];

        // Read input: N float64 values
        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextDouble();
        }

        // Sort the array in ascending order
        Arrays.sort(values);

        // Calculate the median value
        double generated = 0;
        // Iterate through the array, excluding the last value (which is the maximum)
        for (int i = 0; i < N - 1; i++) {
            // Calculate the average of the current and next value
            generated = (values[i] + values[i + 1]) / 2;

            // Update the next value with the calculated average
            values[i + 1] = generated;
        }

        // Print the calculated median value
        System.out.println(generated);
    }
}

