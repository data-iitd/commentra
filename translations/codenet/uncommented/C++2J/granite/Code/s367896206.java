
import java.util.Scanner;

class Cube {
	int f[];

	Cube() {
		f = new int[6];
	}

	void roll_z() {
		roll(1, 2, 4, 3);
	}

	void roll_y() {
		roll(0, 2, 5, 3);
	}

	void roll_x() {
		roll(0, 1, 5, 4);
	}

	void roll(int i, int j, int k, int l) {
		int t = f[i];
		f[i] = f[j];
		f[j] = f[k];
		f[k] = f[l];
		f[l] = t;
	}
}

class s367896206 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Cube c1 = new Cube(), c2 = new Cube();
		for (int i = 0; i < 6; i++)
			c1.f[i] = sc.nextInt();
		for (int i = 0; i < 6; i++)
			c2.f[i] = sc.nextInt();
		boolean flg = false;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 4; j++) {
				if (equal(c1, c2)) {
					flg = true;
					break;
				}
				c1.roll_z();
			}
			if (i % 2 == 0)
				c1.roll_y();
			else
				c1.roll_x();
		}
		System.out.println(flg? "Yes" : "No");
	}

	static boolean equal(Cube c1, Cube c2) {
		for (int i = 0; i < 6; i++) {
			if (c1.f[i]!= c2.f[i])
				return false;
		}
		return true;
	}
}
