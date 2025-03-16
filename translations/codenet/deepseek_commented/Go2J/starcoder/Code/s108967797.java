import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double[] a = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextDouble();
		}
		double ave = ave(a);
		double minDiff = 999999.9;
		int ansIndex = -1;
		for (int i = 0; i < n; i++) {
			double diff = diff(a[i], ave);
			if (diff < minDiff) {
				minDiff = diff;
				ansIndex = i;
			}
		}
		System.out.println(ansIndex);
	}

	public static double ave(double[] a) {
		double sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum += a[i];
		}
		return sum / a.length;
	}

	public static double diff(double a, double b) {
		if (a > b) {
			return a - b;
		}
		return b - a;
	}
}

