
import java.util.Scanner;

public class ABC152D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] f1 = new int[100];
		int[] f2 = new int[100];
		while (N > 0) {
			int k = N % 10;
			N /= 10;
			++f1[10*k + N];
			++f2[N*10 + k];
			--N;
		}
		int ans = 0;
		for (int i = 0; i < 100; ++i) ans += f1[i] * f2[i];
		System.out.println(ans);
	}
}

