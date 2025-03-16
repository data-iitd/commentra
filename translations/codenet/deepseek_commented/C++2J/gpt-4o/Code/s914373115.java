import java.util.Scanner;

public class Main {
    
    // Function A is not defined in the provided code.
    public static void A() {
        // Function implementation here (if needed)
    }

    // Function B is defined to take input and calculate the number of iterations.
    public static void B() {
        Scanner scanner = new Scanner(System.in);
        long x, sum;
        x = scanner.nextLong();
        int i = 0; // Initialize i to 0
        sum = 100; // Initialize sum to 100
        while (sum < x) {
            sum += sum / 100; // Increment sum by 1%
            i++; // Increment the iteration count
        }
        System.out.println(i); // Output the number of iterations
        scanner.close();
    }

    // Function C is not defined in the provided code.
    public static void C() {
        // Function implementation here (if needed)
    }

    // Function D is not defined in the provided code.
    public static void D() {
        // Function implementation here (if needed)
    }

    // Main function calls the B function.
    public static void main(String[] args) {
        B();
    }
}

// <END-OF-CODE>
