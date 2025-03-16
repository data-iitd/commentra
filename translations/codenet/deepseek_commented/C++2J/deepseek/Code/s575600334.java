public class BitwiseOperations {
    // Function to print the binary representation of an integer x with a specified number of bits
    public static void binPrint(int x, int bits) {
        for (int i = bits - 1; i >= 0; i--) {
            System.out.print((x & (1 << i)) != 0 ? 1 : 0);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();  // Read the first integer from standard input
        int b = scanner.nextInt();  // Read the second integer from standard input

        binPrint(a & b, 32);  // Print the binary AND of a and b
        binPrint(a | b, 32);  // Print the binary OR of a and b
        binPrint(a ^ b, 32);  // Print the binary XOR of a and b
    }
}
