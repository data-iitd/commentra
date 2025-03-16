
import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] cnt = new int[26];
		char[] s = new char[n];
		for(int i = 0; i < n; i++){
			s[i] = sc.next().charAt(0);
			cnt[s[i] - 'a']++;
		}
		long ans = 1;
		for(int i = 0; i < 26; i++){
			ans *= cnt[i];
		}
		ans--;
		System.out.println(ans);
	}
}

