
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a[] = new int[100];
		int b[] = new int[100];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextInt();
			if (a[i] - b[i] > 0) {
				sum += a[i] - b[i];
			}
		}
		System.out.println(sum);
	}
}

