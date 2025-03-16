
import java.util.Scanner;

public class s344526598{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int i, j, x[] = new int[10000];

		for (i = 0; i < 10000; i++) {
			x[i] = 0;
		}
		i = 0;
		x[i] = sc.nextInt();

		while (x[i]!= 0) {
			i++;
			x[i] = sc.nextInt();
		}

		for (j = 0; j < i; j++) {
			System.out.printf("Case %d: %d\n", j + 1, x[j]);
		}

		sc.close();
	}
}
