package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

		String s = scanner.next();
		String t = scanner.next();

		int ns = s.length();
		int nt = t.length();
		String[] ss = new String[(nt - 1) / ns + 1];
		for (int i = 0; i < ss.length; i++) {
			ss[i] = s;
		}

		String sss = String.join("", ss) + String.join("", ss);

		boolean[] ok = new boolean[ns];

		int[] uni = new int[ns];
		for (int i = 0; i < ns; i++) {
			uni[i] = i;
		}
		int m = 0;
		boolean o;
		for (int i = 0; i < ns; i++) {
			o = true;
			for (int j = 0; j < nt; j++) {
				if (t.charAt(j)!= sss.charAt(i + j)) {
					o = false;
					break;
				}
			}
			ok[i] = o;
			if (o) {
				i += nt - mp.table[m];
				m = mp.table[m];
			}
			for (int j = 0; j < m && t.charAt(j)!= sss.charAt(i + j); j++) {
				i += m - mp.table[m];
				m = mp.table[m];
			}
			i--;
			m++;
		}

		int ans = 0;
		int r, rr;
		for (int i = 0; i < ns; i++) {
			if (!ok[i]) {
				continue;
			}
			if (!ok[(i + nt) % ns]) {
				continue;
			}
			r = root(i, uni);
			rr = root((i + nt) % ns, uni);
			if (rr == r) {
				System.out.println(-1);
				return;
			}
			uni[rr] = r;
		}

		int[] counter = new int[ns];
		for (int i = 0; i < ns; i++) {
			r = root(i, uni);
			if (!ok[r]) {
				continue;
			}
			counter[r]++;
		}
		for (int i = 0; i < ns; i++) {
			if (ans < counter[i]) {
				ans = counter[i];
			}
		}

		System.out.println(ans);

		writer.flush();
	}

	public static int root(int i, int[] uni) {
		if (i == uni[i]) {
			return i;
		}

		uni[i] = root(uni[i], uni);
		return uni[i];
	}

	// MP...
	class MP {
		String s;
		int[] table;

		public void init(String s) {
			this.s = s;
			int n = s.length();
			table = new int[n + 1];
			table[0] = -1;
			int j = -1;
			for (int i = 0; i < n; i++) {
				for (j = j; j >= 0 && s.charAt(i)!= s.charAt(j); j = table[j]) {
				}
				j++;
				table[i + 1] = j;
			}
		}
	}
}

