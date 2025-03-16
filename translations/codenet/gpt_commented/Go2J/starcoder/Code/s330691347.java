import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int L = sc.nextInt();
		Data[] s = new Data[N];
		for (int i = 0; i < N; i++) {
			s[i] = new Data();
			s[i].X = sc.next();
		}
		System.out.println(N + " " + L + " " + s);
		Arrays.sort(s);
		System.out.println(s);
		String ans = "";
		for (int i = 0; i < N; i++) {
			ans = ans + s[i].X;
		}
		System.out.println(ans);
	}
}

class Data implements Comparable<Data> {
	String X;
	public int compareTo(Data o) {
		return X.compareTo(o.X);
	}
}

