import java.util.Scanner;

public class Main {
    // Function to print the binary representation of an integer x with a specified number of bits
    public static void binPrint(int x, int bits) {
        for (int i = bits - 1; i >= 0; i--) {
            System.out.print((x & (1 << i)) != 0 ? 1 : 0);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long a = scanner.nextLong();  // Read two unsigned integers from standard input
        long b = scanner.nextLong();

        binPrint((int)(a & b), 32);  // Print the binary AND of a and b
        binPrint((int)(a | b), 32);  // Print the binary OR of a and b
        binPrint((int)(a ^ b), 32);  // Print the binary XOR of a and b

        scanner.close();
    }
}

// <END-OF-CODE>
