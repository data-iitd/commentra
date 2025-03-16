import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		int G = sc.nextInt();
		Problem[] problems = new Problem[D];
		for (int i = 0; i < D; i++) {
			problems[i] = new Problem(sc.nextInt(), sc.nextInt());
		}
		System.out.println(solve(D, G, problems));
	}

	public static int solve(int D, int G, Problem[] problems) {
		int ans = 10000;
		for (int bit = 0; bit < (1 << D); bit++) {
			int score = 0;
			int solved = 0;
			boolean ok = false;
			for (int j = 0; j < D; j++) {
				if ((bit & (1 << j))!= 0) {
					score += (j + 1) * 100 * problems[j].number + problems[j].bonus;
					solved += problems[j].number;
				}
			}
			if (score < G) {
				int j;
				for (j = D - 1; j >= 0; j--) {
					if ((bit & (1 << j)) == 0) {
						break;
					}
				}
				for (int k = 0; k < problems[j].number; k++) {
					score += (j + 1) * 100;
					solved++;
					if (score >= G) {
						ok = true;
						break;
					}
				}
				if (!ok) {
					score += problems[j].bonus;
					if (score >= G) {
						ok = true;
					}
				}
			} else {
				ok = true;
			}
			if (ok) {
				ans = Math.min(ans, solved);
			}
		}
		return ans;
	}
}

class Problem {
	int number, bonus;

	public Problem(int number, int bonus) {
		this.number = number;
		this.bonus = bonus;
	}
}

