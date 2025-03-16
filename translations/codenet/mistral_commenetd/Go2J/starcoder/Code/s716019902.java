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
		if (i % 3!= 0 && i % 5!= 0) {
			sum += i;
		}
	}

	// Print the result to the standard output
	System.out.println(sum);
}

// I/O
class scanner {
	// Initialize a new scanner
	public scanner(InputStream input) {
		// Initialize a new bufio.Scanner with the given input
		sc = new Scanner(input);

		// Set the scanner to split input on words
		sc.useDelimiter(new String(new char[] {'' }));
	}

	// Helper methods for scanner
	public String s() {
		// Scan the next token and return it as a string
		sc.next();
		return sc.next();
	}

	public int i() {
		// Convert the next token to an integer and return it
		return Integer.parseInt(s());
	}

	public float f() {
		// Convert the next token to a float64 and return it
		return Float.parseFloat(s());
	}

	public byte[] bs() {
		// Return the next token as a byte slice
		return s().getBytes();
	}

	public int[] is(int n) {
		// Read n integers from the standard input and return them as a slice
		int[] res = new int[n];
		for (int i = 0; i < n; i++) {
			res[i] = i();
		}
		return res;
	}

	public float[] fs(int n) {
		// Read n floating-point numbers from the standard input and return them as a slice
		float[] res = new float[n];
		for (int i = 0; i < n; i++) {
			res[i] = f();
		}
		return res;
	}

	// Scanner instance
	Scanner sc;
}

// Math functions
class math {
	// Calculate a^n modulo mod
	public static int Pow(int a, int n) {
		// Calculate a^n modulo mod
		int ans = 1;
		for (int i = 0; i < 31; i++) {
			if ((n >> i) & 1 == 1) {
				ans = (ans * a) % mod;
			}
			a = (a * a) % mod;
		}
		return ans;
	}

	// Calculate the greatest common divisor of a and b
	public static int Gcd(int a, int b) {
		// Calculate the greatest common divisor of a and b
		if (a < b) {
			return Gcd(b, a);
		}
		while (b!= 0) {
			a = b;
			b = a % b;
		}
		return a;
	}

	// Return the minimum of a and b
	public static int min(int a, int b) {
		// Return the minimum of a and b
		if (a < b) {
			return a;
		}
		return b;
	}
}

// Combination function
class combination {
	// Calculate the binomial coefficient (n choose k) modulo mod
	public static int combination(int n, int k, int[] fac, int[] ifac) {
		// Calculate the binomial coefficient (n choose k) modulo mod
		if (n < k || n < 0) {
			return 0;
		}
		if (k == 0) {
			return 1;
		}
		// While n is not 0
		int ans = ifac[k] * ifac[n-k] % mod;
		return ans * fac[n] % mod;
	}

	// Factorial function
	public static int[] factorial() {
		// Calculate and return the factorial of all numbers from 0 to facNum-1
		int[] fac = new int[facNum];
		fac[0] = 1;
		int[] ifac = new int[facNum];
		ifac[0] = 1;
		for (int i = 1; i < facNum; i++) {
			fac[i] = fac[i-1] * i % mod;
			ifac[i] = ifac[i-1] * math.Pow(i, mod-2) % mod;
		}
		return fac;
	}

	// Lower bound function
	public static int lowerBound(int[] vs, int v) {
		// Calculate the index of the first element in vs that is greater than or equal to v
		int n = vs.length / 2;
		int m = vs.length;
		while (m!= n) {
			if (vs[n] < v) {
				n = (m-n+1)/2 + n;
				//m = m;
			} else {
				m = n;
				n = n / 2;
			}
		}
		return n;
	}

	// IntSlice function
	public static int[] IntSlice(int n, int init) {
		// Create and initialize a slice of length n with the given initial value
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = init;
		}
		return r;
	}
}

// 