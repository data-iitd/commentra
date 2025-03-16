#include <stdio.h>
#include <string.h>

public class Main {
	public static void main(String[] args) {
		String A = new String();
		String B = new String();
		String C = new String();

		Scanner sc = new Scanner(System.in);

		A = sc.next();
		B = sc.next();
		C = sc.next();

		int la = A.length();
		int lb = B.length();

		if (A.charAt(la - 1) == B.charAt(0) && B.charAt(lb - 1) == C.charAt(0)) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}
}

