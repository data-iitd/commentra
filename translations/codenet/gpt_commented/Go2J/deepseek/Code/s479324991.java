import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();
        // Create a list to hold the float64 values
        List<Double> arr = new ArrayList<>();

        // Read n integers from input and convert them to float64
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextDouble());
        }

        // Sort the list of float64 values
        Collections.sort(arr);

        // Initialize 'prev' with the first element of the sorted list
        double prev = arr.get(0);

        // Calculate the average of the elements iteratively
        for (int i = 1; i < arr.size(); i++) {
            prev = (prev + arr.get(i)) / 2;
        }

        // Print the final computed average
        System.out.printf("%.6f\n", prev);
    }
}
