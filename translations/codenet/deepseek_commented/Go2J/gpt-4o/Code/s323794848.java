import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Deque class to simulate a double-ended queue
class Deque {
    private List<Byte> front;
    private List<Byte> back;

    public Deque() {
        front = new ArrayList<>();
        back = new ArrayList<>();
    }

    // Check if the front of the deque is empty
    public boolean isEmptyFront() {
        return front.isEmpty();
    }

    // Check if the back of the deque is empty
    public boolean isEmptyBack() {
        return back.isEmpty();
    }

    // Push a byte to the back of the deque
    public void pushBack(byte v) {
        back.add(v);
    }

    // Push a byte to the front of the deque
    public void pushFront(byte v) {
        front.add(v);
    }

    // Pop a byte from the back of the deque
    public boolean popBack(ByteHolder v) {
        if (!isEmptyBack()) {
            v.value = back.remove(back.size() - 1);
            return true;
        } else if (!isEmptyFront()) {
            v.value = front.remove(0);
            return true;
        }
        return false;
    }

    // Pop a byte from the front of the deque
    public boolean popFront(ByteHolder v) {
        if (!isEmptyFront()) {
            v.value = front.remove(front.size() - 1);
            return true;
        } else if (!isEmptyBack()) {
            v.value = back.remove(0);
            return true;
        }
        return false;
    }

    // Get the byte at a specific index in the deque
    public byte get(int idx) {
        int tot = front.size() + back.size();
        if (idx < tot) {
            if (idx < front.size()) {
                return front.get(front.size() - 1 - idx);
            } else {
                return back.get(idx - front.size());
            }
        }
        return 0; // Return 0 if index is out of bounds
    }
}

// Operation class to store each operation's details
class Operation {
    boolean rev;
    boolean front;
    byte c;

    public Operation() {
        this.rev = false;
        this.front = false;
        this.c = 0;
    }
}

// ByteHolder class to hold a byte value
class ByteHolder {
    public byte value;

    public ByteHolder() {
        this.value = 0;
    }
}

// Reverse a string
public class Main {
    public static String rev(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int Q = scanner.nextInt();
        Operation[] ops = new Operation[Q];
        for (int i = 0; i < Q; i++) {
            ops[i] = new Operation();
            int q = scanner.nextInt();
            if (q == 1) {
                ops[i].rev = true;
            } else {
                int f = scanner.nextInt();
                ops[i].c = scanner.next().getBytes()[0];
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
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            result.append((char) deq.front.get(i).byteValue());
        }
        result.append(S);
        for (int i = 0; i < deq.back.size(); i++) {
            result.append((char) deq.back.get(i).byteValue());
        }
        System.out.println(result);
    }
}
// <END-OF-CODE>
