
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] c = new int[26];
		while (sc.hasNext()) {
			String str = sc.next();
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
					c[str.charAt(i) - 'a']++;
				} else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
					c[str.charAt(i) - 'A']++;
				}
			}
		}
		for (int i = 0; i < 26; i++) {
			System.out.println((char) ('a' + i) + " : " + c[i]);
		}
	}
}

