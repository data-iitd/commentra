
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int K = in.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = in.nextInt();
		}
		int cur = 1;
		int[] dic = new int[N + 1];
		Arrays.fill(dic, -1);
		boolean flg = false;
		for (int i = 1; i <= K; i++) {
			if (dic[cur] < 0 || flg) {
				dic[cur] = i;
				cur = A[cur];
			} else if (!flg) {
				int tmp = K - (dic[cur] - 1);
				tmp %= i - dic[cur];
				i = K - tmp;
				flg = true;
			}
		}
		System.out.println(cur);
	}
}

