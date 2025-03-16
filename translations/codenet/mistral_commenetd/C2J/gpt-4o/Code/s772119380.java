import java.util.Scanner;

public class BubbleSort {
    // This is the main function where the program starts execution
    public static void main(String[] args) {
        // Declare an integer array 'a' of size 1000 and an integer variable 'n'
        int[] a = new int[1000];
        int n, d = 0; // Initialize a variable 'd' to keep track of the number of swaps made during sorting

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the size of the array from the user
        n = scanner.nextInt();

        // Read 'n' integers from the user and store them in the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read an integer and store it in the current index of the array 'a'
        }

        // Implement bubble sort algorithm to sort the array 'a' in ascending order
        for (int i = 0; i < n; i++) { // Iterate through each index of the array 'a'
            for (int j = n - 1; j >= i + 1; j--) { // Iterate through the array from the last index to the current index
                if (a[j] < a[j - 1]) { // Check if the current element is smaller than the previous element
                    int temp = a[j]; // Swap the elements if they are in the wrong order
                    a[j] = a[j - 1];
                    a[j - 1] = temp;
                    d++; // Increment the swap counter
                }
            }
        }

        // Print the sorted array 'a'
        System.out.print(a[0]); // Print the first element of the array
        for (int i = 1; i < n; i++) { // Iterate through the remaining elements of the array
            System.out.print(" " + a[i]); // Print each element followed by a space
        }
        System.out.println(); // Print a newline character at the end of the line

        // Print the number of swaps made during sorting
        System.out.println(d);

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
