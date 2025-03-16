import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an array to hold 10 integers
        int[] s = new int[10];
        Scanner scanner = new Scanner(System.in);

        // Input 10 integers from the user
        for (int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt();
        }

        // Sort the array of integers in ascending order
        Arrays.sort(s);

        // Print the three largest integers from the sorted array
        for (int i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
