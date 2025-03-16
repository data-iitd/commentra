public class BitwiseOperations {
    // Method to print the binary representation of an integer
    public static void binPrint(int x, int bits) {
        // Loop through each bit from the most significant to the least significant
        for (int i = bits - 1; i >= 0; i--) {
            // Print 1 if the ith bit is set, otherwise print 0
            System.out.print(x & (1 << i) != 0 ? 1 : 0);
        }
        // Print a newline after the binary representation
        System.out.println();
    }

    public static void main(String[] args) {
        // Declare two integers to hold user input
        int a, b;
        
        // Read two integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Print the binary representation of the bitwise AND of a and b
        binPrint(a & b, 32);
        
        // Print the binary representation of the bitwise OR of a and b
        binPrint(a | b, 32);
        
        // Print the binary representation of the bitwise XOR of a and b
        binPrint(a ^ b, 32);
        
        // Close the scanner
        scanner.close();
    }
}
