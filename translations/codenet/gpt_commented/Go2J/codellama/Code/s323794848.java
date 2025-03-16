
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String S = br.readLine();
        int Q = Integer.parseInt(br.readLine());
        List<Operation> ops = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            String[] tokens = br.readLine().split(" ");
            int q = Integer.parseInt(tokens[0]);
            if (q == 1) {
                ops.add(new Operation(true, false, ' '));
            } else {
                int f = Integer.parseInt(tokens[1]);
                char c = tokens[2].charAt(0);
                if (f == 1) {
                    ops.add(new Operation(false, true, c));
                } else {
                    ops.add(new Operation(false, false, c));
                }
            }
        }

        int[] sum = new int[Q + 1];
        for (int i = Q - 1; i >= 1; i--) {
            if (ops.get(i).isReverse()) {
                sum[i - 1] = sum[i] + 1;
            } else {
                sum[i - 1] = sum[i];
            }
        }

        if (sum[0] % 2 == 1) {
            S = new StringBuilder(S).reverse().toString();
        }

        Deque<Character> deq = new ArrayDeque<>();
        for (int i = 0; i < Q; i++) {
            if (!ops.get(i).isReverse()) {
                if (ops.get(i).isFront()) {
                    if (sum[i] % 2 == 1) {
                        deq.addLast(ops.get(i).getC());
                    } else {
                        deq.addFirst(ops.get(i).getC());
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.addFirst(ops.get(i).getC());
                    } else {
                        deq.addLast(ops.get(i).getC());
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = deq.size() - 1; i >= 0; i--) {
            sb.append(deq.removeLast());
        }
        sb.append(S);
        for (int i = 0; i < deq.size(); i++) {
            sb.append(deq.removeFirst());
        }
        System.out.println(sb);
    }

    static class Operation {
        boolean isReverse;
        boolean isFront;
        char c;

        Operation(boolean isReverse, boolean isFront, char c) {
            this.isReverse = isReverse;
            this.isFront = isFront;
            this.c = c;
        }

        boolean isReverse() {
            return isReverse;
        }

        boolean isFront() {
            return isFront;
        }

        char getC() {
            return c;
        }
    }
}

