import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] io = new int[5];

        // Read five integers from the input and store them in the array 'io'
        for (int i = 0; i < 5; i++) {
            io[i] = scanner.nextInt();
        }

        // Outer loop to iterate over each element in the array 'io'
        for (int i = 0; i < 5; i++) {
            int max = io[i]; // Initialize 'max' with the current element
            int max_j = i;   // Store the index of the current element in 'max_j'

            // Inner loop to find the maximum element in the unsorted part of the array
            for (int j = i + 1; j < 5; j++) {
                if (max < io[j]) { // If the current maximum is less than the element at index 'j'
                    max = io[j]; // Update 'max' with the new maximum value
                    max_j = j;   // Update 'max_j' with the index of the new maximum value
                }
            }

            // Swap the current element with the maximum element found in the unsorted part
            int buf = io[i];
            io[i] = io[max_j];
            io[max_j] = buf;

            // Print the current element, with a space for all but the last element, and a newline for the last element
            if (i < 4) {
                System.out.print(io[i] + " ");
            } else {
                System.out.println(io[i]);
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
