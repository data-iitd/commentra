import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] ar = new int[3*n];
		for (int i = 0; i < 3*n; i++) {
			ar[i] = sc.nextInt();
		}
		Arrays.sort(ar);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += ar[3*n-(i+1)*2];
		}
		System.out.println(sum);
	}
}

