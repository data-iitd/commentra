
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		String p = sc.next();
		sc.close();

		str = str + str;
		int slen = str.length();
		int plen = p.length();

		boolean flag = false;
		for (int i = 0; i < slen - plen; i++) {
			if (str.substring(i, i + plen).equals(p)) {
				flag = true;
			}
		}

		if (flag) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

