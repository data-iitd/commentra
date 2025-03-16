import java.util.Scanner;

public class Main {

    // Solve function takes three integers a, b, and c as input and returns an integer.
    public static int solve(int a, int b, int c) {
        int temp_ = 0;
        // Check if c is equal to the sum of a and b
        if (c == a + b) {
            temp_ = b + c;
        } else if (c - 1 > a + b) { // Check if c-1 is greater than the sum of a and b
            int temp = (c - 1) - (a + b);
            temp_ = b + c - temp; // Calculate temp_ based on the difference
        } else { // If neither condition is met
            temp_ = b + c;
        }
        return temp_;
    }

    // Main function reads three integers from standard input, calls the solve function with these integers, and prints the result.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        
        int ans = solve(a, b, c);
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
