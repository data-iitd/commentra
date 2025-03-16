
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer> md = new ArrayList<>(); // Static ArrayList to store some data

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a Scanner object to read input
        int n = in.nextInt(); // Read the number of elements
        int[] a = new int[n]; // Initialize array 'a' to store first set of values
        int[] b = new int[n]; // Initialize array 'b' to store second set of values
        int temp = 0; // Variable to temporarily store a value
        int q = 0; // Variable to store a value for comparison
        int w = 0; // Variable to store the maximum value of 'a'
        int e = 0; // Variable to store a value for comparison
        boolean f = false; // Boolean variable to determine the output

        // Loop through each element
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt(); // Read the value for array 'a'
            b[i] = in.nextInt(); // Read the value for array 'b'
            if (temp < a[i]) { // Check if the current 'a' value is greater than the stored 'temp' value
                if (q > b[i]) { // Check if the stored 'q' value is greater than the current 'b' value
                    f = true; // Set 'f' to true if the condition is met
                }
                q = b[i]; // Update 'q' with the current 'b' value
                temp = a[i]; // Update 'temp' with the current 'a' value
            }
            if (temp > a[i]) { // Check if the current 'a' value is less than the stored 'temp' value
                if (q < b[i]) { // Check if the stored 'q' value is less than the current 'b' value
                    f = true; // Set 'f' to true if the condition is met
                }
                q = b[i]; // Update 'q' with the current 'b' value
                temp = a[i]; // Update 'temp' with the current 'a' value
            }
            if (a[i] > w) { // Check if the current 'a' value is greater than the stored 'w' value
                w = a[i]; // Update 'w' with the current 'a' value
                if (b[i] < e) { // Check if the current 'b' value is less than the stored 'e' value
                    f = true; // Set 'f' to true if the condition is met
                }
                e = b[i]; // Update 'e' with the current 'b' value
            }
            if (a[i] < w) { // Check if the current 'a' value is less than the stored 'w' value
                if (b[i] > e) { // Check if the current 'b' value is greater than the stored 'e' value
                    f = true; // Set 'f' to true if the condition is met
                }
            }
        }

        // Determine and print the output based on the value of 'f'
        if (f == true) {
            System.out.println("Happy Alex"); // Print "Happy Alex" if 'f' is true
        } else {
            System.out.println("Poor Alex"); // Print "Poor Alex" if 'f' is false
        }
    }
}
