import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of elements

        int[] a = new int[n]; // Allocate an array of size 'n'

        // Read 'n' integers and store them in the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt(); // Read an integer and store it in the 'i'-th position of the array 'a'
        }

        int ans = 0; // Initialize an integer variable 'ans' to store the answer
        boolean ok = true; // Initialize a boolean variable 'ok' to keep track of the loop condition

        // Main logic of the program starts here
        while (ok) {
            for (int i = 0; i < n; i++) { // Iterate through all the elements in the array 'a'
                if (a[i] % 2 == 1) { // Check if the 'i'-th element of the array 'a' is odd
                    System.out.println(ans); // If yes, print the answer and exit the program
                    return;
                } else { // If the 'i'-th element of the array 'a' is even, divide it by 2
                    a[i] /= 2;
                }
            }
            ans++; // Increment the answer by 1 for each iteration of the outer loop
            ok = false; // Set the loop condition to false to exit the loop if all elements in the array 'a' become even
        }

        // Print the final answer if all elements in the array 'a' become even
        System.out.println(ans);
    }
}
// <END-OF-CODE>
