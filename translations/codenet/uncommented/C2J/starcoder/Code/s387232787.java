import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String str = sc.next();
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) >= 'a' && str.charAt(i) <= 'z') {
					System.out.println((char) (str.charAt(i) - 'a') + " : " + 1);
				} else if (str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') {
					System.out.println((char) (str.charAt(i) - 'A') + " : " + 1);
				}
			}
		}
	}
}
