
import java.util.*; // For input and output operations
import java.io.*; // For standard input and output operations
import java.math.*; // To use the BigInteger class

public class s049366196{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Creates a BufferedReader to read input from standard input
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); // Creates a PrintWriter to write output to standard output

        int N = Integer.parseInt(br.readLine()); // Reads an integer N from standard input

        BigInteger ans = BigInteger.ONE; // Initializes the answer variable to 1
        for (int i = 2; i <= N; i++) { // Iterates from 2 to N
            if (isPrime(i)) { // Checks if the current number i is prime
                int NN = N;
                int cnt = 0; // Initializes a counter to count the power of the prime
                while (NN > 0) { // While loop to calculate the power of the prime in N
                    cnt += NN/i; // Adds the quotient of NN divided by i to cnt
                    NN /= i; // Divides NN by i
                }
                ans = ans.multiply(BigInteger.valueOf(cnt+1)); // Multiplies ans by cnt+1
            }
        }

        pw.println(ans.mod(BigInteger.valueOf(100000007))); // Prints the final answer modulo 100000007
        pw.close(); // Flushes and closes the PrintWriter
    }

    // Function to check if a number is prime
    public static boolean isPrime(int x) {
        for (int i = 2; i*i <= x; i++) // Iterates from 2 to the square root of x
            if (x % i == 0) return false; // Returns false if x is divisible by i
        return true; // Returns true if no divisors are found
    }
}

