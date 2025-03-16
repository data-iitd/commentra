package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			int times = Integer.parseInt(reader.readLine());
			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			for (int i = 0; i < times; i++) {
				String[] line = reader.readLine().split(" ");
				for (int j = 0; j < line.length; j++) {
					int n = Integer.parseInt(line[j]);
					if (map.containsKey(n)) {
						map.remove(n);
					} else {
						map.put(n, 1);
					}
				}
			}
			Set<Integer> set = new TreeSet<Integer>(map.keySet());
			for (int n : set) {
				writer.write(n + "\n");
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
}

