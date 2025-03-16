import java.util.Scanner;

public class CountOccurrences {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        System.out.print("Enter the number of elements: ");
        long n = scanner.nextLong(); // Read the number of elements from the standard input

        long[] a = new long[(int) n]; // Declare an array of size n to store the input numbers
        long[] count = new long[(int) n]; // Declare an array of size n to store the count of occurrences of each number

        System.out.println("Enter " + n + " numbers:");
        for (int i = 0; i < n; i++) { // Initialize the array a with input numbers
            a[i] = scanner.nextLong();
        }

        System.out.println("Initializing count array with zeros:");
        for (int i = 0; i < n; i++) { // Initialize all elements of the count array to zero
            count[i] = 0;
        }

        System.out.println("Counting occurrences:");
        for (int i = 0; i < n; i++) { // Iterate through the array a and increment the corresponding element in the count array
            count[(int) (a[i] - 1)]++;
        }

        System.out.println("Printing the contents of the count array:");
        for (int i = 0; i < n; i++) { // Print the contents of the count array to the standard output
            System.out.println(count[i]);
        }

        System.out.println("Program completed successfully.");
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
