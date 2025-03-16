import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input which represents the number of elements
        int n = scanner.nextInt();
        
        // Read the line of input and convert it to an array of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize the current level and counters
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;  // Start with -1 to account for the first turn increment
        
        // Loop until all elements have been processed
        while (counter < a.length) {
            counterTurns++;  // Increment the turn counter
            
            // Iterate through the array to find elements that can be processed
            for (int i = 0; i < a.length; i++) {
                // Check if the current element is not marked (-1) and is less than or equal to the current counter
                if (a[i] != -1 && a[i] <= counter) {
                    counter++;  // Increment the counter as we can process this element
                    a[i] = -1;  // Mark the element as processed by setting it to -1
                }
            }
            
            // Reverse the array to prepare for the next round of processing
            reverseArray(a);
        }
        
        // Print the total number of turns taken to process all elements
        System.out.println(counterTurns);
        
        // Close the scanner
        scanner.close();
    }
    
    // Method to reverse the array
    private static void reverseArray(int[] array) {
        int left = 0;
        int right = array.length - 1;
        while (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    }
}

// <END-OF-CODE>
