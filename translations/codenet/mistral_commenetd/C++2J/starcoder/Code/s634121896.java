
import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n;
		n = in.nextInt();
		int[] nums = new int[n];
		int last = 0;
		for(int i=0; i<n; i++){
			nums[i] = in.nextInt();
			last = nums[i];
		}
		int[] dp = new int[n+1];
		dp[0] = 1;
		Map<Integer, Integer> kek = new HashMap<Integer, Integer>();
		Map<Integer, Integer> prev = new HashMap<Integer, Integer>();
		for(int i=1; i<=n; i++){
			dp[i] = dp[i-1] + (prev.get(nums[i-1])!=i-1? kek.get(nums[i-1]):0);
			dp[i] %= MOD;
			kek.put(nums[i-1], dp[i]);
			prev.put(nums[i-1], i);
		}
		System.out.println(dp[n]);
	}
}

