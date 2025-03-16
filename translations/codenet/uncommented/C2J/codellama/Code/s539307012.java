
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = sc.nextInt();
		int min = sc.nextInt();
		x -= min;
		for (int i = 1; i < n; i++) {
			int m = sc.nextInt();
			x -= m;
			if (min > m) {
				min = m;
			}
		}
		System.out.println(n + x / min);
		sc.close();
	}

}

