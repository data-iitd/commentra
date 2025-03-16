import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Take the number of elements in the list as input
        int n = scanner.nextInt();
        
        // Initialize an array to store the input elements
        int[] l = new int[n];
        
        // Read the list elements from the standard input
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Initialize variables 'high' and 'tower' with initial values
        int high = 1;
        int tower = n;
        int maximum = 1; // Initialize maximum to 1
        
        // Iterate through the list starting from the second element
        for (int i = 1; i < n; i++) {
            // If the current element is same as the previous one, decrement 'tower' and increment 'high'
            if (l[i] == l[i - 1]) {
                tower--;
                high++;
            } else {
                // If the current element is different, check if 'high' is greater than the current maximum and update it if true
                if (high > maximum) {
                    maximum = high;
                }
                high = 1; // Reset high for the new element
            }
        }
        
        // Check if the last 'high' value is greater than the current maximum and update it if true
        if (high > maximum) {
            maximum = high;
        }
        
        // Print the final result
        System.out.println(maximum + " " + tower);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
