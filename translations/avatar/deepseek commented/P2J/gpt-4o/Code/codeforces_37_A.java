import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Read the number of elements
        int[] l = new int[n];  // Create an array to hold the elements
        
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();  // Read the list of elements
        }
        
        // Initialize variables
        int high = 1;
        int tower = n;
        int maximum = 1;

        // Sort the array
        Arrays.sort(l);

        // Loop through the sorted array
        for (int i = 1; i < n; i++) {
            if (l[i] == l[i - 1]) {  // Check if the current element is equal to the previous element
                tower--;  // Decrement the tower count
                high++;  // Increment the high count
            } else {
                if (high > maximum) {  // Check if the current high is greater than the maximum
                    maximum = high;  // Update the maximum
                }
                high = 1;  // Reset high to 1
            }
        }

        if (high > maximum) {  // Check if the final high is greater than the maximum
            maximum = high;  // Update the maximum
        }

        // Print the result
        System.out.println(maximum + " " + tower);
        
        scanner.close();
    }
}

// <END-OF-CODE>
