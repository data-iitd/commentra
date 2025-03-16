
import java.util.*;
import java.io.*;

class s384319383 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] cnt = new int[26];
		Arrays.fill(cnt, 1);
		char[] s = new char[n];
		for(int i = 0; i < n; i++) {
			s[i] = sc.next().charAt(0);
			cnt[s[i] - 'a']++;
		}
		long ans = cnt[0];
		for(int i = 1; i < 26; i++) {
			ans *= cnt[i];
			ans %= 100000007;
		}
		System.out.println(ans - 1);
	}
}

