
// Util functions
import java.util.Scanner;

// Util functions
public static String nextStr() {
	// Scans the next token, a rune, into sc.Text().
	sc.next();
	// Returns the text scanned into sc.Text() as a string.
	return sc.next();
}

// With a comment explaining what the function does:
// Scans the next token, a rune, into sc.Text() and returns it as a string.
public static String nextStr() {
	// Scans the next token, a rune, into sc.Text().
	sc.next();
	// Returns the text scanned into sc.Text() as a string.
	return sc.next();
}

public static int nextInt() {
	// Scans the next token, a string, into sc.Text().
	// Converts the string to an integer using Integer.parseInt() and returns it.
	sc.next();
	return Integer.parseInt(sc.next());
}

// With a comment explaining what the function does:
// Scans the next token, a string, into sc.Text() and converts it to an integer.
public static int nextInt() {
	// Scans the next token, a string, into sc.Text().
	sc.next();
	// Converts the string to an integer using Integer.parseInt().
	return Integer.parseInt(sc.next());
}

// Helper functions for mathematical operations
public static int maxInt(int a, int b) {
	// Returns the maximum of two integers.
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two integers.
public static int maxInt(int a, int b) {
	// If 'a' is greater than 'b', return 'a'.
	if (a > b) {
		return a;
	} else {
		// Otherwise, return 'b'.
		return b;
	}
}

public static int minInt(int a, int b) {
	// Returns the minimum of two integers.
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two integers.
public static int minInt(int a, int b) {
	// If 'a' is greater than 'b', return 'b'.
	if (a > b) {
		return b;
	} else {
		// Otherwise, return 'a'.
		return a;
	}
}

public static int absInt(int a) {
	// Returns the absolute value of an integer.
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of an integer.
public static int absInt(int a) {
	// If the integer is non-negative, return it as is.
	if (a >= 0) {
		return a;
	} else {
		// Otherwise, return the negative of the integer.
		return -a;
	}
}

public static double absFloat64(double a) {
	// Returns the absolute value of a floating-point number.
	if (a >= 0) {
		return a;
	} else {
		return -a;
	}
}

// With a comment explaining what the function does:
// Returns the absolute value of a floating-point number.
public static double absFloat64(double a) {
	// If the floating-point number is non-negative, return it as is.
	if (a >= 0) {
		return a;
	} else {
		// Otherwise, return the negative of the floating-point number.
		return -a;
	}
}

public static double maxFloat64(double a, double b) {
	// Returns the maximum of two floating-point numbers.
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

// With a comment explaining what the function does:
// Returns the maximum of two floating-point numbers.
public static double maxFloat64(double a, double b) {
	// If 'a' is greater than 'b', return 'a'.
	if (a > b) {
		return a;
	} else {
		// Otherwise, return 'b'.
		return b;
	}
}

public static double minFloat64(double a, double b) {
	// Returns the minimum of two floating-point numbers.
	if (a > b) {
		return b;
	} else {
		return a;
	}
}

// With a comment explaining what the function does:
// Returns the minimum of two floating-point numbers.
public static double minFloat64(double a, double b) {
	// If 'a' is greater than 'b', return 'b'.
	if (a > b) {
		return b;
	} else {
		// Otherwise, return 'a'.
		return a;
	}
}

public static int str2Int(String s) {
	// Converts a string to an integer.
	return Integer.parseInt(s);
}

// With a comment explaining what the function does:
// Converts a string to an integer.
public static int str2Int(String s) {
	// Attempts to convert the string to an integer using Integer.parseInt().
	return Integer.parseInt(s);
}

public static String reverse(String s) {
	// Reverses a given string.
	char[] runes = s.toCharArray();
	// Iterates through the rune slice from both ends and swaps the elements.
	for (int i = 0, j = runes.length - 1; i < j; i++, j--) {
		// Swaps the elements at the current indices.
		char temp = runes[i];
		runes[i] = runes[j];
		runes[j] = temp;
	}
	// Returns the reversed string.
	return new String(runes);
}

// With a comment explaining what the function does:
// Reverses a given string.
public static String reverse(String s) {
	// Initializes a char array with the given string.
	char[] runes = s.toCharArray();
	// Iterates through the rune slice from both ends and swaps the elements.
	for (int i = 0, j = runes.length - 1; i < j; i++, j--) {
		// Swaps the elements at the current indices.
		char temp = runes[i];
		runes[i] = runes[j];
		runes[j] = temp;
	}
	// Returns the reversed string.
	return new String(runes);
}

public static int powInt(int p, int q) {
	// Calculates 'p' raised to the power of 'q'.
	return (int) Math.pow(p, q);
}

// With a comment explaining what the function does:
// Calculates 'p' raised to the power of 'q'.
public static int powInt(int p, int q) {
	// Calculates 'p' raised to the power of 'q' using the Math.pow() function.
	return (int) Math.pow(p, q);
}

public static boolean isPrime(int x) {
	// Checks if a given number is prime.
	if (x == 1) {
		// 1 is not a prime number.
		return false;
	}
	if (x == 2) {
		// 2 is a prime number.
		return true;
	}
	// If the number is even, it's not a prime number.
	if (x % 2 == 0) {
		return false;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	boolean b = true;
	int rootx = (int) Math.sqrt(x);
	int i = 3;
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	for (i = 3; i <= rootx; i = i + 2) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x % i == 0) {
			b = false;
			break;
		}
	}
	// Returns the result.
	return b;
}

// With a comment explaining what the function does:
// Checks if a given number is prime.
public static boolean isPrime(int x) {
	// If the number is 1, it's not a prime number.
	if (x == 1) {
		return false;
	}
	// If the number is 2, it's a prime number.
	if (x == 2) {
		return true;
	}
	// If the number is even, it's not a prime number.
	if (x % 2 == 0) {
		return false;
	}

	// Iterates through the numbers from 3 to the square root of 'x'.
	boolean b = true;
	int rootx = (int) Math.sqrt(x);
	int i = 3;
	// Checks if any of the numbers from 3 to the square root of 'x' divide 'x'.
	for (i = 3; i <= rootx; i = i + 2) {
		// If 'x' is divisible by the current number, it's not a prime number.
		if (x % i == 0) {
			b = false;
			break;
		}
	}
	// Returns the result.
	return b;
}

public static int[] PrimeFactors(int n) {
	// Finds the prime factors of a given number.
	// Get the number of 2s that divide n
	int[] pfs = new int[0];
	for (; n % 2 == 0; n /= 2) {
		// Appends 2 to the result slice.
		pfs = Arrays.copyOf(pfs, pfs.length + 1);
		pfs[pfs.length - 1] = 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// While i divides n, appends i to the result slice and divides n by i.
		for (; n % i == 0; n /= i) {
			pfs = Arrays.copyOf(pfs, pfs.length + 1);
			pfs[pfs.length - 1] = i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result slice.
		pfs = Arrays.copyOf(pfs, pfs.length + 1);
		pfs[pfs.length - 1] = n;
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number.
public static int[] PrimeFactors(int n) {
	// Initializes an empty result slice.
	int[] pfs = new int[0];

	// Get the number of 2s that divide n
	for (; n % 2 == 0; n /= 2) {
		// Appends 2 to the result slice.
		pfs = Arrays.copyOf(pfs, pfs.length + 1);
		pfs[pfs.length - 1] = 2;
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// While i divides n, appends i to the result slice and divides n by i.
		for (; n % i == 0; n /= i) {
			pfs = Arrays.copyOf(pfs, pfs.length + 1);
			pfs[pfs.length - 1] = i;
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Appends n to the result slice.
		pfs = Arrays.copyOf(pfs, pfs.length + 1);
		pfs[pfs.length - 1] = n;
	}

	// Returns the result.
	return pfs;
}

public static Map<Integer, Integer> PrimeFactorsMap(int n) {
	// Finds the prime factors of a given number and returns them as a map.
	Map<Integer, Integer> pfs = new HashMap<Integer, Integer>();
	// Get the number of 2s that divide n
	for (; n % 2 == 0; n /= 2) {
		// Sets the key to 2 and the value to the number of occurrences.
		pfs.put(2, pfs.getOrDefault(2, 0) + 1);
	}

	// n must be odd at this point. so we can skip one element
	// (note i = i + 2)
	for (int i = 3; i * i <= n; i += 2) {
		// While i divides n, sets the key to i and the value to the number of occurrences.
		// Then divides n by i.
		for (; n % i == 0; n /= i) {
			pfs.put(i, pfs.getOrDefault(i, 0) + 1);
		}
	}

	// This condition is to handle the case when n is a prime number
	// greater than 2
	if (n > 2) {
		// Sets the key to n and the value to the number of occurrences.
		pfs.put(n, pfs.getOrDefault(n, 0) + 1);
	}

	// Returns the result.
	return pfs;
}

// With a comment explaining what the function does:
// Finds the prime factors of a given number and returns them as a map.
public static Map<Integer, Integer> PrimeFactorsMap(int n) {
	// Initializes an empty map.
	Map<Integer, Integer> pfs = new HashMap<Integer, Integer>();

	// Get the number of 2s that divide n
	for (; n % 2 == 0; n /= 2) {
		// Sets the key 