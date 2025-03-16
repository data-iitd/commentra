import java.io.*;
import java.util.*;

class Main {
    // Constants for large values and modulo operations
    final static long INF = Long.MAX_VALUE / 2;
    final static int MOD = 1_000_000_007;
    final static int SIZE = 1_000_000;

    // Arrays for factorials and their inverses
    long[] fac = new long[SIZE];
    long[] inv = new long[SIZE];
    long[] finv = new long[SIZE];
    FastScanner sc = new FastScanner(); // Fast input scanner

    public static void main(String[] args) {
        new Main().solve(); // Start the solution process
    }

    void solve() {
        // Read the number of digits (n) and the number of constraints (m)
        int n = sc.nextInt();
        int m = sc.nextInt();
        Map<Integer, Integer> map = new HashMap<>(); // Map to store digit constraints

        // Read constraints and populate the map
        for (int i = 0; i < m; i++) {
            int s = sc.nextInt(); // Position of the digit
            int c = sc.nextInt(); // Value of the digit
            // Check for conflicting constraints
            if (map.get(s) != null && map.get(s) != c) {
                System.out.println(-1); // Output -1 if there's a conflict
                System.exit(0); // Exit the program
            }
            map.put(s, c); // Store the constraint
        }

        // Attempt to find a valid number based on constraints
        for (int i = 0; i < 1000; i++) {
            String s = "" + i; // Convert the number to a string
            boolean flag = true; // Flag to check if the current number is valid
            if (s.length() < n) continue; // Skip if the number has fewer digits than n
            for (int j = 0; j < n; j++) {
                // Check if the current digit meets the constraints
                if ((map.get(j + 1) != null && map.get(j + 1) != Character.getNumericValue(s.charAt(j))) || 
                    (map.get(j + 1) == null && Character.getNumericValue(s.charAt(j)) != 0)) {
                    // Special case for the first digit being 1
                    if (map.get(j + 1) == null && j == 0 && Character.getNumericValue(s.charAt(j)) == 1) {
                        continue;
                    }
                    flag = false; // Mark as invalid
                    break; // Exit the loop
                }
            }
            // If valid and the length matches, print the result
            if (flag && s.length() == n) {
                System.out.println(s);
                System.exit(0); // Exit after finding a valid number
            }
        }

        // If no valid number is found, output -1
        System.out.println(-1);
    }

    // Method to calculate the greatest common divisor (GCD)
    long gcd(long a, long b) {
        if (b == 0) {
            return a; // Base case
        }
        return gcd(b, a % b); // Recursive call
    }

    // Method to calculate the least common multiple (LCM)
    long lcm(long a, long b) {
        return a * b / gcd(a, b); // LCM formula
    }

    // Method to find the modular inverse of a number
    long inv(long a) {
        return pow(a, MOD - 2); // Using Fermat's little theorem
    }

    // Method to calculate a^r mod MOD
    long pow(long a, long r) {
        long sum = 1; // Initialize result
        while (r > 0) {
            if ((r & 1) == 1) { // If r is odd
                sum *= a;
                sum %= MOD; // Apply modulo
            }
            a *= a; // Square the base
            a %= MOD; // Apply modulo
            r >>= 1; // Divide r by 2
        }
        return sum; // Return the result
    }

    // Method to calculate n! mod MOD
    long modFact(long n) {
        if (n == 0) {
            return 1; // Base case
        }
        return n * modFact(n - 1) % MOD; // Recursive call with modulo
    }

    // Method to calculate n!
    long fact(long n) {
        if (n == 0) {
            return 1; // Base case
        }
        return n * fact(n - 1); // Recursive call
    }

    // Method to initialize factorials and their inverses
    void initCOMB() {
        fac[0] = fac[1] = 1; // Base cases
        inv[1] = 1;
        finv[0] = finv[1] = 1;
        for (int i = 2; i < SIZE; i++) {
            fac[i] = fac[i - 1] * i % MOD; // Calculate factorial
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD; // Calculate inverse
            finv[i] = finv[i - 1] * inv[i] % MOD; // Calculate inverse factorial
        }
    }

    // Method to calculate nCr (combinations)
    long modComb(int n, int r) {
        if (n < r || n < 0 || r < 0) return 0; // Invalid case
        return fac[n] * finv[r] % MOD * finv[n - r] % MOD; // Combination formula
    }

    // Method to calculate nCr without modulo
    long comb(long n, long r) {
        long num = 1; // Initialize result
        for (long i = 1; i <= r; i++) {
            num = num * (n - i + 1) / i; // Combination calculation
        }
        return num; // Return the result
    }

    // Method to check if a number is prime
    boolean isPrime(long a) {
        if (a <= 1) return false; // Numbers <= 1 are not prime
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) return false; // Found a divisor
        }
        return true; // No divisors found, it's prime
    }

    // Method to find the next permutation of a string
    String nextPermutation(String s) {
        ArrayList<Character> list = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) list.add(s.charAt(i)); // Convert string to list

        int pivotPos = -1;
        char pivot = 0;
        // Find the pivot point
        for (int i = list.size() - 2; i >= 0; i--) {
            if (list.get(i) < list.get(i + 1)) {
                pivotPos = i; // Found pivot
                pivot = list.get(i);
                break;
            }
        }

        // If no pivot found, return null (last permutation)
        if (pivotPos == -1 && pivot == 0) return null;

        int L = pivotPos + 1;
        int R = list.size() - 1;
        int minPos = -1;
        char min = Character.MAX_VALUE;
        // Find the smallest element greater than the pivot
        for (int i = R; i >= L; i--) {
            if (pivot < list.get(i)) {
                if (list.get(i) < min) {
                    min = list.get(i);
                    minPos = i; // Update min position
                }
            }
        }

        // Swap pivot with the smallest element found
        Collections.swap(list, pivotPos, minPos);
        Collections.sort(list.subList(L, R + 1)); // Sort the suffix

        // Build the next permutation string
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) sb.append(list.get(i));

        return sb.toString(); // Return the next permutation
    }

    // Method to find the next permutation of an array
    boolean nextPermutation(long[] a) {
        for (int i = a.length - 1; i > 0; i--) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1); // Find the swap index
                long temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp; // Swap elements
                Arrays.sort(a, i, a.length); // Sort the suffix
                return true; // Next permutation found
            }
        }
        return false; // No next permutation
    }

    // Helper method to find the index for swapping in next permutation
    int find(long dest, long[] a, int s, int e) {
        if (s == e) {
            return s; // Base case
        }
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e); // Binary search
    }

    // Method for Gaussian elimination to solve linear equations
    void elimination(int[][] a, int[] b) {
        int n = a.length; // Number of equations
        double f; // Factor for elimination
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                f = -a[i][k] / a[k][k]; // Calculate factor
                for (int j = k + 1; j < n; j++) {
                    a[i][j] += f * a[k][j]; // Eliminate variable
                }
                b[i] += f * b[k]; // Update the constant terms
            }
            // Back substitution
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i + 1; j < n; j++) {
                    b[i] -= a[i][j] * b[j]; // Update constant term
                }
                b[i] = b[i] / a[i][i]; // Solve for variable
            }
        }
    }
}

// Class to represent a pair of long integers
class Pair implements Comparable<Pair> {
    long a, b; // Pair values
    public Pair(long i, long j) {
        a = i;
        b = j; // Initialize pair
    }

    @Override
    public int compareTo(Pair p) {
        if (this.b < p.b) return -1; // Compare based on second value
        else if (this.b > p.b) return 1;
        else return 0; // Equal case
    }
}

// Fast input scanner class
class FastScanner {
    private final InputStream in = System.in; // Input stream
    private final byte[] buffer = new byte[1024]; // Buffer for input
    private int ptr = 0; // Pointer for buffer
    private int buflen = 0; // Length of buffer

    // Check if there is a next byte available
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true; // Bytes available
        } else {
            ptr = 0; // Reset pointer
            try {
                buflen = in.read(buffer); // Read new bytes
            } catch (IOException e) {
                e.printStackTrace(); // Handle exceptions
            }
            if (buflen <= 0) {
                return false; // No bytes available
            }
        }
        return true; // Bytes available
    }

    // Read the next byte
    private int readByte() {
        if (hasNextByte()) return buffer[ptr++]; // Return the next byte
        else return -1; // No more bytes
    }

    // Check if a character is printable
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126; // ASCII printable range
    }

    // Check if there is a next token
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; // Skip non-printable characters
        return hasNextByte(); // Check again
    }

    // Read the next token as a string
    public String next() {
        if (!hasNext()) throw new NoSuchElementException(); // No more tokens
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b); // Append printable characters
            b = readByte(); // Read next byte
        }
        return sb.toString(); // Return the string
    }

    // Read the next token as a long
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException(); // No more tokens
        long n = 0; // Initialize number
        boolean minus = false; // Flag for negative numbers
        int b = readByte();
        if (b == '-') {
            minus = true; // Set negative flag
            b = readByte(); // Read next byte
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException(); // Invalid number format
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10; // Shift left
                n += b - '0'; // Add digit
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n; // Return the number with sign
            } else {
                throw new NumberFormatException(); // Invalid number format
            }
            b = readByte(); // Read next byte
        }
    }

    // Read the next token as an integer
    public int nextInt() {
        long nl = nextLong(); // Read as long first
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException(); // Check bounds
        return (int) nl; // Cast to int
    }

    // Read the next token as a double
    public double nextDouble() {
        return Double.parseDouble(next()); // Parse as double
    }
}
