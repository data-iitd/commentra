
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = s.charAt(0) + Integer.toString(s.length() - 2) + s.charAt(s.length() - 1);
		System.out.println(t);
	}
}

