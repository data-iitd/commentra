import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the value of n from the standard input
        double[] a = new double[n]; // Create an array of double with n elements
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble(); // Read n floating-point numbers from the standard input to populate the array a
        }
        
        while (a.length > 1) { // Continue until only one element remains in the array a
            Arrays.sort(a); // Sort the array a in ascending order
            double[] na = new double[a.length - 1]; // Create a new array na to store the updated elements
            for (int j = 2; j < a.length; j++) { // Iterate over the array a starting from the third element
                na[j - 2] = a[j]; // Copy the elements from a to na, excluding the first two
            }
            na[na.length - 1] = (a[0] + a[1]) / 2; // Append the average of the first two elements to na
            a = na; // Update the array a with the new array na
        }
        
        System.out.println(a[0]); // Print the single remaining element in the array a
    }
}
// <END-OF-CODE>
