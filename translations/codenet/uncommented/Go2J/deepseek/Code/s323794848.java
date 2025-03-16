import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    static class Dequeue {
        private Deque<Character> front = new LinkedList<>();
        private Deque<Character> back = new LinkedList<>();

        public boolean isEmptyFront() {
            return front.isEmpty();
        }

        public boolean isEmptyBack() {
            return back.isEmpty();
        }

        public void pushBack(char v) {
            back.addLast(v);
        }

        public void pushFront(char v) {
            front.addFirst(v);
        }

        public boolean popBack(Character v) {
            boolean r = true;
            if (!isEmptyBack()) {
                v = back.removeLast();
            } else if (!isEmptyFront()) {
                v = front.removeFirst();
            } else {
                r = false;
            }
            return r;
        }

        public boolean popFront(Character v) {
            boolean r = true;
            if (!isEmptyFront()) {
                v = front.removeLast();
            } else if (!isEmptyBack()) {
                v = back.removeFirst();
            } else {
                r = false;
            }
            return r;
        }

        public char get(int idx) {
            int tot = front.size() + back.size();
            char v = 0;
            if (idx < tot) {
                if (idx < front.size()) {
                    v = front.getLast();
                } else {
                    v = back.getFirst();
                }
            }
            return v;
        }
    }

    static class Op {
        boolean rev, front;
        char c;
    }

    public static String rev(String s) {
        char[] r = new char[s.length()];
        int i = s.length() - 1, j = 0;
        while (i >= 0) {
            r[j] = s.charAt(i);
            j++;
            i--;
        }
        return new String(r);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        int Q = scanner.nextInt();
        scanner.nextLine();
        Op[] ops = new Op[Q];
        for (int i = 0; i < Q; i++) {
            ops[i] = new Op();
            int q = scanner.nextInt();
            if (q == 1) {
                ops[i].rev = true;
            } else {
                int f = scanner.nextInt();
                char c = scanner.next().charAt(0);
                if (f == 1) {
                    ops[i].front = true;
                }
            }
        }
        int[] sum = new int[Q + 1];
        for (int i = Q - 1; i >= 1; i--) {
            if (ops[i].rev) {
                sum[i - 1] = sum[i] + 1;
            } else {
                sum[i - 1] = sum[i];
            }
        }
        if (sum[0] % 2 == 1) {
            S = rev(S);
        }
        Dequeue deq = new Dequeue();
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) { // 反転ではない(文字列追加)
                if (ops[i].front) {
                    if (sum[i] % 2 == 1) {
                        deq.pushBack(ops[i].c);
                    } else {
                        deq.pushFront(ops[i].c);
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.pushFront(ops[i].c);
                    } else {
                        deq.pushBack(ops[i].c);
                    }
                }
            }
        }
        StringBuilder result = new StringBuilder();
        while (!deq.isEmptyFront()) {
            result.append(deq.front.removeLast());
        }
        result.append(S);
        while (!deq.isEmptyBack()) {
            result.append(deq.back.removeFirst());
        }
        System.out.println(result.toString());
    }
}
