import java.util.*;

public class Main {
    // Function to check if a number is prime
    static boolean is_prime(long x) {
        for (long i = 2; i * i <= x; i++) // Iterates from 2 to the square root of x
            if (x % i == 0) return false; // Returns false if x is divisible by i
        return true; // Returns true if no divisors are found
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Reads an integer N from standard input

        long ans = 1; // Initializes the answer variable to 1
        for (int i = 2; i <= N; i++) { // Iterates from 2 to N
            if (is_prime((long)i)) { // Checks if the current number i is prime
                int NN = N;
                int cnt = 0; // Initializes a counter to count the power of the prime
                while (NN > 0) { // While loop to calculate the power of the prime in N
                    cnt += NN / i; // Adds the quotient of NN divided by i to cnt
                    NN /= i; // Divides NN by i
                }
                ans *= cnt + 1; // Multiplies ans by cnt+1
                ans %= 1000000007; // Takes modulo 1000000007 to prevent overflow
            }
        }

        System.out.println(ans); // Prints the final answer
    }
}
