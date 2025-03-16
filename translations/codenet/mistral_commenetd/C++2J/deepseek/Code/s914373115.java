import java.util.Scanner;

// Function A definition goes here
void A(void);

// Function B definition goes here
void B(void);

// Function C definition goes here
void C(void);

// Function D definition goes here
void D(void);

public class Main {
    public static void main(String[] args) {
        // Call function B
        B();
    }

    // Function B definition
    // Reads a long long integer 'x' from the standard input
    public static void B(void) {
        Scanner scanner = new Scanner(System.in);
        long x, sum; // Declare variables 'x' and 'sum' of type long
        x = scanner.nextLong(); // Read a long long integer 'x' from the standard input
        int i = 0; // Declare variable 'i' of type int and initialize it to 0
        sum = 100; // Initialize 'sum' with the value 100

        // Calculate the number of iterations required to reach or exceed 'x'
        while (sum < x) {
            sum += sum / 100; // Update 'sum' by adding the result of dividing 'sum' by 100
            i++; // Increment 'i'
        }

        // Print the number of iterations required to reach or exceed 'x'
        System.out.println(i);
    }
}
