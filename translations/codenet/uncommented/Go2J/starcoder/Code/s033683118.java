package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		int k = scanner.nextInt();
		int x = scanner.nextInt();
		scanner.close();

		String ans = "No";
		if (k * 500 >= x) {
			ans = "Yes";
		}
		writer.write(ans);
		writer.close();
	}
}

