package main;

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		Point[] points = new Point[N];
		for (int i = 0; i < N; i++) {
			points[i] = new Point();
			points[i].x = sc.nextInt();
			int L = sc.nextInt();
			points[i].l = points[i].x - L;
			points[i].r = points[i].x + L;
		}
		Arrays.sort(points, new Comparator<Point>() {
			public int compare(Point a, Point b) {
				return a.r - b.r;
			}
		});
		int start = points[0].r;
		int ans = 1;
		for (int i = 0; i < N; i++) {
			if (points[i].l < start) continue;
			start = points[i].r;
			ans++;
		}
		System.out.println(ans);
	}
}

class Point {
	int x, l, r;
}

