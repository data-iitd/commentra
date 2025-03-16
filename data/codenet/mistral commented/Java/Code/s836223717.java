
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new Scanner object to read input
        Scanner sc = new Scanner(System.in);

        // Read an integer `n` from the standard input stream
        int n = sc.nextInt();

        // Create an array `ryuka` of size `n + 1` to store the Fibonacci sequence
        long[] ryuka = new long[n + 1];

        // Initialize the first two elements of the array with the base values of the Fibonacci sequence
        ryuka[0] = 2;
        ryuka[1] = 1;

        // Use a for loop to calculate the remaining elements of the array by summing up the previous two elements
        for (int i = 2; i < n + 1; i++) {
            // Calculate the `i`-th Fibonacci number by summing up the previous two numbers
            ryuka[i] = ryuka[i - 1] + ryuka[i - 2];
        }

        // Print the `n`-th Fibonacci number, which is stored in the last element of the array
        System.out.println("The " + n + "-th Fibonacci number is: " + ryuka[n]);
    }
}