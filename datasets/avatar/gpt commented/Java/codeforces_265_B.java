import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scn = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = scn.nextInt(); 
        
        // Initialize an array to hold the input integers
        int[] arr = new int[n]; 
        
        // Populate the array with integers from user input
        for (int i = 0; i < arr.length; i++) { 
            arr[i] = scn.nextInt(); 
        } 
        
        // Initialize the answer with the first element of the array plus one
        int ans = arr[0] + 1; 
        
        // Calculate the total distance based on the differences between consecutive elements
        for (int i = 1; i < arr.length; i++) { 
            // Add the absolute difference between the current and previous element, plus 2
            ans += Math.abs(arr[i] - arr[i - 1]) + 2; 
        } 
        
        // Output the final calculated answer
        System.out.println(ans); 
    } 
}
