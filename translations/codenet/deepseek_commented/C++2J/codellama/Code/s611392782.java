// ACM-ICPCアジア地区予選2014 B. Miscalculation

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String s = sc.next();
			int d = sc.nextInt();
			int idx = 0;
			int a = add(s, idx);
			idx = 0;
			int b = bob(s, idx);
			if (a == d) {
				System.out.println(b == d ? "U" : "M");
			} else {
				System.out.println(b == d ? "L" : "I");
			}
		}
	}

	public static int add(String s, int idx) {
		int res = mul(s, idx);
		while (idx + 1 < s.length() && s.charAt(idx + 1) == '+') {
			idx += 2;
			res += mul(s, idx);
		}
		return res;
	}

	public static int bob(String s, int idx) {
		int res = s.charAt(idx) - '0';
		while (idx + 1 < s.length()) {
			if (s.charAt(idx + 1) == '+')
				res += s.charAt(idx + 2) - '0';
			else
				res *= s.charAt(idx + 2) - '0';
			idx += 2;
		}
		return res;
	}

	public static int mul(String s, int idx) {
		int res = s.charAt(idx) - '0';
		while (idx + 1 < s.length() && s.charAt(idx + 1) == '*') {
			idx += 2;
			res *= s.charAt(idx) - '0';
		}
		return res;
	}
}

