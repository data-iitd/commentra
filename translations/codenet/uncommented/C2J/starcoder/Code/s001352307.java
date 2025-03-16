import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = 0;
		while(true) {
			int W = sc.nextInt();
			int N = sc.nextInt();
			if(W == 0)
				break;
			int[][] input = new int[N][2];
			int[][] ans = new int[W + 1][2];
			for(int i = 0; i < N; i++) {
				input[i][0] = sc.nextInt();
				input[i][1] = sc.nextInt();
			}
			for(int i = 0; i < N; i++) {
				for(int j = W; j >= input[i][1]; j--) {
					if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
						ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
						ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
					}
				}
			}
			int j = 0;
			while(ans[W][0] == ans[W - j - 1][0])
				j++;
			System.out.printf("Case %d:\n%d\n%d\n", ++t, ans[W - j][0], ans[W - j][1]);
		}
	}
}

