import java.util.Scanner;

public class Main {
    // Function declarations
    static void A() {}
    static void B() {}
    static void C() {}
    static void D() {}

    public static void main(String[] args) {
        // Call function B to execute its logic
        B();
    }

    static void B() {
        long x, sum; // Declare variables for input and sum
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextLong(); // Read input value x from the user
        int i; // Declare a counter variable
        sum = 100; // Initialize sum to 100

        // Loop until sum is less than x
        for (i = 0; sum < x; ++i) {
            // Increase sum by 1% of its current value
            sum += sum / 100;
        }

        // Output the number of iterations needed to exceed or meet x
        System.out.println(i);
        scanner.close();
    }
}

// <END-OF-CODE>
