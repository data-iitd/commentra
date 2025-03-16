import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Deque {
    private List<Byte> front;
    private List<Byte> back;

    public Deque() {
        front = new ArrayList<>();
        back = new ArrayList<>();
    }

    public boolean isEmptyFront() {
        return front.isEmpty();
    }

    public boolean isEmptyBack() {
        return back.isEmpty();
    }

    public void pushBack(byte v) {
        back.add(v);
    }

    public void pushFront(byte v) {
        front.add(v);
    }

    public boolean popBack(Byte[] v) {
        if (!isEmptyBack()) {
            v[0] = back.remove(back.size() - 1);
            return true;
        } else if (!isEmptyFront()) {
            v[0] = front.remove(0);
            return true;
        }
        return false;
    }

    public boolean popFront(Byte[] v) {
        if (!isEmptyFront()) {
            v[0] = front.remove(front.size() - 1);
            return true;
        } else if (!isEmptyBack()) {
            v[0] = back.remove(0);
            return true;
        }
        return false;
    }

    public byte get(int idx) {
        int tot = front.size() + back.size();
        if (idx < tot) {
            if (idx < front.size()) {
                return front.get(front.size() - 1 - idx);
            } else {
                return back.get(idx - front.size());
            }
        }
        return 0; // Default return value, should not be used
    }
}

class Op {
    boolean rev;
    boolean front;
    byte c;

    public Op(boolean rev, boolean front, byte c) {
        this.rev = rev;
        this.front = front;
        this.c = c;
    }
}

public class Main {
    public static String rev(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int Q = scanner.nextInt();
        Op[] ops = new Op[Q];

        for (int i = 0; i < Q; i++) {
            int q = scanner.nextInt();
            if (q == 1) {
                ops[i] = new Op(true, false, (byte) 0);
            } else {
                int f = scanner.nextInt();
                byte c = scanner.next().getBytes()[0];
                ops[i] = new Op(false, f == 1, c);
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

        Deque deq = new Deque();
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) {
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
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            result.append((char) (byte) deq.front.get(i));
        }
        result.append(S);
        for (int i = 0; i < deq.back.size(); i++) {
            result.append((char) (byte) deq.back.get(i));
        }
        System.out.println(result);
    }
}
// <END-OF-CODE>
