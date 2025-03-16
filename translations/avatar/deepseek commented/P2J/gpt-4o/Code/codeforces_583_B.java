import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from the user
        int n = scanner.nextInt();
        // Read the list of integers from the user input
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Initialize variables to track the current level and the number of turns
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;
        
        // Start a while loop that continues until all elements are processed
        while (counter < a.length) {
            // Increment the turn counter
            counterTurns++;
            // Iterate over the list 'a' to process each element
            for (int i = 0; i < a.length; i++) {
                // Check if the element is not -1 and is less than or equal to the current level
                if (a[i] != -1 && a[i] <= counter) {
                    // Increment the counter and mark the element as processed
                    counter++;
                    a[i] = -1;
                }
            }
            // Reverse the list 'a' to process elements in a different order in the next iteration
            reverseArray(a);
        }
        
        // Print the number of turns taken to process all elements
        System.out.println(counterTurns);
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
