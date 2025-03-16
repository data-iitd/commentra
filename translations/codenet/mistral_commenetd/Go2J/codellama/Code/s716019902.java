
// Constants
final int mod = 998244353;
final int facNum = 300001;

// Main function
public static void main(String[] args) {
	// Initialize a new scanner
	Scanner sc = new Scanner(System.in);

	// Read an integer N from the standard input
	int N = sc.nextInt();

	// Initialize a variable sum to 0
	int sum = 0;

	// Loop through numbers from 1 to N
	for (int i = 1; i <= N; i++) {
		// If the number is not divisible by 3 or 5, add it to the sum
		if (i % 3 != 0 && i % 5 != 0) {
			sum += i;
		}
	}

	// Print the result to the standard output
	System.out.println(sum);
}

// I/O
class Scanner {
	// Initialize a new scanner
	Scanner(InputStream input) {
		// Initialize a new scanner with the given input
		sc = new java.util.Scanner(input);

		// Set the scanner to split input on words
		sc.useDelimiter("\\s+");

		// Set the scanner buffer size
		sc.useLocale(java.util.Locale.US);
	}

	// Helper methods for scanner
	String s() {
		// Scan the next token and return it as a string
		sc.next();
		return sc.next();
	}

	int i() {
		// Convert the next token to an integer and return it
		return Integer.parseInt(s());
	}

	double f() {
		// Convert the next token to a float64 and return it
		return Double.parseDouble(s());
	}

	byte[] bs() {
		// Return the next token as a byte slice
		return s().getBytes();
	}

	int[] is(int n) {
		// Read n integers from the standard input and return them as a slice
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = i();
		}
		return res;
	}

	double[] fs(int n) {
		// Read n floating-point numbers from the standard input and return them as a slice
		double[] res = new double[n];
		for (int i = 0; i < n; i++) {
			res[i] = f();
		}
		return res;
	}

	// Scanner instance
	java.util.Scanner sc;
}

// Math functions
int Pow(int a, int n) {
	// Calculate a^n modulo mod
	int ans = 1;
	for (; n > 0; n >>= 1) {
		if ((n & 1) == 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
	}
	return ans;
}

int Gcd(int a, int b) {
	// Calculate the greatest common divisor of a and b
	if (a < b) {
		return Gcd(b, a);
	}
	for (; b != 0; a = b, b = a % b) {
	}
	return a;
}

int min(int a, int b) {
	// Return the minimum of a and b
	if (a < b) {
		return a;
	}
	return b;
}

// Combination function
int combination(int n, int k, int[] fac, int[] ifac) {
	// Calculate the binomial coefficient (n choose k) modulo mod
	if (n < k || n < 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}
	// While n is not 0
	int ans = ifac[k] * ifac[n - k] % mod;
	return ans * fac[n] % mod;
}

// Factorial function
int[][] factorial() {
	// Calculate and return the factorial of all numbers from 0 to facNum-1
	int[] fac = new int[facNum];
	int[] ifac = new int[facNum];
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < facNum; i++) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * Pow(i, mod - 2) % mod;
	}
	return new int[][] { fac, ifac };
}

// Lower bound function
int lowerBound(int[] vs, int v) {
	// Calculate the index of the first element in vs that is greater than or equal to v
	int n = vs.length / 2;
	int m = vs.length;
	for (; m != n;) {
		if (vs[n] < v) {
			n = (m - n + 1) / 2 + n;
			//m = m;
		} else {
			m = n;
			n = n / 2;
		}
	}
	return n;
}

// IntSlice function
int[] IntSlice(int n, int init) {
	// Create and initialize a slice of length n with the given initial value
	int[] r = new int[n];
	for (int i = 0; i < r.length; i++) {
		r[i] = init;
	}
	return r;
}

// 

