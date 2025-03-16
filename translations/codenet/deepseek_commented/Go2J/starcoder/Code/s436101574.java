import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		String s = sc.next();
		String t = sc.next();
		for (int i = 0; i < s.length() - t.length() + 1; i++) {
			boolean f = true;
			char[] ss = s.toCharArray();
			for (int j = 0; j < t.length(); j++) {
				if (ss[i + j]!= t.charAt(j) && ss[i + j]!= '?') {
					f = false;
					break;
				} else {
					ss[i + j] = t.charAt(j);
				}
			}
			if (f) {
				sb.append(new String(ss).replace('?', 'a'));
			}
		}
		if (sb.length() == 0) {
			System.out.println("UNRESTORABLE");
		} else {
			System.out.println(sb.toString());
		}
	}
}

