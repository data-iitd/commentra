package main;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		Data[] s = new Data[N];
		for (int i = 0; i < N; i++) {
			s[i] = new Data(sc.next());
		}
		Arrays.sort(s);
		String ans = "";
		for (int i = 0; i < N; i++) {
			ans = ans + s[i].X;
		}
		System.out.println(ans);
	}
}

class Data implements Comparable<Data> {
	String X;

	public Data(String x) {
		X = x;
	}

	@Override
	public int compareTo(Data o) {
		return this.X.compareTo(o.X);
	}
}

