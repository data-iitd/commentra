import java.util.Scanner;

public class Main {
    // Define the main function
    public static void main(String[] args) {
        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases
        int n = scanner.nextInt();

        // Read the array of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize variables
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;

        // Main loop
        while (counter < a.length) {
            // Increment turns counter
            counterTurns++;

            // Iterate through the array
            for (int i = 0; i < a.length; i++) {
                // If current index is valid and its value is less than or equal to current level
                if (a[i] != -1 && a[i] <= counter) {
                    // Increment counter and mark the index as visited
                    counter++;
                    a[i] = -1;
                }
            }

            // Reverse the array
            reverseArray(a);
        }

        // Print the result
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
