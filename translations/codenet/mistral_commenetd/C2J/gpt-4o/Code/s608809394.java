import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int n = scanner.nextInt(); // Read an integer value from the standard input and store it in 'n'

        int[] a = new int[n]; // Declare an integer array 'a' of size 'n'

        for (int i = 0; i < n; i++) { // Iterate through each element of the array 'a'
            a[i] = scanner.nextInt(); // Read an integer value from the standard input and store it in the current element of array 'a'
        }

        int t = 0; // Initialize the variable 't' to zero

        for (int i = 0; i < n; i++) { // Iterate through each element of the array 'a'
            int s = 0; // Initialize the variable 's' to zero for summation

            for (int j = 1; j < n; j++) { // Iterate through all other elements of the array 'a' except the current element 'i'
                if (j <= i) { // If the current index 'j' is less than or equal to the current index 'i', then skip the iteration
                    continue;
                }

                int m = a[i] * a[j]; // Multiply the current element 'a[i]' with the next element 'a[j]' and store the result in 'm'

                s = s + m; // Add the product 'm' to the sum 's'
            }

            t = t + s; // Add the sum 's' to the total sum 't'
        }

        System.out.println(t); // Print the total sum 't' to the standard output

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
