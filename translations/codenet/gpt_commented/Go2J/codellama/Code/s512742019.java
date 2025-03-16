
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());
        Monster[] monsters = new Monster[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            monsters[i] = new Monster(x, h);
        }
        List<Monster> monsterList = new ArrayList<>();
        for (Monster monster : monsters) {
            monsterList.add(monster);
        }
        Collections.sort(monsterList, new Comparator<Monster>() {
            @Override
            public int compare(Monster o1, Monster o2) {
                return o1.x - o2.x;
            }
        });
        int ans = 0;
        int total = 0;
        Queue queue = new Queue();
        for (int i = 0; i < N; i++) {
            Monster m = monsterList.get(i);
            while (!queue.isEmpty() && queue.first().x < m.x) {
                total -= queue.pop().h;
            }
            if (total < m.h) {
                m.h -= total;
                int count = (int) Math.ceil((double) m.h / A);
                ans += count;
                int damage = count * A;
                queue.push(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }
        System.out.println(ans);
    }

    static class Monster {
        int x;
        int h;

        Monster(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Node {
        int x;
        int h;

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    static class Queue {
        List<Node> arr = new ArrayList<>();

        void push(Node v) {
            arr.add(v);
        }

        Node first() {
            return arr.get(0);
        }

        Node pop() {
            Node res = arr.get(0);
            arr.remove(0);
            return res;
        }

        boolean isEmpty() {
            return arr.isEmpty();
        }
    }
}

