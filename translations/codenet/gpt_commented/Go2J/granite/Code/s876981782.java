
import java.util.Arrays;
import java.util.Scanner;

public class s876981782{

    public static void main(String[] args) {
        // Read the number of values to be processed
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Initialize an array to hold the double values
        double[] values = new double[N];

        // Read N double values from standard input
        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextDouble();
        }

        // Sort the array of double values in ascending order
        Arrays.sort(values);

        // Variable to hold the generated average value
        double generated = 0;

        // Calculate the average of each pair of adjacent values
        for (int i = 0; i < N - 1; i++) {
            generated = (values[i] + values[i + 1]) / 2;
            // Update the next value in the array with the generated average
            values[i + 1] = generated;
        }

        // Print the last generated average value
        System.out.println(generated);
    }
}
