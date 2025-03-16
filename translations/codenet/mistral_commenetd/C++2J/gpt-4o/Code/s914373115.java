import java.util.Scanner;

public class Main {
    // Function A definition goes here
    static void A() {
        // Implementation for function A
    }

    // Function B definition goes here
    static void B() {
        // Implementation for function B
        Scanner scanner = new Scanner(System.in);
        long x, sum; // Declare variables 'x' and 'sum' of type long
        x = scanner.nextLong(); // Read a long integer 'x' from the standard input
        int i; // Declare variable 'i' of type int
        sum = 100; // Initialize 'sum' with the value 100

        // Calculate the number of iterations required to reach or exceed 'x'
        for (i = 0; sum < x; ++i) {
            sum += sum / 100; // Update 'sum' by adding the result of dividing 'sum' by 100
        }

        // Print the number of iterations required to reach or exceed 'x'
        System.out.println(i);
        scanner.close(); // Close the scanner
    }

    // Function C definition goes here
    static void C() {
        // Implementation for function C
    }

    // Function D definition goes here
    static void D() {
        // Implementation for function D
    }

    public static void main(String[] args) {
        // Call function B
        B();
    }
}

// <END-OF-CODE>
