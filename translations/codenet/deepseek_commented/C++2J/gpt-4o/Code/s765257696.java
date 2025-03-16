import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Comment 2: Initializes the scanner for input

        int n = scanner.nextInt(); // Comment 3: Reads the size of the array p from standard input

        int[] p = new int[n]; // Comment 4: Initializes the array p with n integers
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt(); // Populates the array p with n integers from standard input
        }

        int ans = 0; // Comment 5: Initializes the variable ans to 0

        for (int i = 0; i < n - 2; i++) { // Comment 6: Loops through the array p
            if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) ans++; // Comment 7: Checks for a peak and increments ans
            if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) ans++; // Comment 8: Checks for a valley and increments ans
        }

        System.out.println(ans); // Comment 9: Prints the final value of ans to standard output
        scanner.close(); // Closes the scanner
    } // Comment 10: Ends the program
} // <END-OF-CODE>
