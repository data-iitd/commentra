
// ACM-ICPCアジア地区予選2014 B. Miscalculation

import java.util.Scanner;

public class s611392782{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String s = sc.next();
			int d = sc.nextInt();
			int idx = 0;
			int a = add(s, idx); // Calculate the result using the add function
			idx = 0;
			int b = bob(s, idx); // Calculate the result using the bob function
			if (a == d) {
				System.out.println((b == d)? "U" : "M"); // Output based on both results
			} else {
				System.out.println((b == d)? "L" : "I"); // Output based on both results
			}
		}
	}

	// This function multiplies consecutive digits until it encounters a '+' or the end of the string.
	public static int mul(String str, int idx) {
		int res = str.charAt(idx) - '0';
		while (idx + 1 < str.length() && str.charAt(idx + 1) == '*') {
			idx += 2;
			res *= str.charAt(idx) - '0';
		}
		return res;
	}

	// This function adds the results of multiple calls to mul by handling '+' operations.
	public static int add(String str, int idx) {
		int res = mul(str, idx);
		while (idx + 1 < str.length() && str.charAt(idx + 1) == '+') {
			idx += 2;
			res += mul(str, idx);
		}
		return res;
	}

	// This function performs the same operations as add but uses a different approach.
	public static int bob(String str, int idx) {
		int res = str.charAt(idx) - '0';
		while (idx + 1 < str.length()) {
			if (str.charAt(idx + 1) == '+')
				res += str.charAt(idx + 2) - '0';
			else
				res *= str.charAt(idx + 2) - '0';
			idx += 2;
		}
		return res;
	}
}
