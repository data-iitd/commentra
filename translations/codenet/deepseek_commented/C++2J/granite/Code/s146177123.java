
import java.util.*;
import java.io.*;

class s146177123 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n, t;
		boolean[] st = new boolean[7];
		while ((n = in.nextInt())!= -1) {
			for (int i = 0; i < n; i++) {
				t = in.nextInt();
				char[] ans = new char[8];
				for (int j = 0; j < 7; j++) {
					ans[j] = (st[j] ^ (t & (1 << j)) == 1)? '1' : '0';
					st[j] = (t & (1 << j)) == 1;
				}
				System.out.println(ans);
			}
		}
	}
}

Translate the above Java code to Python and end with comment "