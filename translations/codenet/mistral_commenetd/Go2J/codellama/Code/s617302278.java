
// Importing required packages
import java.util.Scanner;

// Initializing scanner
Scanner sc = new Scanner(System.in);

// Function to read a line text from stdin and return its string
public static String NextLine() {
	// Scanning next line from stdin
	sc.nextLine();
	// Returning the scanned line text
	return sc.nextLine();
}

// Function to read a line text, that consists of ONLY INTEGERS DELIMITED BY SPACES, from stdin
// And then returns integers slice
public static int[] NextIntsLine() {
	// Initializing empty integers slice
	int[] ints = new int[0];
	// Reading a line text from stdin
	String intsStr = NextLine();
	// Splitting the line text by space
	String[] tmp = intsStr.split(" ");
	// Iterating through the split text and converting each string to integer
	// and appending it to the integers slice
	for (String s : tmp) {
		// Converting string to integer
		int integer = Integer.parseInt(s);
		// Appending integer to integers slice
		ints = append(ints, integer);
	}
	// Returning the integers slice
	return ints;
}

// Function to read a line text, that consists of ONLY CHARACTERS ARRANGED CONTINUOUSLY, from stdin
// And then returns runes slice
public static char[] NextRunesLine() {
	// Returning the next line text as runes slice
	return NextLine().toCharArray();
}

// Function to find the maximum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
public static int Max(int... integers) {
	// Initializing maximum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 0; i < integers.length; i++) {
		// If current integer is greater than maximum integer, update maximum integer
		if (i == 0) {
			continue;
		}
		if (m < integers[i]) {
			m = integers[i];
		}
	}
	// Returning the maximum integer
	return m;
}

// Function to find the minimum integer among input integers
// This function needs at least 1 argument (no argument causes panic)
public static int Min(int... integers) {
	// Initializing minimum integer as first integer
	int m = integers[0];
	// Iterating through the input integers
	for (int i = 0; i < integers.length; i++) {
		// If current integer is smaller than minimum integer, update minimum integer
		if (i == 0) {
			continue;
		}
		if (m > integers[i]) {
			m = integers[i];
		}
	}
	// Returning the minimum integer
	return m;
}

// Function to calculate integer power
public static int PowInt(int a, int e) {
	// Checking for negative integers
	if (a < 0 || e < 0) {
		panic(errors.New("[argument error]: PowInt does not accept negative integers"));
	}
	// Converting base and exponent to float64
	double fa = (double) a;
	double fe = (double) e;
	// Calculating the power using math.Pow
	double fanswer = Math.pow(fa, fe);
	// Converting the answer back to integer
	return (int) fanswer;
}

// Function to calculate absolute value of an integer
public static int AbsInt(int a) {
	// Converting integer to float64
	double fa = (double) a;
	// Calculating the absolute value using math.Abs
	double fanswer = Math.abs(fa);
	// Converting the answer back to integer
	return (int) fanswer;
}

// Function to delete an element from a slice
public static int[] DeleteElement(int[] s, int i) {
	// Checking for negative index or empty slice
	if (i < 0 || s.length <= i) {
		panic(errors.New("[index error]"));
	}
	// Creating a new slice with zero capacity
	int[] n = new int[0];
	// Appending elements before the index to the new slice
	n = append(n, s[:i]...);
	// Appending elements after the index to the new slice
	n = append(n, s[i + 1:]...);
	// Returning the new slice
	return n;
}

// Function to concatenate two slices
public static char[] Concat(char[] s, char[] t) {
	// Creating a new slice with zero capacity
	char[] n = new char[0];
	// Appending elements of the first slice to the new slice
	n = append(n, s...);
	// Appending elements of the second slice to the new slice
	n = append(n, t...);
	// Returning the new slice
	return n;
}

// Function to sort a slice using sort package
//sort.Sort(sort.IntSlice(s))
//sort.Sort(sort.Reverse(sort.IntSlice(s)))
//sort.Sort(sort.Float64Slice(s))
//sort.Sort(sort.StringSlice(s))

// Function to copy elements from one slice to another
//a = []int{0, 1, 2}
//b = make([]int, len(a))
//copy(b, a)

// Variable declaration and initialization
int x;

// Main function
public static void main(String[] args) {
	// Reading integers from stdin as a line text
	int[] tmp = NextIntsLine();
	// Assigning the first integer to variable x
	x = tmp[0];
	// Initializing sum variable as zero
	int sum = 0;
	// Initializing index variable as one
	int i = 1;
	// Looping until the sum is greater than or equal to x
	while (true) {
		// Adding current index to sum
		sum += i;
		// Checking if sum is greater than or equal to x
		if (sum >= x) {
			// Breaking the loop
			break;
		}
		// Incrementing index
		i++;
	}
	// Printing the index
	System.out.println(i);
}

