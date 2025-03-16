import java.util.Scanner;

public class Main {
    // Deque structure to simulate a double-ended queue
    static class Deque {
        private StringBuilder front = new StringBuilder();
        private StringBuilder back = new StringBuilder();

        // Check if the front of the deque is empty
        public boolean isEmptyFront() {
            return front.length() == 0;
        }

        // Check if the back of the deque is empty
        public boolean isEmptyBack() {
            return back.length() == 0;
        }

        // Push a character to the back of the deque
        public void pushBack(char c) {
            back.append(c);
        }

        // Push a character to the front of the deque
        public void pushFront(char c) {
            front.append(c);
        }

        // Pop a character from the back of the deque
        public boolean popBack(StringBuilder v) {
            boolean r = true;
            if (!isEmptyBack()) {
                v.append(back.charAt(back.length() - 1));
                back.deleteCharAt(back.length() - 1);
            } else if (!isEmptyFront()) {
                v.append(front.charAt(0));
                front.deleteCharAt(0);
            } else {
                r = false;
            }
            return r;
        }

        // Pop a character from the front of the deque
        public boolean popFront(StringBuilder v) {
            boolean r = true;
            if (!isEmptyFront()) {
                v.append(front.charAt(front.length() - 1));
                front.deleteCharAt(front.length() - 1);
            } else if (!isEmptyBack()) {
                v.append(back.charAt(0));
                back.deleteCharAt(0);
            } else {
                r = false;
            }
            return r;
        }

        // Get the character at a specific index in the deque
        public char get(int idx) {
            int tot = front.length() + back.length();
            char v = 0;
            if (idx < tot) {
                if (idx < front.length()) {
                    v = front.charAt(front.length() - 1 - idx);
                } else {
                    v = back.charAt(idx - front.length());
                }
            }
            return v;
        }
    }

    // Operation class to store each operation's details
    static class Op {
        boolean rev;
        boolean front;
        char c;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        int Q = scanner.nextInt();
        scanner.nextLine(); // Consume newline
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
                ops[i].c = c;
            }
            scanner.nextLine(); // Consume newline
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
            S = new StringBuilder(S).reverse().toString();
        }
        Deque deq = new Deque();
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) { // Not a reversal operation (string append)
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
        for (int i = deq.front.length() - 1; i >= 0; i--) {
            result.append(deq.front.charAt(i));
        }
        result.append(S);
        for (int i = 0; i < deq.back.length(); i++) {
            result.append(deq.back.charAt(i));
        }
        System.out.println(result.toString());
    }
}
