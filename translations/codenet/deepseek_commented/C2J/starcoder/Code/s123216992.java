import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (a == 0 && b == 0) break;
			if (b < a) swap(a, b);
			System.out.println(a + " " + b);
		}
	}

	public static void swap(int a, int b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
}
