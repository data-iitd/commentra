
import java.util.Scanner;

public class s387232787{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] c = new int[26];
		while (sc.hasNext()) {
			String str = sc.next();
			for (int i = 0; i < str.length(); i++) {
				char ch = str.charAt(i);
				if ('a' <= ch && ch <= 'z') {
					c[ch - 'a']++;
				} else if ('A' <= ch && ch <= 'Z') {
					c[ch - 'A']++;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			System.out.println((char)('a' + i) + " : " + c[i]);
		}
	}
}
