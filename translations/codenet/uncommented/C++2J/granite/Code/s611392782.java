
// ACM-ICPCアジア地区予選2014 B. Miscalculation

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s611392782{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";

		while ((line = br.readLine())!= null) {
			if (line.isEmpty())
				break;
			String[] input = line.split(" ");
			String s = input[0];
			int d = Integer.parseInt(input[1]);
			int idx = 0;
			int a = add(s, idx);
			idx = 0;
			int b = bob(s, idx);
			if (a == d) {
				System.out.println(b == d? "U" : "M");
			} else {
				System.out.println(b == d? "L" : "I");
			}
		}
	}

	public static int mul(String str, int idx) {
		int res = str.charAt(idx) - '0';
		while (idx + 1 < str.length() && str.charAt(idx + 1) == '*') {
			idx += 2;
			res *= str.charAt(idx) - '0';
		}
		return res;
	}

	public static int add(String str, int idx) {
		int res = mul(str, idx);
		while (idx + 1 < str.length() && str.charAt(idx + 1) == '+') {
			idx += 2;
			res += mul(str, idx);
		}
		return res;
	}

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

