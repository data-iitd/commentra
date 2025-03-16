
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n, t;
		boolean[][] seg = new boolean[10][7];
		while (in.hasNext()) {
			n = in.nextInt();
			if (n < 0) break;
			for (int i = 0; i < 7; i++)
				for (int j = 0; j < 10; j++)
					seg[j][i] = false;
			for (int i = 0; i < n; i++) {
				t = in.nextInt();
				for (int j = 0; j < 7; j++)
					seg[t][j] =!seg[t][j];
				System.out.println(Arrays.toString(seg[t]));
			}
		}
	}
}

