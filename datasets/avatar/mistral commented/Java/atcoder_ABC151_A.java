
import java.io.BufferedReader; // Import BufferedReader class for reading input from standard input
import java.io.IOException; // Import IOException for handling input/output errors
import java.io.InputStreamReader; // Import InputStreamReader class for reading input from standard input

public class Main {
    public static void main(String[] args) throws IOException { // Main method to start the program
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in), 1); // Create a new BufferedReader object to read input
        String s; // Declare a String variable to store a line of input
        String sl[]; // Declare a String array variable to store each word in a line of input

        // Read a line of input and print the ASCII value of its first character incremented by 1
        s = r.readLine();
        System.out.printf("%c", s.charAt(0) + 1);

        r.close(); // Close the BufferedReader object to free up system resources
    }
}

class RemRing { // Define a new class named RemRing
    long module; // Declare a long variable named module to store the ring modulus

    public RemRing(long module) { // Constructor to initialize the module variable
        this.module = module;
    }

    public long sum(long a, long b) { // Method to compute the sum of two numbers modulo the module
        return (a + b + module) % module;
    }

    public long sub(long a, long b) { // Method to compute the difference of two numbers modulo the module
        return (a - b + module) % module;
    }

    public long prod(long a, long b) { // Method to compute the product of two numbers modulo the module
        return (a * b) % module;
    }

    public long div(long a, long b) { // Method to compute the quotient and remainder of two numbers modulo the module
        long quotient = a * inv(b); // Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
        return quotient % module; // Return the quotient modulo the module
    }

    public long inv(long a) { // Method to compute the multiplicative inverse of a number modulo the module
        long b = module; // Initialize b as the module
        long u = 1; // Initialize u as 1
        long v = 0; // Initialize v as 0

        // Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
        while (b > 0) {
            long t = a / b; // Compute the quotient of a divided by b
            long z = a; // Store a temporarily
            a = b; // Update a with the value of b
            b = z % module; // Update b with the remainder of z modulo the module
            long temp = u; // Store u temporarily
            u = v; // Update u with the value of v
            v = temp - t * v; // Update v as (u - t * v) % module
        }

        // If the result is negative, add the module to make it positive
        if (u < 0) u += module;

        return u; // Return the multiplicative inverse of a
    }
}