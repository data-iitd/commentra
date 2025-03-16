import java.math.*;
import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
    @Override
    public void run() {
        try {
            // Create an instance of Solver and invoke the solve method
            new Solver().solve();
            System.exit(0); // Exit the program successfully
        } catch (Exception | Error e) {
            e.printStackTrace(); // Print any exceptions or errors that occur
            System.exit(1); // Exit the program with an error code
        }
    }

    public static void main(String[] args) {
        // Start the main program execution
        new Main().run();
    }
}

class Solver {
    final Helper hp; // Instance of Helper class for utility functions
    final int MAXN = 1000_006; // Maximum size for arrays
    final long MOD = (long) 1e9 + 7; // Modulus value for calculations

    final Timer timer; // Timer for managing execution time
    final TimerTask task; // Task to be executed by the timer

    Solver() {
        // Initialize Helper with MOD and MAXN
        hp = new Helper(MOD, MAXN);
        // Initialize input and output streams
        hp.initIO(System.in, System.out);

        // Set up a timer to terminate the program if it runs too long
        timer = new Timer();
        task = new TimerTask() {
            @Override
            public void run() {
                try {
                    hp.flush(); // Flush output before exiting
                    System.exit(0); // Exit the program
                } catch (Exception e) {
                    // Handle any exceptions silently
                }
            }
        };
        // Uncomment to schedule the timer task (currently commented out)
        // timer.schedule(task, 4700);
    }

    void solve() throws Exception {
        // Determine the number of test cases
        int tc = TESTCASES ? hp.nextInt() : 1;
        // Loop through each test case and solve it
        for (int tce = 1; tce <= tc; ++tce) solve(tce);
        timer.cancel(); // Cancel the timer after solving
        hp.flush(); // Flush output at the end
    }

    boolean TESTCASES = false; // Flag to indicate if multiple test cases are used

    void solve(int tc) throws Exception {
        // Declare variables for processing
        int i, j, k;

        // Read input values for the current test case
        int N = hp.nextInt(); // Number of elements
        long K = hp.nextLong(); // The K-th position to find
        int[] A = hp.getIntArray(N); // Read the array of integers

        // Initialize lists to store straight path and cycle
        ArrayList<Integer> straight = new ArrayList<>(), cycle = new ArrayList<>();
        boolean[] vis = new boolean[N]; // Visited array to track elements
        int curr = 0; // Current index to track the path

        // Traverse the array to find the cycle
        while (!vis[curr]) {
            vis[curr] = true; // Mark the current index as visited
            curr = A[curr] - 1; // Move to the next index
        }

        // Collect the straight path before the cycle starts
        int st = 0;
        while (st != curr) {
            straight.add(st); // Add to straight path
            st = A[st] - 1; // Move to the next index
        }

        // Collect the cycle elements
        cycle.add(curr); // Start the cycle with the current index
        curr = A[curr] - 1; // Move to the next index in the cycle
        while (curr != cycle.get(0)) {
            cycle.add(curr); // Add to cycle
            curr = A[curr] - 1; // Move to the next index
        }

        // Determine the output based on the value of K
        if (K < straight.size()) {
            hp.println(straight.get((int) K) + 1); // Output the K-th element in the straight path
        } else {
            K -= straight.size(); // Adjust K to account for the straight path
            hp.println(cycle.get((int) (K % cycle.size())) + 1); // Output the K-th element in the cycle
        }
    }
}

class Helper {
    final long MOD; // Modulus value for calculations
    final int MAXN; // Maximum size for arrays
    final Random rnd; // Random number generator

    public Helper(long mod, int maxn) {
        MOD = mod; // Initialize MOD
        MAXN = maxn; // Initialize MAXN
        rnd = new Random(); // Initialize random number generator
    }

    // Sieve of Eratosthenes for prime number generation
    public static int[] sieve;
    public static ArrayList<Integer> primes;

    public void setSieve() {
        primes = new ArrayList<>(); // List to store prime numbers
        sieve = new int[MAXN]; // Initialize sieve array
        int i, j;
        for (i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.add(i); // Add prime number to the list
                for (j = i; j < MAXN; j += i) {
                    sieve[j] = i; // Mark multiples of the prime
                }
            }
    }

    // Factorial array for combinatorial calculations
    public static long[] factorial;

    public void setFactorial() {
        factorial = new long[MAXN]; // Initialize factorial array
        factorial[0] = 1; // Base case for factorial
        for (int i = 1; i < MAXN; ++i) 
            factorial[i] = factorial[i - 1] * i % MOD; // Compute factorial with modulus
    }

    public long getFactorial(int n) {
        if (factorial == null) setFactorial(); // Ensure factorial array is initialized
        return factorial[n]; // Return the factorial of n
    }

    public long ncr(int n, int r) {
        if (r > n) return 0; // Return 0 if r is greater than n
        if (factorial == null) setFactorial(); // Ensure factorial array is initialized
        long numerator = factorial[n]; // Calculate numerator
        long denominator = factorial[r] * factorial[n - r] % MOD; // Calculate denominator
        return numerator * pow(denominator, MOD - 2, MOD) % MOD; // Return nCr using modular arithmetic
    }

    // Methods for reading arrays of different types
    public long[] getLongArray(int size) throws Exception {
        long[] ar = new long[size];
        for (int i = 0; i < size; ++i) ar[i] = nextLong(); // Read long values
        return ar;
    }

    public int[] getIntArray(int size) throws Exception {
        int[] ar = new int[size];
        for (int i = 0; i < size; ++i) ar[i] = nextInt(); // Read int values
        return ar;
    }

    public String[] getStringArray(int size) throws Exception {
        String[] ar = new String[size];
        for (int i = 0; i < size; ++i) ar[i] = next(); // Read string values
        return ar;
    }

    // Methods for joining elements into a string
    public String joinElements(long... ar) {
        StringBuilder sb = new StringBuilder();
        for (long itr : ar) sb.append(itr).append(" "); // Append long values
        return sb.toString().trim(); // Return joined string
    }

    public String joinElements(int... ar) {
        StringBuilder sb = new StringBuilder();
        for (int itr : ar) sb.append(itr).append(" "); // Append int values
        return sb.toString().trim(); // Return joined string
    }

    public String joinElements(String... ar) {
        StringBuilder sb = new StringBuilder();
        for (String itr : ar) sb.append(itr).append(" "); // Append string values
        return sb.toString().trim(); // Return joined string
    }

    public String joinElements(Object... ar) {
        StringBuilder sb = new StringBuilder();
        for (Object itr : ar) sb.append(itr).append(" "); // Append object values
        return sb.toString().trim(); // Return joined string
    }

    // Methods for calculating GCD
    public long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b); // Recursive GCD calculation
    }

    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b); // Recursive GCD calculation
    }

    // Methods for finding max and min values
    public long max(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.max(ret, itr); // Find maximum value
        return ret; // Return maximum value
    }

    public int max(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.max(ret, itr); // Find maximum value
        return ret; // Return maximum value
    }

    public long min(long... ar) {
        long ret = ar[0];
        for (long itr : ar) ret = Math.min(ret, itr); // Find minimum value
        return ret; // Return minimum value
    }

    public int min(int... ar) {
        int ret = ar[0];
        for (int itr : ar) ret = Math.min(ret, itr); // Find minimum value
        return ret; // Return minimum value
    }

    // Methods for summing elements
    public long sum(long... ar) {
        long sum = 0;
        for (long itr : ar) sum += itr; // Calculate sum of long values
        return sum; // Return sum
    }

    public long sum(int... ar) {
        long sum = 0;
        for (int itr : ar) sum += itr; // Calculate sum of int values
        return sum; // Return sum
    }

    // Methods for shuffling arrays
    public void shuffle(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length); // Generate random index
            if (r != i) {
                // Swap elements at indices i and r
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void shuffle(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = rnd.nextInt(ar.length); // Generate random index
            if (r != i) {
                // Swap elements at indices i and r
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    // Methods for reversing arrays
    public void reverse(int[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i; // Calculate reverse index
            if (r > i) {
                // Swap elements at indices i and r
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    public void reverse(long[] ar) {
        int r;
        for (int i = 0; i < ar.length; ++i) {
            r = ar.length - 1 - i; // Calculate reverse index
            if (r > i) {
                // Swap elements at indices i and r
                ar[i] ^= ar[r];
                ar[r] ^= ar[i];
                ar[i] ^= ar[r];
            }
        }
    }

    // Modular exponentiation
    public long pow(long base, long exp, long MOD) {
        base %= MOD; // Reduce base modulo MOD
        long ret = 1; // Initialize result
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD; // Multiply if exp is odd
            base = base * base % MOD; // Square the base
            exp >>= 1; // Divide exp by 2
        }
        return ret; // Return result
    }

    // Buffer size for fast input/output
    static final int BUFSIZE = 1 << 20;
    static byte[] buf; // Buffer for input
    static int index, total; // Index and total bytes read
    static InputStream in; // Input stream
    static BufferedWriter bw; // Buffered writer for output

    // Initialize input and output streams
    public void initIO(InputStream is, OutputStream os) {
        try {
            in = is; // Set input stream
            bw = new BufferedWriter(new OutputStreamWriter(os)); // Set output stream
            buf = new byte[BUFSIZE]; // Initialize buffer
        } catch (Exception e) {
            // Handle exceptions silently
        }
    }

    // Overloaded method to initialize IO with file names
    public void initIO(String inputFile, String outputFile) {
        try {
            in = new FileInputStream(inputFile); // Set input file
            bw = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(outputFile))); // Set output file
            buf = new byte[BUFSIZE]; // Initialize buffer
        } catch (Exception e) {
            // Handle exceptions silently
        }
    }

    // Method to read a byte from the input stream
    private int scan() throws Exception {
        if (index >= total) {
            index = 0; // Reset index
            total = in.read(buf); // Read bytes into buffer
            if (total <= 0)
                return -1; // Return -1 if no more bytes to read
        }
        return buf[index++]; // Return the next byte
    }

    // Method to read the next string from input
    public String next() throws Exception {
        int c;
        for (c = scan(); c <= 32; c = scan()) ; // Skip whitespace
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan())
            sb.append((char) c); // Append characters to string
        return sb.toString(); // Return the constructed string
    }

    // Method to read the next integer from input
    public int nextInt() throws Exception {
        int c, val = 0;
        for (c = scan(); c <= 32; c = scan()) ; // Skip whitespace
        boolean neg = c == '-'; // Check for negative sign
        if (c == '-' || c == '+')
            c = scan(); // Read next character
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15); // Construct integer value
        return neg ? -val : val; // Return value with sign
    }

    // Method to read the next long from input
    public long nextLong() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ; // Skip whitespace
        boolean neg = c == '-'; // Check for negative sign
        if (c == '-' || c == '+')
            c = scan(); // Read next character
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15); // Construct long value
        return neg ? -val : val; // Return value with sign
    }

    // Method to print an object to output
    public void print(Object a) throws Exception {
        bw.write(a.toString()); // Write object as string
    }

    // Method to print an object followed by a space
    public void printsp(Object a) throws Exception {
        print(a); // Print object
        print(" "); // Print space
    }

    // Method to print a newline
    public void println() throws Exception {
        bw.write("\n"); // Write newline
    }

    // Method to print an object followed by a newline
    public void println(Object a) throws Exception {
        print(a); // Print object
        println(); // Print newline
    }

    // Method to flush the output buffer
    public void flush() throws Exception {
        bw.flush(); // Flush the buffered writer
    }
}
