import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of values
        double[] values = new double[N];
        
        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextDouble(); // Read the values into the array
        }

        Arrays.sort(values); // Sort the values in ascending order
        double generated = 0;

        // Uncomment the following line to print the sorted values (for debugging purposes)
        // System.out.println(Arrays.toString(values));

        for (int i = 0; i < N - 1; i++) {
            generated = (values[i] + values[i + 1]) / 2; // Calculate the average of the current and next value
            values[i + 1] = generated; // Update the next value with the calculated average
        }

        System.out.println(generated); // Print the final generated value
    }
}

// <END-OF-CODE>
