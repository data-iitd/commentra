
import java.util.Scanner;

public class s555338838{
    public static void main(String[] args) {
        // Declare variables
        int key, i, j, len, a[];
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read the length of the array
        len = scanner.nextInt();
        
        // Create an array of length len
        a = new int[len];
        
        // Read the elements of the array
        for(i = 0; i < len; i++) 
            a[i] = scanner.nextInt();

        // Perform insertion sort
        for(j = 1; j < len; j++) {
            // Print the current state of the array
            for(i = 0; i < len; i++) 
                System.out.print(i!= 0? " " + a[i] : a[i]);
            System.out.println(); // Move to the next line after printing the array
            
            // Store the current element to be positioned
            key = a[j];
            
            // Shift elements of the sorted segment to the right
            for(i = j - 1; i >= 0 && a[i] > key; i--) 
                a[i + 1] = a[i];
            
            // Place the key in its correct position
            a[i + 1] = key;
        }

        // Print the sorted array
        for(i = 0; i < len; i++) 
            System.out.print(i!= 0? " " + a[i] : a[i]);
        System.out.println(); // Move to the next line after printing the sorted array
        
        // Close the Scanner object
        scanner.close();
    }
}
