import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array from the standard input
        int n = scanner.nextInt();

        // Allocate memory for the array of size n
        List<Double> arr = new ArrayList<>(n);

        // Read n integers from the standard input and store them in the array
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextDouble());
        }

        // Sort the array in ascending order
        Collections.sort(arr);

        // Initialize a variable prev to store the previous element in the sorted array
        double prev = arr.get(0);

        // Iterate through the sorted array from the second element to the last
        for (int i = 1; i < arr.size(); i++) {
            // Calculate the average of the previous and current elements
            prev = (prev + arr.get(i)) / 2;
        }

        // Print the result to the standard output
        System.out.printf("%.1f\n", prev);
    }
}
