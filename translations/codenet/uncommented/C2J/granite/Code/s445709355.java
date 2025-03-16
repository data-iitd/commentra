
// ABC 152-D
// 2020.1.19 bal4u

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class s445709355{
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] f1 = new int[100];
		int[] f2 = new int[100];
		int k, m, ans = 0;
		
		while (n > 0) {
			k = n % 10;
			m = n;
			while (m >= 10) m /= 10;
			f1[10 * k + m]++;
			f2[10 * m + k]++;
			n--;
		}
		
		for (int i = 0; i < 100; i++) {
			ans += f1[i] * f2[i];
		}
		
		System.out.println(ans);
	}
}
// END-OF-CODE