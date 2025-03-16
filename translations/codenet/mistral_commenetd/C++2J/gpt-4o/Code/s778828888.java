import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int n = scanner.nextInt(); // Read the first integer
        int m = scanner.nextInt(); // Read the second integer
        int x = scanner.nextInt(); // Read the third integer

        int[] a = new int[105]; // Declare and initialize an array a of size 105 with zeros

        for (int i = 0; i < m; ++i) { // Iterate through m times
            int temp = scanner.nextInt(); // Read an integer from the input
            a[temp] = 1; // Set the value of the array element at index temp to 1
        }

        int ansl = 0, ansr = 0; // Declare and initialize two integer variables: ansl and ansr

        for (int i = x; i <= n; ++i) { // Iterate through the range from x to n
            ansr += a[i]; // Add the value of the array element at index i to the variable ansr
        }

        for (int i = x; i >= 0; --i) { // Iterate through the range from x to 0
            ansl += a[i]; // Add the value of the array element at index i to the variable ansl
        }

        System.out.println(Math.min(ansl, ansr)); // Print the minimum value between ansl and ansr
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
