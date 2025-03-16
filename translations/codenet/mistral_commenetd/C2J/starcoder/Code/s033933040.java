import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a, b, mawari, menseki;
		a = input.nextInt();
		b = input.nextInt();
		mawari = a * a + b * b;
		menseki = a * b;
		System.out.println(menseki + " " + mawari);
	}
}
