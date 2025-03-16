package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

		String s = sc.next();
		String t = sc.next();

		List<String> ans = new ArrayList<>();
		for (int i = 0; i < s.length() - t.length() + 1; i++) {
			boolean f = true;
			char[] ss = s.toCharArray();

			for (int j = 0; j < t.length(); j++) {
				if (s.charAt(i + j)!= t.charAt(j) && s.charAt(i + j)!= '?') {
					f = false;
					break;
				} else {
					ss[i + j] = t.charAt(j);
				}
			}
			if (f) {
				ans.add(new String(ss).replace('?', 'a'));
			}
		}
		Collections.sort(ans);
		if (ans.size() == 0) {
			wr.write("UNRESTORABLE");
		} else {
			wr.write(ans.get(0));
		}
		wr.close();
	}
}

