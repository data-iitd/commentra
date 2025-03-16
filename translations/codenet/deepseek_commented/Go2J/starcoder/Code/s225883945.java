import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] a = new int[n];
		a[0] = 0;
		int sum = k;
		int ans = 1;
		while (sum < n) {
			sum = sum - 1 + k;
			ans++;
		}
		System.out.println(ans);
	}
}

