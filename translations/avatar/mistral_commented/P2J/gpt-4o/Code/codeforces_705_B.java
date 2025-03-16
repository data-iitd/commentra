import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases from the input
        int n = scanner.nextInt();

        // Initialize an array to store the given numbers
        int[] w = new int[n];

        // Read the given numbers and store them in the array
        for (int i = 0; i < n; i++) {
            w[i] = scanner.nextInt();
        }

        // Initialize a variable 'c' with a value of 2
        int c = 2;

        // Iterate through each number in the array 'w'
        for (int number : w) {
            // If the number is equal to 1, print the current value of 'c'
            if (number == 1) {
                System.out.println(c);
            }
            // If the number is even, toggle the value of 'c'
            else if (number % 2 == 0) {
                c = 3 - c;
                System.out.println(c);
            }
            // If the number is odd, print the current value of 'c'
            else {
                System.out.println(c);
            }
        }

        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
