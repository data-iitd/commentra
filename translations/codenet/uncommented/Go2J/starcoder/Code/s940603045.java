package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		String N = sc.next();
		int n = 0;
		for (int i = 0; i < N.length(); i++) {
			n += (N.charAt(i) - '0');
		}
		int m = Integer.parseInt(N);
		if (m % n == 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

