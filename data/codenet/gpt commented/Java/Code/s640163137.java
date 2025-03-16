import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main (String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of elements and parse it to an integer
        int n = Integer.parseInt(br.readLine());
        
        // Initialize an array to hold the integers
        int[] a = new int[n];
        
        // Read the elements from the input, split by space, and store them in the array
        String[] elements = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(elements[i]); // Convert each element to an integer
        }
        
        // Initialize a counter for the number of swaps made during sorting
        int swapCount = 0; 
        
        // Selection sort algorithm to sort the array
        for (int i = 0; i < a.length; i++) {
            int mini = i; // Assume the minimum is the current index
            
            // Find the index of the minimum element in the unsorted portion of the array
            for (int j = i; j < a.length; j++) {
                if (a[j] < a[mini]) {
                    mini = j; // Update mini if a smaller element is found
                }
            }
            
            // If the found minimum is not the current index, swap the elements
            if (mini != i) {
                int v = a[mini]; // Store the minimum value
                a[mini] = a[i]; // Swap the minimum with the current element
                a[i] = v; // Place the stored minimum value in the current position
                
                swapCount++; // Increment the swap count
            }
        }
        
        // Prepare the output string with the sorted elements
        String ans = String.valueOf(a[0]); // Start with the first element
        for (int i = 1; i < a.length; i++) {
            ans += " " + a[i]; // Append each subsequent element
        }
        
        // Print the sorted array
        System.out.println(ans);
        // Print the total number of swaps made during sorting
        System.out.println(swapCount);
    }
}
