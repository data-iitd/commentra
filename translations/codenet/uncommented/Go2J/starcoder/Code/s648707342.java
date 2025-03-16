import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int n = new BufferedReader(new InputStreamReader(System.in)).readLine().trim().length();
		ArrayList<Arm> as = new ArrayList<Arm>();
		for (int i = 0; i < n; i++) {
			int x = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine().trim());
			int l = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine().trim());
			as.add(new Arm(x - l, x + l));
		}
		Collections.sort(as, new Comparator<Arm>() {
			@Override
			public int compare(Arm a, Arm b) {
				return a.r - b.r;
			}
		});
		int ans = 1, r = as.get(0).r;
		for (int i = 1; i < n; i++) {
			if (as.get(i).l >= r) {
				ans++;
				r = as.get(i).r;
			}
		}
		System.out.println(ans);
	}
}

class Arm {
	int l, r;

	public Arm(int l, int r) {
		this.l = l;
		this.r = r;
	}
}

