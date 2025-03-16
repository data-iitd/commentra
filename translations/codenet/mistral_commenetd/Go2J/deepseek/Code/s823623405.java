import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of integers from the standard input
        int[] as = new int[n]; // Create an array of size n to store the input integers
        Map<Integer, Integer> ps = new HashMap<>(); // Create a map to store the prime factors and their powers

        // Read the input integers and calculate their prime factors
        for (int i = 0; i < n; i++) {
            as[i] = scanner.nextInt(); // Read an integer from the standard input

            Map<Integer, Integer> ns = primeFactorize(as[i]); // Calculate the prime factors and their powers of the current integer
            for (Map.Entry<Integer, Integer> entry : ns.entrySet()) { // Iterate through the map to update the powers of the prime factors
                int k = entry.getKey();
                int v = entry.getValue();
                ps.put(k, Math.max(ps.getOrDefault(k, 0), v)); // Update the power of the current prime factor if it's greater
            }
        }

        // Calculate the answer
        long x = 1; // Initialize a variable to store the product of prime factors
        for (Map.Entry<Integer, Integer> entry : ps.entrySet()) { // Iterate through the map to calculate the product of prime factors
            int k = entry.getKey();
            int v = entry.getValue();
            for (int i = 1; i <= v; i++) { // Calculate the power of the prime factor
                x = (x * k) % 1000000007; // Multiply the current product with the prime factor
            }
        }

        int ans = 0; // Initialize a variable to store the answer
        for (int i = 0; i < n; i++) { // Iterate through the array to calculate the answer
            ans = (ans + divide(x, as[i])) % 1000000007; // Calculate the difference between the current product and the current integer, and add it to the answer
        }

        System.out.println(ans); // Print the answer
    }

    public static Map<Integer, Integer> primeFactorize(int n) {
        // Calculate the prime factors and their powers of a given integer
        Map<Integer, Integer> res = new HashMap<>();
        for (int i = 2; i * i <= n; i++) { // Iterate through the possible prime factors
            while (n % i == 0) { // If the current number is divisible by the current prime factor
                n /= i; // Divide the current number by the prime factor
                res.put(i, res.getOrDefault(i, 0) + 1); // Increment the power of the prime factor
            }
        }
        if (n != 1) { // If the number is not equal to 1, it means that it has a prime factor greater than 1
            res.put(n, res.getOrDefault(n, 0) + 1); // Increment the power of the last prime factor
        }
        return res;
    }

    public static int max(int a, int b) {
        // Return the maximum of two integers
        return a > b ? a : b;
    }

    public static int divide(int a, int b) {
        // Return the quotient of a and b modulo 1000000007
        return (int) ((long) a * modInverse(b) % 1000000007);
    }

    public static int modInverse(int b) {
        // Calculate the modular multiplicative inverse of b modulo 1000000007
        return pow(b, 1000000005);
    }

    public static int pow(int n, int k) {
        // Calculate n raised to the power of k modulo 1000000007
        int res = 1;
        while (k > 0) {
            if (k % 2 == 1) {
                res = (int) ((long) res * n % 1000000007);
            }
            n = (int) ((long) n * n % 1000000007);
            k /= 2;
        }
        return res;
    }
}
