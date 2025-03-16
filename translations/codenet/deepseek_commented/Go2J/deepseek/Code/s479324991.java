import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Initialize an array to hold the float values
        double[] arr = new double[n];

        // Read each integer and convert it to double, then store in the array
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextDouble();
        }

        // Sort the array of double values
        Arrays.sort(arr);

        // Initialize a variable to keep track of the running average
        double prev = arr[0];

        // Iterate through the sorted array to calculate the average
        for (int i = 1; i < arr.length; i++) {
            prev = (prev + arr[i]) / 2;
        }

        // Print the final average
        System.out.printf("%.6f\n", prev);
    }
}
