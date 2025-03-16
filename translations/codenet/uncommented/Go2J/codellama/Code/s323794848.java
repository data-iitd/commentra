
package main

import java.util.Scanner;

class deque {
    byte[] front, back;

    boolean isEmptyFront() {
        return front == null || front.length == 0;
    }
    boolean isEmptyBack() {
        return back == null || back.length == 0;
    }

    void pushBack(byte v) {
        if (back == null) {
            back = new byte[] { v };
        } else {
            byte[] tmp = new byte[back.length + 1];
            System.arraycopy(back, 0, tmp, 0, back.length);
            tmp[back.length] = v;
            back = tmp;
        }
    }
    void pushFront(byte v) {
        if (front == null) {
            front = new byte[] { v };
        } else {
            byte[] tmp = new byte[front.length + 1];
            System.arraycopy(front, 0, tmp, 1, front.length);
            tmp[0] = v;
            front = tmp;
        }
    }
    boolean popBack(byte[] v) {
        boolean r = true;
        if (!isEmptyBack()) {
            v[0] = back[back.length - 1];
            back = new byte[back.length - 1];
            System.arraycopy(back, 0, back, 0, back.length);
        } else if (!isEmptyFront()) {
            v[0] = front[0];
            front = new byte[front.length - 1];
            System.arraycopy(front, 1, front, 0, front.length);
        } else {
            r = false;
        }
        return r;
    }
    boolean popFront(byte[] v) {
        boolean r = true;
        if (!isEmptyFront()) {
            v[0] = front[front.length - 1];
            front = new byte[front.length - 1];
            System.arraycopy(front, 0, front, 0, front.length);
        } else if (!isEmptyBack()) {
            v[0] = back[0];
            back = new byte[back.length - 1];
            System.arraycopy(back, 1, back, 0, back.length);
        } else {
            r = false;
        }
        return r;
    }

    byte get(int idx) {
        int tot = (front == null ? 0 : front.length) + (back == null ? 0 : back.length);
        byte v = 0;
        if (idx < tot) {
            if (idx < front.length) {
                v = front[front.length - 1 - idx];
            } else {
                v = back[idx - front.length];
            }
        }
        return v;
    }
}

class op {
    boolean rev, front;
    byte c;
}

public class Main {
    public static String rev(String s) {
        byte[] r = new byte[s.length()];
        for (int i = s.length() - 1, j = 0; i >= 0; i--, j++) {
            r[j] = (byte) s.charAt(i);
        }
        return new String(r);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = sc.nextInt();
        op[] ops = new op[Q];
        for (int i = 0; i < Q; i++) {
            int q = sc.nextInt();
            if (q == 1) {
                ops[i] = new op();
                ops[i].rev = true;
            } else {
                ops[i] = new op();
                ops[i].c = (byte) sc.next().charAt(0);
                if (sc.nextInt() == 1) {
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
        // System.out.println("S " + S + " Q " + Q + " ops " + ops + " sum " + sum);
        if (sum[0] % 2 == 1) {
            S = rev(S);
        }
        deque deq = new deque();
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
        StringBuilder sb = new StringBuilder();
        for (int i = deq.front.length - 1; i >= 0; i--) {
            sb.append((char) deq.front[i]);
        }
        sb.append(S);
        for (int i = 0; i < deq.back.length; i++) {
            sb.append((char) deq.back[i]);
        }
        System.out.println(sb.toString());
    }
}

