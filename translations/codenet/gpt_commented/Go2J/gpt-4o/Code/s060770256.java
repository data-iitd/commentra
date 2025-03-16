import java.util.Scanner;

public class Main {
    // solution calculates the product of (n-2) and (m-2) with adjustments for negative values.
    public static int solution(int n, int m) {
        // Decrease n and m by 2 to adjust for some offset
        n = n - 2;
        m = m - 2;

        // If the adjusted n is negative, set it to 1
        if (n < 0) {
            n = 1;
        }

        // If the adjusted m is negative, set it to 1
        if (m < 0) {
            m = 1;
        }

        // Return the product of the adjusted n and m
        return n * m;
    }

    public static void main(String[] args) {
        // Declare variables to hold input values for n and m
        Scanner scanner = new Scanner(System.in);
        int n, m;

        // Read input values for n and m from the standard input
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Call the solution function and print the result
        System.out.println(solution(n, m));
        
        scanner.close();
    }
}

// <END-OF-CODE>
