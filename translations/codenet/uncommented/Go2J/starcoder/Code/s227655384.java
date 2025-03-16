package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		try {
			int n = Integer.parseInt(reader.readLine());
			Set<Integer> set = new HashSet<>();
			for (int i = 0; i < n; i++) {
				set.add(Integer.parseInt(reader.readLine()));
			}
			n = Integer.parseInt(reader.readLine());
			for (int i = 0; i < n; i++) {
				set.remove(Integer.parseInt(reader.readLine()));
			}
			List<Integer> list = new ArrayList<>(set);
			Collections.sort(list);
			for (int i = 0; i < list.size(); i++) {
				writer.write(list.get(i) + "\n");
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
}

