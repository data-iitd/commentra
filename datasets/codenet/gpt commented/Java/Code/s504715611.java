import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Random;
import java.util.Scanner;

// Class to implement Union-Find data structure
class UnionFind {
    int Parent[];

    // Constructor to initialize the Union-Find structure with -1
    UnionFind(int n) {
        Parent = new int[n];
        Arrays.fill(Parent, -1); // All nodes are initially their own parent
    }

    // Find the root of the tree containing A
    int root(int A) {
        if (Parent[A] < 0) return A; // If A is a root, return A
        return Parent[A] = root(Parent[A]); // Path compression
    }

    // Get the size of the tree that includes A
    int size(int A) {
        return -Parent[root(A)]; // Size is stored as a negative value
    }

    // Connect two elements A and B
    boolean connect(int A, int B) {
        A = root(A); // Find root of A
        B = root(B); // Find root of B
        if (A == B) return false; // Already connected

        // Union by size: attach smaller tree under larger tree
        if (size(A) < size(B)) {
            int C = 0; C = B; B = A; A = C; // Swap A and B
        }
        Parent[A] += Parent[B]; // Update size of A
        Parent[B] = A; // Make A the parent of B
        return true; // Successfully connected
    }
}

public class Main {
    // Initialize scanners and constants
    static FastScanner scan = new FastScanner();
    static Scanner scanner = new Scanner(System.in);
    static Random rand = new Random();
    static long mod = 1000000007; // Modulus for calculations
    static double eps = 1.0E-14; // Epsilon for floating-point comparisons
    static int big = Integer.MAX_VALUE; // Maximum integer value
    static double PI = 3.14159265358979323846262338327950288; // Value of PI

    // Calculate the modular least common multiple
    static long modlcm(long a, long b) {
        return a * b * modint(gcd(a, b), mod);
    }

    // Calculate the greatest common divisor
    static long gcd(long a, long b) {
        return b > 0 ? gcd(b, a % b) : a;
    }

    // Calculate the least common multiple
    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    // Return the maximum of two integers
    static int max(int a, int b) {
        return a > b ? a : b;
    }

    // Return the minimum of two integers
    static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Return the maximum of two long integers
    static long lmax(long a, long b) {
        return Math.max(a, b);
    }

    // Return the minimum of two long integers
    static long lmin(long a, long b) {
        return Math.min(a, b);
    }

    // Calculate factorial of a number
    static long factorial(int i) {
        return i == 1 ? 1 : i * factorial(i - 1);
    }

    public static void main(String[] args) throws IOException {
        // Read a string and check specific character conditions
        String str = scan.next();
        System.out.println(str.charAt(2) == str.charAt(3) && str.charAt(4) == str.charAt(5) ? "Yes" : "No");
    }

    // Find the lower bound index of a key in a sorted array
    static int lower_bound(int a[], int key) {
        int right = a.length;
        int left = 0;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (a[mid] < key) {
                left = mid; // Move left pointer
            } else {
                right = mid; // Move right pointer
            }
        }
        return left; // Return lower bound index
    }

    // Find the upper bound index of a key in a sorted array
    static int upper_bound(int a[], int key) {
        int right = a.length;
        int left = 0;
        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (a[mid] <= key) {
                left = mid; // Move left pointer
            } else {
                right = mid; // Move right pointer
            }
        }
        return left; // Return upper bound index
    }

    // Check if a number is prime
    static boolean isPrime(long n) {
        if (n == 2) return true; // 2 is prime
        if (n < 2 || n % 2 == 0) return false; // Exclude even numbers
        double d = Math.sqrt(n);
        for (int i = 3; i <= d; i += 2) if (n % i == 0) { return false; } // Check for factors
        return true; // Number is prime
    }

    // Perform integer division rounding up
    static int upper_division(int a, int b) {
        if (a % b == 0) {
            return a / b; // Exact division
        } else {
            return a / b + 1; // Round up
        }
    }

    // Perform long integer division rounding up
    static long lupper_division(long a, long b) {
        if (a % b == 0) {
            return a / b; // Exact division
        } else {
            return a / b + 1; // Round up
        }
    }

    // Set an array of integers from input
    static int[] setArray(int a) {
        int b[] = new int[a];
        for (int i = 0; i < a; i++) {
            b[i] = scan.nextInt(); // Read integers into array
        }
        return b; // Return the populated array
    }

    // Set an array of long integers from input
    static long[] lsetArray(int a) {
        long b[] = new long[a];
        for (int i = 0; i < a; i++) {
            b[i] = scan.nextLong(); // Read long integers into array
        }
        return b; // Return the populated array
    }

    // Reverse a string
    static String reverse(String str) {
        char ch[] = new char[str.length()];
        char chch[] = str.toCharArray();
        int a = str.length();
        for (int i = 0; i < upper_division(a, 2); i++) {
            ch[i] = chch[ch.length - i - 1]; // Swap characters
            ch[ch.length - 1 - i] = chch[i];
        }
        return String.valueOf(ch); // Return the reversed string
    }

    // Print an array of integers
    public static void printArray(int[] que) {
        for (int i = 0; i < que.length - 1; i++) {
            System.out.print(que[i] + " "); // Print elements with space
        }
        System.out.println(que[que.length - 1]); // Print last element
    }

    // Sort a 2D array of integers based on the first column
    public static int[][] doublesort(int[][] a) {
        Arrays.sort(a, (x, y) -> Integer.compare(x[0], y[0])); // Sort using comparator
        return a; // Return sorted array
    }

    // Sort a 2D array of long integers based on the first column
    public static long[][] ldoublesort(long[][] a) {
        Arrays.sort(a, (x, y) -> Long.compare(x[0], y[0])); // Sort using comparator
        return a; // Return sorted array
    }

    // Calculate modular exponentiation
    static long modpow(long x, long n, long mo) {
        long sum = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                sum = sum * x % mo; // Multiply if n is odd
            }
            x = x * x % mo; // Square the base
            n >>= 1; // Divide n by 2
        }
        return sum; // Return result
    }

    // Reverse a character array
    public static char[] revch(char ch[]) {
        char ret[] = new char[ch.length];
        for (int i = ch.length - 1, j = 0; i >= 0; i--, j++) {
            ret[j] = ch[i]; // Reverse characters
        }
        return ret; // Return reversed array
    }

    // Reverse an integer array
    public static int[] revint(int ch[]) {
        int ret[] = new int[ch.length];
        for (int i = ch.length - 1, j = 0; i >= 0; i--, j++) {
            ret[j] = ch[i]; // Reverse integers
        }
        return ret; // Return reversed array
    }

    // Implement the Floyd-Warshall algorithm for shortest paths
    public static void warshall_floyd(int v[][], int n) {
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]); // Update shortest paths
    }

    // Calculate modular inverse using Extended Euclidean Algorithm
    public static long modint(long a, long m) {
        long b = m, u = 1, v = 0;
        while (b != 0) {
            long t = a / b;
            a -= t * b;
            long x = a;
            a = b;
            b = x;

            u -= t * v;
            x = u;
            u = v;
            v = x;
        }
        u %= m; // Ensure u is positive
        if (u < 0) u += m;
        return u; // Return modular inverse
    }
}

// FastScanner class for efficient input reading
class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    // Check if there is a next byte available
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true; // Bytes available in buffer
        } else {
            ptr = 0;
            try {
                buflen = in.read(buffer); // Read new bytes into buffer
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false; // No more bytes available
            }
        }
        return true; // Bytes available
    }

    // Read a byte from the input stream
    private int readByte() {
        if (hasNextByte()) return buffer[ptr++]; else return -1;
    }

    // Check if a character is printable
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126; // ASCII printable range
    }

    // Check if there is a next printable character
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        return hasNextByte(); // Return if there is a next printable character
    }

    // Read the next string from input
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b); // Append printable characters
            b = readByte();
        }
        return sb.toString(); // Return the constructed string
    }

    // Read the next long integer from input
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true; // Handle negative numbers
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException(); // Invalid number format
        }
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0'; // Construct the number
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n; // Return the number with sign
            } else {
                throw new NumberFormatException(); // Invalid number format
            }
            b = readByte();
        }
    }

    // Read the next integer from input
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl; // Return the integer value
    }

    // Read the next double from input
    public double nextDouble() {
        return Double.parseDouble(next()); // Parse and return double
    }

    // Read the next character from input
    public char nextchar() {
        try {
            return (char) System.in.read(); // Read a single character
        } catch (Exception e) {
            throw new RuntimeException(e); // Handle exceptions
        }
    }
}
