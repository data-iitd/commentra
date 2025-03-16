
import java.util.Scanner;

public class LinearSearch {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = sc.nextInt();
		}
		int q = sc.nextInt();
		int t = 0;
		int count = 0;
		for (int i = 0; i < q; i++) {
			t = sc.nextInt();
			if (linearSearch(s, n, t))
				count++;
		}
		System.out.println(count);
	}

	public static boolean linearSearch(int[] a, int n, int key) {
		for (int i = 0; i < n; i++) {
			if (a[i] == key)
				return true;
		}
		return false;
	}
}

