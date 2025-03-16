import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Define a deque structure with two lists to represent the front and back.
class Deque {
    private List<Byte> front;
    private List<Byte> back;

    public Deque() {
        front = new ArrayList<>();
        back = new ArrayList<>();
    }

    // Check if the front of the deque is empty.
    public boolean isEmptyFront() {
        return front.isEmpty();
    }

    // Check if the back of the deque is empty.
    public boolean isEmptyBack() {
        return back.isEmpty();
    }

    // Push a byte to the back of the deque.
    public void pushBack(byte v) {
        back.add(v);
    }

    // Push a byte to the front of the deque.
    public void pushFront(byte v) {
        front.add(v);
    }

    // Pop a byte from the back of the deque, or from the front if the back is empty.
    public boolean popBack(Byte[] v) {
        if (!isEmptyBack()) {
            v[0] = back.remove(back.size() - 1);
            return true;
        } else if (!isEmptyFront()) {
            v[0] = front.remove(0);
            return true;
        } else {
            return false; // Return false if both front and back are empty.
        }
    }

    // Pop a byte from the front of the deque, or from the back if the front is empty.
    public boolean popFront(Byte[] v) {
        if (!isEmptyFront()) {
            v[0] = front.remove(front.size() - 1);
            return true;
        } else if (!isEmptyBack()) {
            v[0] = back.remove(0);
            return true;
        } else {
            return false; // Return false if both front and back are empty.
        }
    }

    // Get a byte at a specific index in the deque.
    public byte get(int idx) {
        int tot = front.size() + back.size();
        if (idx < tot) {
            if (idx < front.size()) {
                return front.get(front.size() - 1 - idx); // Access from the front.
            } else {
                return back.get(idx - front.size()); // Access from the back.
            }
        }
        return 0; // Return 0 if index is out of bounds.
    }
}

// Define an operation structure to hold the operation type and character.
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

// Reverse a string and return the reversed version.
public class Main {
    public static String rev(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    // Main function to execute the program logic.
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next(); // Read the initial string S.
        int Q = scanner.nextInt(); // Read the number of operations Q.
        Op[] ops = new Op[Q]; // Create an array to hold operations.

        // Read each operation and populate the ops array.
        for (int i = 0; i < Q; i++) {
            int q = scanner.nextInt();
            if (q == 1) {
                ops[i] = new Op(true, false, (byte) 0); // Mark operation as reverse.
            } else {
                int f = scanner.nextInt();
                byte c = scanner.next().getBytes()[0]; // Read front/back flag and character.
                ops[i] = new Op(false, f == 1, c); // Mark operation as front insertion.
            }
        }

        // Prepare a sum array to track the number of reversals.
        int[] sum = new int[Q + 1];
        for (int i = Q - 1; i >= 1; i--) {
            if (ops[i].rev) {
                sum[i - 1] = sum[i] + 1; // Increment count if operation is reverse.
            } else {
                sum[i - 1] = sum[i]; // Carry forward the count if not reverse.
            }
        }

        // Reverse the string S if the total number of reversals is odd.
        if (sum[0] % 2 == 1) {
            S = rev(S);
        }

        Deque deq = new Deque(); // Initialize a deque to manage character insertions.
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) { // Process only non-reverse operations.
                if (ops[i].front) {
                    if (sum[i] % 2 == 1) {
                        deq.pushBack(ops[i].c); // Push to back if the reversal count is odd.
                    } else {
                        deq.pushFront(ops[i].c); // Push to front if the reversal count is even.
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.pushFront(ops[i].c); // Push to front if the reversal count is odd.
                    } else {
                        deq.pushBack(ops[i].c); // Push to back if the reversal count is even.
                    }
                }
            }
        }

        // Output the characters in the correct order.
        StringBuilder result = new StringBuilder();
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            result.append((char) deq.front.get(i).byteValue()); // Print front characters in reverse order.
        }
        result.append(S); // Print the original string S.
        for (int i = 0; i < deq.back.size(); i++) {
            result.append((char) deq.back.get(i).byteValue()); // Print back characters in order.
        }
        System.out.println(result.toString()); // Print the final result.
    }
}
// <END-OF-CODE>
