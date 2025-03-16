package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();

		int mx = Math.max(A+B, Math.max(A-B, A*B));
		System.out.println(mx);
	}
}

