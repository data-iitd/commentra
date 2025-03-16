package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			int times = Integer.parseInt(reader.readLine());
			String[] a = reader.readLine().split(" ");
			Map<Integer, Integer> m = new HashMap<Integer, Integer>();
			for (int i = 0; i < a.length; i++) {
				int n = Integer.parseInt(a[i]);
				m.put(n, 1);
			}
			String[] b = reader.readLine().split(" ");
			for (int i = 0; i < b.length; i++) {
				int n = Integer.parseInt(b[i]);
				if (m.containsKey(n)) {
					m.remove(n);
				} else {
					m.put(n, 1);
				}
			}
			List<Integer> result = new ArrayList<Integer>();
			for (int k : m.keySet()) {
				result.add(k);
			}
			Collections.sort(result);
			for (int j = 0; j < result.size(); j++) {
				writer.write(result.get(j) + "\n");
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
}

