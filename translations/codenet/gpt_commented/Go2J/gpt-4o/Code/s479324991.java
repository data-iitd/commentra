import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Initialize a new scanner to read input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements
        int n = sc.nextInt();
        // Create a list to hold the float values
        List<Double> arr = new ArrayList<>();

        // Read n integers from input and convert them to double
        for (int i = 0; i < n; i++) {
            arr.add((double) sc.nextInt());
        }

        // Sort the list of double values
        Collections.sort(arr);

        // Initialize 'prev' with the first element of the sorted list
        double prev = arr.get(0);

        // Calculate the average of the elements iteratively
        for (int i = 1; i < arr.size(); i++) {
            prev = (prev + arr.get(i)) / 2;
        }

        // Print the final computed average
        System.out.printf("%f\n", prev);
    }
}
// <END-OF-CODE>
