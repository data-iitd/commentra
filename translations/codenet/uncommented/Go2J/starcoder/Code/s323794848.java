package main;

import java.io.*;
import java.util.*;

class deque {
	byte[] front, back;
	int f, b;
	int tot;

	public deque() {
		front = new byte[100000];
		back = new byte[100000];
		f = b = tot = 0;
	}

	public boolean isEmptyFront() {
		return f == 0;
	}
	public boolean isEmptyBack() {
		return b == tot;
	}

	public void pushBack(byte v) {
		back[b] = v;
		b++;
		if (b == back.length) {
			b = 0;
		}
		if (b == f) {
			byte[] tmp = front;
			front = back;
			back = tmp;
			f = 0;
			b = tot;
		}
	}
	public void pushFront(byte v) {
		if (f == 0) {
			if (b == tot) {
				return;
			}
			for (int i = b; i < tot; i++) {
				front[f] = back[i];
				f++;
			}
			b = 0;
			tot -= b;
		}
		front[f-1] = v;
		f--;
	}
	public boolean popBack(byte[] v) {
		if (b == tot) {
			return false;
		}
		v[0] = back[b];
		b++;
		if (b == back.length) {
			b = 0;
		}
		return true;
	}
	public boolean popFront(byte[] v) {
		if (f == 0) {
			return false;
		}
		v[0] = front[f-1];
		f--;
		if (f == 0) {
			f = tot;
			for (int i = 0; i < b; i++) {
				back[i] = front[i];
			}
			b = 0;
		}
		return true;
	}

	public byte get(int idx) {
		int tot = f + b;
		byte v = 0;
		if (idx < tot) {
			if (idx < f) {
				v = front[f-1-idx];
			} else {
				v = back[idx-f];
			}
		}
		return v;
	}
}

class op {
	boolean rev, front;
	byte c;
	public op(boolean rev, boolean front, byte c) {
		this.rev = rev;
		this.front = front;
		this.c = c;
	}
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		String S = br.readLine();
		int Q = Integer.parseInt(br.readLine());
		op[] ops = new op[Q];
		for (int i = 0; i < Q; i++) {
			int q = Integer.parseInt(br.readLine());
			if (q == 1) {
				ops[i] = new op(true, false, 0);
			} else {
				int f = Integer.parseInt(br.readLine());
				byte c = br.readLine().getBytes()[0];
				if (f == 1) {
					ops[i] = new op(false, true, c);
				} else {
					ops[i] = new op(false, false, c);
				}
			}
		}
		int[] sum = new int[Q+1];
		for (int i = Q - 1; i >= 1; i--) {
			if (ops[i].rev) {
				sum[i-1] = sum[i] + 1;
			} else {
				sum[i-1] = sum[i];
			}
		}
		if (sum[0] % 2 == 1) {
			S = new StringBuilder(S).reverse().toString();
		}
		deque deq = new deque();
		for (int i = 0; i < Q; i++) {
			if (!ops[i].rev) { // 反転ではない(文字列追加)
				if (ops[i].front) {
					if (sum[i] % 2 == 1) {
						deq.pushBack(ops[i].c);
					} else {
						deq.pushFront(ops[i].c);
					}
				} else {
					if (sum[i] % 2 == 1) {
						deq.pushFront(ops[i].c);
					} else {
						deq.pushBack(ops[i].c);
					}
				}
			}
		}
		for (int i = deq.f - 1; i >= 0; i--) {
			wtr.write(deq.front[i]);
		}
		wtr.write(S);
		for (int i = 0; i < deq.b; i++) {
			wtr.write(deq.back[i]);
		}
		wtr.write("\n");
		wtr.flush();
	}
}

