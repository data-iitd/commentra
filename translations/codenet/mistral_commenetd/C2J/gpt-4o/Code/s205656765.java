import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int X, A, B, C; // Declare variables X, A, B, C of type int
        int kosu = 0; // Initialize variable kosu to zero

        Scanner scanner = new Scanner(System.in);

        // Input values for A, B, C, and X from the user
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();
        X = scanner.nextInt();

        // Divide X by 50 and assign the quotient to X
        X = X / 50;

        // Three nested for loops to check if X can be represented as 10*i + 2*j + k
        for (int i = 0; i <= A; i++) { // Loop through all possible values of i from 0 to A
            for (int j = 0; j <= B; j++) { // Loop through all possible values of j from 0 to B
                for (int k = 0; k <= C; k++) { // Loop through all possible values of k from 0 to C
                    if (X == (10 * i) + (2 * j) + k) { // Check if X equals the sum of 10*i, 2*j, and k
                        kosu++; // If so, increment the counter kosu
                    }
                }
            }
        }

        // Print the result, which is the number of ways X can be represented as 10*i + 2*j + k
        System.out.println(kosu);

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
