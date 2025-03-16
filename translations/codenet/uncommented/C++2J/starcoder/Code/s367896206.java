
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Cube c1 = new Cube();
		Cube c2 = new Cube();
		for (int i = 0; i < 6; i++)c1.f[i] = sc.nextInt();
		for (int i = 0; i < 6; i++)c2.f[i] = sc.nextInt();
		if (equal(c1, c2))System.out.println("Yes");
		else System.out.println("No");
	}
	public static boolean equal(Cube c1, Cube c2) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (c1.f[0] == c2.f[0] && c1.f[1] == c2.f[1] && c1.f[2] == c2.f[2] && c1.f[3] == c2.f[3] && c1.f[4] == c2.f[4] && c1.f[5] == c2.f[5])return true;
				c1.roll_z();
			}
			if (i % 2 == 0)c1.roll_y();
			else c1.roll_x();
		}
		return false;
	}
	public static class Cube {
		int f[] = new int[6];
		public void roll_z() {
			int t = f[1]; f[1] = f[2]; f[2] = f[4]; f[4] = f[3]; f[3] = t;
		}
		public void roll_y() {
			int t = f[0]; f[0] = f[2]; f[2] = f[5]; f[5] = f[3]; f[3] = t;
		}
		public void roll_x() {
			int t = f[0]; f[0] = f[1]; f[1] = f[5]; f[5] = f[4]; f[4] = t;
		}
	}
}

