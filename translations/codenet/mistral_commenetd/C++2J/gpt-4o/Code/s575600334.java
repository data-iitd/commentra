import java.util.Scanner;

public class BitwiseOperations {

    // Function to print binary representation of a number
    public static void binPrint(int x, int bits) {
        // Iterate through each bit starting from the last one
        for (int i = bits - 1; i >= 0; i--) {
            // Print the bit value based on the bitwise AND operation with the mask (1<<i)
            System.out.print((x & (1 << i)) != 0 ? 1 : 0);
        }
        // Print newline character after printing the binary number
        System.out.println();
    }

    public static void main(String[] args) {
        // Declare unsigned integer variables a and b
        Scanner scanner = new Scanner(System.in);
        int a, b;

        // Read integer values of a and b from the standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Print binary representation of bitwise AND of a and b
        binPrint(a & b, 32);

        // Print binary representation of bitwise OR of a and b
        binPrint(a | b, 32);

        // Print binary representation of bitwise XOR of a and b
        binPrint(a ^ b, 32);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
