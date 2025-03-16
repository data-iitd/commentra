import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = sc.nextInt();
			if (a[i] - b[i] > 0) {
				sum += a[i] - b[i];
			}
		}
		System.out.println(sum);
	}
}
