import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a, b, c, d;
		a = input.nextInt();
		b = input.nextInt();
		c = input.nextInt();
		d = input.nextInt();
		if (a + b > c + d) {
			System.out.println("Left");
		} else if (a + b < c + d) {
			System.out.println("Right");
		} else {
			System.out.println("Balanced");
		}
	}
}
