// Import necessary packages
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner for input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer 'n' from the standard input
        int n = scanner.nextInt();
        
        // Create an array 'a' of 'n' float values
        double[] a = new double[n];
        
        // Read 'n' float values from the standard input and assign them to the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextDouble();
        }
        
        // Sort the array 'a'
        Arrays.sort(a);
        
        // Initialize an empty array list 'na' to store the new values
        double[] na = new double[0];
        
        // Iterate through the array 'a' starting from index 2 and collect elements into 'na'
        for (int j = 2; j < a.length; j++) {
            na = Arrays.copyOf(na, na.length + 1);
            na[na.length - 1] = a[j];
        }
        
        // Calculate the average of the first two elements of the original array 'a'
        double average = (a[0] + a[1]) / 2;
        
        // Create a new array to hold the final values
        double[] finalArray = new double[na.length + 1];
        System.arraycopy(na, 0, finalArray, 0, na.length);
        finalArray[finalArray.length - 1] = average;
        
        // Print the first element of the sorted array 'finalArray'
        System.out.println(finalArray[0]);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
