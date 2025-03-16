import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables N and D of integer type
        // N and D should be positive integers less than or equal to 20
        int N, D;

        // Initialize variables N and D using Scanner class
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        D = scanner.nextInt();

        // Calculate the quotient of N by (D*2+1) and store it in variable ans
        int ans = N / (D * 2 + 1);

        // Calculate the remainder of N by (D*2+1) and store it in variable rem
        int rem = N % (D * 2 + 1);

        // Check if the remainder is zero or not
        if (rem != 0) {
            // If the remainder is not zero, increment the value of ans by 1
            ans = ans + 1;
        }

        // Print the value of ans using System.out.println
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
