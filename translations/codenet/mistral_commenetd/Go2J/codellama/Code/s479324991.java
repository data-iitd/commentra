
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements in the array from the standard input
        int n = sc.nextInt();

        // Allocate memory for the array of size n
        double[] arr = new double[n];

        // Read n integers from the standard input and store them in the array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextDouble();
        }

        // Sort the array in ascending order
        Arrays.sort(arr);

        // Initialize a variable prev to store the previous element in the sorted array
        double prev = arr[0];

        // Iterate through the sorted array from the second element to the last
        for (int i = 1; i < arr.length; i++) {
            // Calculate the average of the previous and current elements
            prev = (prev + arr[i]) / 2;
        }

        // Print the result to the standard output
        System.out.println(prev);
    }
}

