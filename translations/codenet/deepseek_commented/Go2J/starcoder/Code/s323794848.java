import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String S = br.readLine();
		int Q = Integer.parseInt(br.readLine());
		Deque<op> ops = new ArrayDeque<op>();
		for (int i = 0; i < Q; i++) {
			int q = Integer.parseInt(br.readLine());
			if (q == 1) {
				ops.add(new op(true, false, 0));
			} else {
				int f = Integer.parseInt(br.readLine());
				char c = br.readLine().charAt(0);
				if (f == 1) {
					ops.add(new op(false, true, c));
				} else {
					ops.add(new op(false, false, c));
				}
			}
		}
		int[] sum = new int[Q + 1];
		for (int i = Q - 1; i >= 1; i--) {
			if (ops.get(i).rev) {
				sum[i - 1] = sum[i] + 1;
			} else {
				sum[i - 1] = sum[i];
			}
		}
		if (sum[0] % 2 == 1) {
			S = new StringBuilder(S).reverse().toString();
		}
		Deque<Character> deq = new ArrayDeque<Character>();
		for (int i = 0; i < Q; i++) {
			if (!ops.get(i).rev) { // Not a reversal operation (string append)
				if (ops.get(i).front) {
					if (sum[i] % 2 == 1) {
						deq.addLast(ops.get(i).c);
					} else {
						deq.addFirst(ops.get(i).c);
					}
				} else {
					if (sum[i] % 2 == 1) {
						deq.addFirst(ops.get(i).c);
					} else {
						deq.addLast(ops.get(i).c);
					}
				}
			}
		}
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		for (int i = deq.size() - 1; i >= 0; i--) {
			wtr.write(deq.get(i));
		}
		wtr.write(S);
		for (int i = 0; i < deq.size(); i++) {
			wtr.write(deq.get(i));
		}
		wtr.write("\n");
		wtr.flush();
	}
}

class op {
	boolean rev;
	boolean front;
	char c;

	op(boolean rev, boolean front, char c) {
		this.rev = rev;
		this.front = front;
		this.c = c;
	}
}

