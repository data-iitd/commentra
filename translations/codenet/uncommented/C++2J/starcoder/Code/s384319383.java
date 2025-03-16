import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = new char[n];
		int[] cnt = new int[26];
		for(int i = 0; i < n; ++i){
			s[i] = sc.next().charAt(0);
			cnt[s[i] - 'a']++;
		}

		long ans = cnt[0];
		for(int i = 1; i < 26; ++i){
			ans *= cnt[i];
			ans %= MOD;
		}

		System.out.println(ans - 1);
	}
}

