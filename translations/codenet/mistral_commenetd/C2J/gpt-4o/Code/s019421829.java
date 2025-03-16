import java.util.Arrays;
import java.util.Scanner;

public class PrimeCount {
    static final int MAX = 707106; // sqrt(10^12/2)
    static char[] tbl = new char[MAX + 1];

    static int sz; // max sz = 57084, prime[0] = 2, prime[57083] = 707099
    static int[] prime = new int[57100]; // Declare an array 'prime' of size 57100 to store prime numbers

    static {
        // Initialize the prime array with the first few prime numbers
        int[] initialPrimes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
            73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
            127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
            179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
            233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
            283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
            353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
            419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
            467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
            547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
            607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
            661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
            739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
            811, 821, 823, 827, 829, 839, 853
        };
        System.arraycopy(initialPrimes, 0, prime, 0, initialPrimes.length);
    }

    static void sieve() {
        int k;
        for (int i = 1; i < 147; i++) {
            k = prime[i]; // Get the current prime number
            for (int j = k * k; j < MAX; j += k) {
                tbl[j] = 1; // Mark all multiples of 'k' as composite in 'tbl' array
            }
        }
        for (sz = 146, int i = 853; i <= MAX; i += 2) {
            if (tbl[i] == 0) {
                prime[sz++] = i; // If 'i' is not marked as composite, it is a prime number
            }
        }
    }

    static int[] base = new int[1000002];
    static int[] idx = new int[1000002];
    static long[] pp = new long[41]; // 2^40 = 1099511627776 >= 10^12

    static int bsch(int x) {
        int l = 0, r = sz;
        while (l < r) {
            int m = (l + r) >> 1; // Calculate the middle index 'm'
            if (prime[m] == x) return m; // If 'x' is a prime number, return its index
            if (prime[m] < x) l = m + 1; // If 'prime[m]' is smaller than 'x', 'l' should be updated
            else r = m; // Otherwise, 'r' should be updated
        }
        return l - 1; // Return the index of the largest prime number 'p' such that 'p^2 <= x'
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A, B, a, b;
        sieve(); // Call the Sieve of Eratosthenes algorithm to find prime numbers

        A = scanner.nextLong();
        B = scanner.nextLong(); // Read two integers 'A' and 'B' from the standard input
        a = A - B;
        b = A + B;
        if (b <= 1) {
            System.out.println("0");
            return;
        }
        if (a <= 1) a = 2;

        sz = bsch((int) Math.sqrt(b >> 1)); // Find the largest prime number 'p' such that 'p^2 <= b'

        Arrays.fill(idx, 1); // Initialize all elements of 'idx' array to 1
        Arrays.fill(base, 0); // Initialize all elements of 'base' array to 0

        for (int i = 0; i <= sz; i++) {
            int p = prime[i]; // Get the current prime number
            for (int k = 1, j = p; j <= b; j *= p) {
                pp[k++] = j; // Calculate all powers of 'p' less than or equal to 'b'
            }
            for (int k = k - 1; k >= 0; k--) {
                long j = pp[k];
                long ll = j * (1 + (a - 1) / j);
                long rr = j * (b / j); // Calculate the lower and upper bounds of the segment to search for 'a' in
                for (; ll <= rr; ll += j) {
                    int x = (int) (ll - a); // Calculate the index 'x' of the segment
                    if (idx[x] == 0 || base[x] == p) continue; // If 'x' is already processed or the prime number at 'x' is the same as 'p', skip it
                    base[x] = p;
                    idx[x] = k; // Otherwise, set the prime number at 'x' to 'p' and its index to 'k'
                }
            }
        }

        int ans = 0;
        int count = (int) (b - a + 1); // Initialize 'ans' to 0 and the loop counter 'count' to the number of segments
        while (count-- > 0) {
            if (idx[count] != 0) ans++; // Increment 'ans' if the current segment has been processed
        }
        System.out.println(ans); // Output the result 'ans' and terminate the program
    }
}
// <END-OF-CODE>
