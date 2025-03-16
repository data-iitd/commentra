// Define constants for base and maximum size
final long B = 13131;
final int N = 500000 + 7;

// Declare global variables
int n; // Length of the input string
char[] s = new char[N]; // Input string
long[] f = new long[N]; // Array to store computed values based on the input string
int[] g = new int[N]; // Array to store the shift values
Map<Long, Long> map = new HashMap<>(); // Map to count occurrences of computed values
long cnt; // Counter for the final result

// Function to compute power of a number with a given exponent
long pow(long a, long k) {
    // Adjust exponent if negative
    if (k < 0) k += (1L << 63) - 1;
    long t = 1; // Initialize result
    // Exponentiation by squaring
    for (; k; a = a * a, k >>= 1)
        if (k & 1) t = t * a; // Multiply result if current bit is set
    return t; // Return computed power
}

public static void main(String[] args) {
    // Uncomment the following lines to read from a file
    // Scanner sc = new Scanner(new File("code.in"));
    // PrintWriter pw = new PrintWriter(new File("code.out"));

    // Read input values: number of operations and the operations string
    // n = sc.nextInt();
    // sc.nextLine();
    // sc.nextLine();
    // sc.nextBytes(s);
    n = 10;
    s[1] = '+';
    s[2] = '>';
    s[3] = '+';
    s[4] = '>';
    s[5] = '+';
    s[6] = '>';
    s[7] = '+';
    s[8] = '>';
    s[9] = '+';
    s[10] = '>';

    // Process each character in the input string
    for (int i = 1; i <= n; ++i) {
        // If the character is '+' or '-', update f and g arrays
        if (s[i] == '+' || s[i] == '-') {
            f[i] = f[i - 1] + (s[i] == '+' ? 1 : -1) * pow(B, g[i] = g[i - 1]);
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i - 1]; // No change in f
            g[i] = g[i - 1] + (s[i] == '<' ? -1 : 1); // Update g based on direction
        }
    }

    // Iterate backwards through the string to count valid combinations
    for (int i = n; i; --i) {
        ++map.getOrDefault(f[i], 0L); // Increment the count of the current f value
        // Update the counter with the number of valid combinations found
        cnt += map.getOrDefault(f[n] * pow(B, g[i - 1]) + f[i - 1], 0L);
    }

    // Output the final count of valid combinations
    // pw.println(cnt);
    // pw.close();
    System.out.println(cnt);

    // End of the program
    // 