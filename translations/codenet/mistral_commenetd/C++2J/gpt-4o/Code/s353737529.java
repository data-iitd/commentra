import java.util.Scanner;

public class Main {
    // Function to find the greatest common divisor of two numbers
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of digits in binary representation
        int n = scanner.nextInt();
        
        // Initialize an empty string 's' to store binary representation
        StringBuilder s = new StringBuilder();

        // Check if the number is zero and print '0' if it is
        if (n == 0) {
            System.out.println('0');
            return;
        }

        // Iterate through the number from the least significant bit to the most significant bit
        while (n != 0) {
            // If the number is even, add '0' to the binary representation
            if (n % 2 == 0) {
                s.append('0');
            } else {
                // If the number is odd, add '1' to the binary representation
                s.append('1');
            }

            // Update the number by subtracting the absolute value of the remainder when the number is divided by 2 and the remainder itself
            n -= Math.abs(n % 2);

            // Update the number by dividing it by -2
            n /= -2;
        }

        // Reverse the binary representation and print it
        s.reverse();
        System.out.println(s.toString());
    }
}

// <END-OF-CODE>
