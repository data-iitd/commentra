
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        Mon[] M = new Mon[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            M[i] = new Mon(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
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

        System.out.println(ans);
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

    static class Queue {
        Node[] arr;

        Queue() {
            arr = new Node[100000];
        }

        void push(Node v) {
            arr[arr.length - 1] = v;
        }

        Node first() {
            return arr[0];
        }

        Node pop() {
            Node res = arr[0];
            for (int i = 0; i < arr.length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            return res;
        }

        boolean isEmpty() {
            return arr.length == 0;
        }
    }

    // END-OF-CODE
}

