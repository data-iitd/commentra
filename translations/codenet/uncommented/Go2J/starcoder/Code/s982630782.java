import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Map<Integer, Integer> m = new HashMap<Integer, Integer>();
		int N = ReadInt();
		int M = ReadInt();
		for (int i = 0; i < N; i++) {
			int x = ReadInt();
			if (m.containsKey(x)) {
				m.put(x, m.get(x) + 1);
			} else {
				m.put(x, 1);
			}
		}
		for (int i = 0; i < M; i++) {
			int B = ReadInt();
			int C = ReadInt();
			if (m.containsKey(C)) {
				m.put(C, m.get(C) + B);
			} else {
				m.put(C, B);
			}
		}
		List<Integer> ints = new ArrayList<Integer>(m.keySet());
		Collections.sort(ints, Collections.reverseOrder());
		int rest = N;
		int sum = 0;
		for (int i : ints) {
			int num = m.get(i);
			if (num >= rest) {
				sum += rest * i;
				break;
			}
			sum += num * i;
			rest -= num;
		}
		System.out.println(sum);
	}

	static int ReadInt() throws IOException {
		return Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
	}
}

