
import java.util.Scanner;

public class s990550009{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		boolean isup = a[0] < a[1];
		boolean issame = false;
		int cnt = 1;
		for (int i = 1; i < n - 1; i++) {
			if (issame) {
				if (a[i]!= a[i + 1]) {
					issame = false;
					isup = a[i] < a[i + 1];
				}
			} else {
				if (isup && a[i] <= a[i + 1]) {
					;
				} else if (!isup && a[i] >= a[i + 1]) {
					;
				} else {
					if (i + 2 < n) {
						isup = a[i + 1] < a[i + 2];
						cnt++;
					} else {
						cnt++;
						break;
					}
				}
			}
		}
		System.out.println(cnt);
	}
}
