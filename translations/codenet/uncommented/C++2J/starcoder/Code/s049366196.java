import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		long ans = 1;
		for (int i = 2; i <= N; i++) {
			if (isPrime(i)) {
				int NN = N;
				int cnt = 0;
				while (NN > 0) {
					cnt += NN/i;
					NN /= i;
				}
				ans *= cnt+1;
				ans %= mod;
			}
		}

		System.out.println(ans);
	}

	public static boolean isPrime(int x) {
		for (int i = 2; i*i <= x; i++)
			if (x % i == 0) return false;
		return true;
	}
}

