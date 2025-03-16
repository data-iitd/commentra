// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
	int M = sc.nextInt();
	int ans = 0;
	// If both N and M are 1, there is only one cell, so the answer is 1.
	if (N == 1 && M == 1) {
		ans += 1;
	} else if (1 < N && 1 < M) {
		// If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
		ans += (N - 2) * (M - 2);
	} else {
		// If either N or M is 1, the number of cells is (N*M) - 2.
		ans += (N * M) - 2;
	}

	System.out.println(ans);
}

/*  ----------------------------------------  */

// This function returns the maximum value among the given integers.
public static int max(int... x) {
	int res = x[0];
	for (int i = 1; i < x.length; i++) {
		res = Math.max(x[i], res);
	}
	return res;
}

// This function returns the minimum value among the given integers.
public static int min(int... x) {
	int res = x[0];
	for (int i = 1; i < x.length; i++) {
		res = Math.min(x[i], res);
	}
	return res;
}

// This function returns x raised to the power of y.
public static int pow(int x, int y) { return (int) Math.pow(x, y); }

// This function returns the absolute value of x.
public static int abs(int x) { return Math.abs(x); }

// This function returns the floor value of x.
public static int floor(int x) { return (int) Math.floor(x); }

// This type is a slice of integers that can be sorted by their absolute values.
class SortBy implements Comparable<SortBy> {
	int[] a;

	public SortBy(int[] a) {
		this.a = a;
	}

	// Len returns the length of the slice.
	public int len() { return a.length; }

	// Swap swaps the elements with indexes i and j.
	public void swap(int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

	// Less returns true if the absolute value of the element at index i is less than the absolute value of the element at index j.
	public int less(int i, int j) { return Math.abs(a[i]) < Math.abs(a[j]); }

	// Compare returns -1 if the absolute value of the element at index i is less than the absolute value of the element at index j, 0 if they are equal, and 1 if the absolute value of the element at index i is greater than the absolute value of the element at index j.
	public int compareTo(SortBy o) {
		if (less(0, o.len() - 1)) {
			return -1;
		} else if (less(o.len() - 1, 0)) {
			return 1;
		} else {
			return 0;
		}
	}
}

