import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b, mawari, menseki;
		a = sc.nextInt();
		b = sc.nextInt();
		mawari = 2 * (a + b);
		menseki = a * b;
		System.out.println(menseki + " " + mawari);
	}
}
