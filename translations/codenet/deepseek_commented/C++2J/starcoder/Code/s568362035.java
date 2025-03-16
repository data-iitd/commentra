import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int Q = sc.nextInt();
		int[] a = new int[Q + 1];
		int[] b = new int[m + 1];
		int[] id = new int[m + 1];
		boolean[] vis = new boolean[m + 1];
		int[] cnt = new int[m + 1];
		for (int i = 1; i <= Q; ++i)
			a[i] = sc.nextInt();
		for (int k = 0, j = Q; j > 0; --j)
			if (!vis[a[j]])
				b[++k] = a[j], vis[a[j]] = true;
		for (int j = m, i = m; i > 0; --i)
			if (!vis[i])
				b[j--] = i;
		for (int i = 1; i <= m; ++i)
			id[b[i]] = i;
		boolean flag = true;
		cnt[0] = n;
		for (int i = Q; i > 0; --i) {
			int t = id[a[i]];
			if (cnt[t - 1] > 0)
				--cnt[t - 1];
			else if (!vis[t]) {
				flag = false;
				break;
			}
			++cnt[t];
			vis[t] = true;
		}
		int l;
		for (l = 0; cnt[l] == 0; ++l);
		for (int i = l + 1; i < m; ++i)
			flag &= b[i] < b[i + 1];
		System.out.println(flag? "Yes" : "No");
	}
}

