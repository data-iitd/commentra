import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int ans = 0;

		if (N == 1 && M == 1) {
			ans += 1;
		} else if (N > 1 && M > 1) {
			ans += (N - 2) * (M - 2);
		} else {
			ans += (N * M) - 2;
		}

		System.out.println(ans);
	}
}

/*  ----------------------------------------  */

// max function returns the maximum value from a variable number of integers
public static int max(int... x) {
	int res = x[0];
	for (int i = 1; i < x.length; i++) {
		res = Math.max(res, x[i]);
	}
	return res;
}

// min function returns the minimum value from a variable number of integers
public static int min(int... x) {
	int res = x[0];
	for (int i = 1; i < x.length; i++) {
		res = Math.min(res, x[i]);
	}
	return res;
}

// pow function calculates x raised to the power of y
public static int pow(int x, int y) { return (int) Math.pow(x, y); }

// abs function returns the absolute value of an integer
public static int abs(int x) { return Math.abs(x); }

// floor function returns the largest integer less than or equal to x
public static int floor(int x) { return (int) Math.floor(x); }

// SortBy is a type that implements sorting based on absolute values
class SortBy implements Comparator<Integer> {
	public int compare(Integer a, Integer b) {
		return Integer.compare(Math.abs(a), Math.abs(b));
	}
}

