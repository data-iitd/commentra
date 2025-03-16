
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Point[] points = new Point[N];
        for (int i = 0; i < N; i++) {
            points[i] = new Point(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }
        sort(points);
        int start = points[0].r;
        int ans = 1;
        for (int i = 0; i < N; i++) {
            if (points[i].l < start) {
                continue;
            }
            start = points[i].r;
            ans++;
        }
        System.out.println(ans);
    }

    public static void sort(Point[] points) {
        for (int i = 0; i < points.length - 1; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].r > points[j].r) {
                    Point temp = points[i];
                    points[i] = points[j];
                    points[j] = temp;
                }
            }
        }
    }

    public static class Point {
        int x;
        int l;
        int r;

        public Point(int x, int l, int r) {
            this.x = x;
            this.l = x - l;
            this.r = x + l;
        }
    }
}

