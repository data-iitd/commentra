
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		String a = cin.next();
		String b = cin.next();
		int n = a.length();
		int m = b.length();
		int ans = n + m + 10;
		for (int i = 0; i + m <= n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				if (a.charAt(i + j) != b.charAt(j))
					sum++;
			}
			ans = Math.min(ans, sum);
		}
		System.out.println(ans);
		cin.close();
	}
}

