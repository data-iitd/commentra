import java.util.Scanner;

public class Main {
    // Method to calculate the greatest common divisor (GCD) using recursion
    public static long gcd(long a, long b) {
        if (b == 0) {
            return a; // Base case: if b is 0, return a
        } else {
            return gcd(b, a % b); // Recursive case
        }
    }

    // Method to calculate the least common multiple (LCM) using GCD
    public static long lcm(long a, long b) {
        return a * b / gcd(a, b); // LCM formula
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n; // Number of participants
        long k; // Points required to win
        long q; // Number of questions
        long[] a = new long[100001]; // Array to store the questions
        long[] point = new long[100001]; // Array to track points of each participant

        // Read input values for n, k, and q
        n = scanner.nextLong();
        k = scanner.nextLong();
        q = scanner.nextLong();

        // Process each question and update points for the corresponding participant
        for (long i = 0; i < q; i++) {
            a[(int) i] = scanner.nextLong(); // Read the participant number for the question
            point[(int) (a[(int) i] - 1)]++; // Increment the point for the participant who answered
        }

        // Determine if each participant has enough points to win
        for (long i = 0; i < n; i++) {
            if (k - (q - point[(int) i]) > 0) { // Check if the participant has enough points
                System.out.println("Yes"); // Participant can win
            } else {
                System.out.println("No"); // Participant cannot win
            }
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
