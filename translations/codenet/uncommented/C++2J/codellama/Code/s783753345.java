import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b;
		char S;
		while (true) {
			a = sc.nextInt();
			S = sc.next().charAt(0);
			b = sc.nextInt();
			if (S == '+') System.out.println(a + b);
			if (S == '-') System.out.println(a - b);
			if (S == '*') System.out.println(a * b);
			if (S == '/') System.out.println(a / b);
			if (S == '?') break;
		}
	}
}
