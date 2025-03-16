
import java.util.Scanner;

public class s698205968{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int m = sc.nextInt();
			int f = sc.nextInt();
			int r = sc.nextInt();
			if (m == -1 && f == -1 && r == -1) break;
			if (m == -1 || f == -1) System.out.print("F");
			else if (m + f >= 80) System.out.print("A");
			else if (m + f >= 65) System.out.print("B");
			else if (m + f >= 50 || r >= 50) System.out.print("C");
			else if (m + f >= 30) System.out.print("D");
			else System.out.print("F");
			System.out.println();
		}
		sc.close();
	}
}
