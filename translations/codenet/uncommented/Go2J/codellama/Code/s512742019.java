
package main

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter wtr = new PrintWriter(System.out);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();
        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }
        Arrays.sort(M, new Comparator<Mon>() {
            @Override
            public int compare(Mon o1, Mon o2) {
                return o1.x - o2.x;
            }
        });
        PriorityQueue<Node> q = new PriorityQueue<>();
        int ans = 0;
        int total = 0;
        for (int i = 0; i < N; i++) {
            Mon m = M[i];
            while (!q.isEmpty() && q.peek().x < m.x) {
                total -= q.poll().h;
            }
            if (total < m.h) {
                m.h -= total;
                int count = (int) Math.ceil((double) m.h / A);
                ans += count;
                int damage = count * A;
                q.offer(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }

        wtr.println(ans);
        wtr.flush();
    }

    static class Mon {
        int x, h;

        Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Node {
        int x, h;

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Comparator implements java.util.Comparator<Mon> {
        @Override
        public int compare(Mon o1, Mon o2) {
            return o1.x - o2.x;
        }
    }

    static class PriorityQueue<T> {
        T[] arr;

        PriorityQueue() {
            arr = (T[]) new Object[100000];
        }

        void push(T v) {
            arr[arr.length - 1] = v;
        }

        T first() {
            return arr[0];
        }

        T pop() {
            T res = arr[0];
            arr[0] = null;
            return res;
        }

        boolean isEmpty() {
            return arr[0] == null;
        }
    }
}

