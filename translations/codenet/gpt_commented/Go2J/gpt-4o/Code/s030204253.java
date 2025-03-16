import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from standard input
        int n = scanner.nextInt();
        
        // Initialize an array to hold the float numbers
        double[] a = new double[n];
        
        // Read n float numbers from standard input into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }
        
        // Perform a series of operations to reduce the array
        for (int i = 0; i + 1 < n; i++) {
            // Sort the array in ascending order
            Arrays.sort(a);
            
            // Create a new array to hold the modified values
            double[] na = new double[a.length - 2];
            
            // Append all elements from the third element onward to the new array
            for (int j = 2; j < a.length; j++) {
                na[j - 2] = a[j];
            }
            
            // Calculate the average of the first two elements and append it to the new array
            double average = (a[0] + a[1]) / 2;
            na[na.length - 1] = average;
            
            // Update the original array to be the new array
            a = na;
        }
        
        // Print the final remaining element in the array
        System.out.println(a[0]);
    }
}

// <END-OF-CODE>
