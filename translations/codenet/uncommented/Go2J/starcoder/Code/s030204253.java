import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextDouble();
		}
		for (int i = 0; i + 1 < n; i++) {
			Arrays.sort(a);
			double[] na = new double[0];
			for (int j = 2; j < a.length; j++) {
				na = Arrays.copyOf(na, na.length + 1);
				na[na.length - 1] = a[j];
			}
			na = Arrays.copyOf(na, na.length + 1);
			na[na.length - 1] = (a[0] + a[1]) / 2;
			a = na;
		}
		System.out.println(a[0]);
	}
}

