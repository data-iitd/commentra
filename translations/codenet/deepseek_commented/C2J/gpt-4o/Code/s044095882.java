import java.util.Scanner;  // Import the Scanner class for input

public class Main {  // Define the Main class
    public static void main(String[] args) {  // Define the main method
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        long n = scanner.nextLong();  // Read the value of n from the standard input
        long[] a = new long[(int) n];  // Declare an array `a` with size n
        long[] count = new long[(int) n];  // Declare an array `count` with size n

        for (long i = 1; i < n; i++) {  // Loop to read n-1 values into the array `a`
            a[(int) i] = scanner.nextLong();
        }

        for (long i = 0; i < n; i++) {  // Loop to initialize the `count` array to zero
            count[(int) i] = 0;
        }

        for (long i = 1; i < n; i++) {  // Loop to increment the `count` array based on the values in `a`
            count[(int) (a[(int) i] - 1)]++;
        }

        for (long i = 0; i < n; i++) {  // Loop to print the values in the `count` array
            System.out.println(count[(int) i]);
        }

        scanner.close();  // Close the scanner
    }  // End of main method
}  // End of Main class
// <END-OF-CODE>
