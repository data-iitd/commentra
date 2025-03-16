import java.util.Scanner; // Importing Scanner class for user input
import javax.swing.JOptionPane; // Importing JOptionPane for potential GUI dialogs (not used in this code)

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner s = new Scanner(System.in);
        
        // Reading the number of elements to be inputted
        int a = s.nextInt();
        
        // Initializing an array to hold the input integers
        int ar[] = new int[a];
        
        // Variables to hold the maximum and minimum differences
        int max = 0, min = 0;
        
        // Loop to read integers into the array
        for (int i = 0; i < ar.length; i++) {
            ar[i] = s.nextInt(); // Reading each integer into the array
        }
        
        // Loop to calculate and print the min and max differences for each element
        for (int i = 0; i < ar.length; i++) {
            // Calculating the maximum difference from the first and last elements
            max = Math.max(ar[i] - ar[0], ar[ar.length - 1] - ar[i]);
            
            // Calculating the minimum difference based on the position of the current element
            if (i == 0) {
                // If it's the first element, compare with the second element
                min = ar[i + 1] - ar[i];
            } else if (i == ar.length - 1) {
                // If it's the last element, compare with the second last element
                min = ar[i] - ar[i - 1];
            } else {
                // For middle elements, compare with both neighbors
                min = Math.min(ar[i] - ar[i - 1], ar[i + 1] - ar[i]);
            }
            
            // Printing the minimum and maximum differences for the current element
            System.out.println(min + " " + max);
        }
        
        // Closing the scanner to prevent resource leaks
        s.close();
    }
}
