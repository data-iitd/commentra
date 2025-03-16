
import java.util.Scanner;

public class codeforces_583_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read a line of input, split it by spaces, and convert it to an array of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize the current level and counters
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;  // Start with -1 to account for the first turn increment
        
        // Loop until all elements have been processed
        while (counter < n) {
            counterTurns++;  // Increment the turn counter
            
            // Iterate through the array to find elements that can be processed
            for (int i = 0; i < n; i++) {
                // Check if the current element is not marked (-1) and is less than or equal to the current counter
                if (a[i]!= -1 && a[i] <= counter) {
                    counter++;  // Increment the counter as we can process this element
                    a[i] = -1;  // Mark the element as processed by setting it to -1
                }
            }
            
            // Reverse the array to prepare for the next round of processing
            reverseArray(a);
        }
        
        // Print the total number of turns taken to process all elements
        System.out.println(counterTurns);
    }
    
    // Method to reverse an array
    public static void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            
            left++;
            right--;
        }
    }
}

// Call the main function to execute the code
codeforces_583_B.main(null);

