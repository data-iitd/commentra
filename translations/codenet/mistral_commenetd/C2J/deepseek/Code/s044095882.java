import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n; // Declare a variable to store the number of elements in the array

        System.out.print("Enter the number of elements: ");
        n = scanner.nextLong(); // Read the number of elements from the standard input and store it in n

        long[] a = new long[(int) n]; // Declare an array of size n to store the input numbers
        long[] count = new long[(int) n]; // Declare an array of size n to store the count of occurrences of each number

        System.out.printf("Enter %d numbers:\n", n);
        for (long i = 0; i < n; i++) { // Initialize the array a with input numbers
            a[(int) i] = scanner.nextLong();
        }

        System.out.println("Initializing count array with zeros:");
        for (long i = 0; i < n; i++) { // Initialize all elements of the count array to zero
            count[(int) i] = 0;
        }

        System.out.println("Counting occurrences:");
        for (long i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
            count[(int) (a[(int) i] - 1)]++;
        }

        System.out.println("Printing the contents of the count array:");
        for (long i = 0; i < n; i++) { // Print the contents of the count array to the standard output
            System.out.println(count[(int) i]);
        }

        System.out.println("Program completed successfully.");
        scanner.close(); // Close the scanner to free up resources
    }
}
