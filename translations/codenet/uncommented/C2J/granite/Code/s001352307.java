
import java.util.Scanner;

public class s001352307{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = 0;
		while(true) {
			int W = sc.nextInt();
			int N = sc.nextInt();
			if(W == 0 && N == 0)
				break;
			int[][] input = new int[N][2];
			for(int i = 0; i < N; i++) {
				String[] tmp = sc.next().split(",");
				input[i][0] = Integer.parseInt(tmp[0]);
				input[i][1] = Integer.parseInt(tmp[1]);
			}
			int[][] ans = new int[1024][2];
			for(int i = 0; i < 1024; i++) {
				ans[i][0] = 0;
				ans[i][1] = 0;
			}
			for(int i = 0; i < N; i++) {
				for(int j = 1023; j >= input[i][1]; j--) {
					if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
						ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
						ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
					}
				}
			}
			int j = 0;
			while(ans[W][0] == ans[W - j - 1][0])
				j++;
			System.out.println("Case " + (t + 1) + ":");
			System.out.println(ans[W - j][0]);
			System.out.println(ans[W - j][1]);
			t++;
		}
	}
}

