import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

	void run() throws IOException {
		int N = Integer.parseInt(reader.readLine());
		long[] T = new long[N];
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			String[] s = reader.readLine().split(" ");
			T[i] = Integer.parseInt(s[0]);
			A[i] = Integer.parseInt(s[1]);
		}
		long t = T[0], a = A[0];
		for (int i = 1; i < N; i++) {
			long r = Math.max(Math.ceil((double) t / T[i]), Math.ceil((double) a / A[i]));
			t = T[i] * r;
			a = A[i] * r;
		}
		out(t + a);
	}

	void out(Object... o) throws IOException {
		writer.write(Arrays.deepToString(o));
		writer.write("\n");
	}
}

