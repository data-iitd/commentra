// Import necessary packages
import java.util.*;

// Define a class for the deque (double ended queue)
class Deque {
    private LinkedList<Byte> front; // Front list to store elements
    private LinkedList<Byte> back;  // Back list to store elements

    // Constructor to initialize the deque
    public Deque() {
        front = new LinkedList<>();
        back = new LinkedList<>();
    }

    // Function to check if deque is empty at the front
    public boolean isEmptyFront() {
        return front.isEmpty();
    }

    // Function to check if deque is empty at the back
    public boolean isEmptyBack() {
        return back.isEmpty();
    }

    // Function to add an element at the back of the deque
    public void pushBack(byte v) {
        back.add(v);
    }

    // Function to add an element at the front of the deque
    public void pushFront(byte v) {
        front.add(v);
    }

    // Function to remove an element from the back of the deque and return it
    public boolean popBack(Byte[] v) {
        if (!isEmptyBack()) {
            v[0] = back.removeLast();
            return true;
        } else if (!isEmptyFront()) {
            v[0] = front.removeFirst();
            return true;
        }
        return false;
    }

    // Function to remove an element from the front of the deque and return it
    public boolean popFront(Byte[] v) {
        if (!isEmptyFront()) {
            v[0] = front.removeLast();
            return true;
        } else if (!isEmptyBack()) {
            v[0] = back.removeFirst();
            return true;
        }
        return false;
    }

    // Function to get an element from the deque by its index
    public byte get(int idx) {
        int tot = front.size() + back.size();
        if (idx < tot) {
            if (idx < front.size()) {
                return front.get(front.size() - 1 - idx);
            } else {
                return back.get(idx - front.size());
            }
        }
        return 0; // Return 0 if index is invalid
    }
}

// Main class to process the input and operations
public class Main {
    // Function to reverse a given string
    public static String rev(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    // Main function to read input and process it
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input string S
        String S = scanner.next();
        // Read the number of operations Q
        int Q = scanner.nextInt();
        
        // Initialize an array of operations
        Operation[] ops = new Operation[Q];
        
        // Read the operations one by one
        for (int i = 0; i < Q; i++) {
            int q = scanner.nextInt();
            if (q == 1) {
                ops[i] = new Operation(true, false, (byte) 0);
            } else {
                int f = scanner.nextInt();
                char c = scanner.next().charAt(0);
                ops[i] = new Operation(false, f == 1, (byte) c);
            }
        }
        
        // Initialize an array of sums
        int[] sum = new int[Q + 1];
        sum[Q] = 0;
        
        // Calculate the sums of operations
        for (int i = Q - 1; i >= 0; i--) {
            if (ops[i].rev) {
                sum[i] = sum[i + 1] + 1;
            } else {
                sum[i] = sum[i + 1];
            }
        }
        
        // Reverse the input string if necessary
        if (sum[0] % 2 == 1) {
            S = rev(S);
        }
        
        // Initialize an empty deque
        Deque deq = new Deque();
        
        // Process the operations
        for (int i = 0; i < Q; i++) {
            if (!ops[i].rev) {
                if (ops[i].front) {
                    if (sum[i] % 2 == 1) {
                        deq.pushFront(ops[i].c);
                    } else {
                        deq.pushBack(ops[i].c);
                    }
                } else {
                    if (sum[i] % 2 == 1) {
                        deq.pushBack(ops[i].c);
                    } else {
                        deq.pushFront(ops[i].c);
                    }
                }
            }
        }
        
        // Output the result
        StringBuilder result = new StringBuilder();
        
        // Write the characters in the front of the deque
        for (int i = deq.front.size() - 1; i >= 0; i--) {
            result.append((char) (byte) deq.front.get(i));
        }
        
        // Write the input string
        result.append(S);
        
        // Write the characters in the back of the deque
        for (int i = 0; i < deq.back.size(); i++) {
            result.append((char) (byte) deq.back.get(i));
        }
        
        // Print the result
        System.out.println(result.toString());
    }
}

// Class to represent an operation
class Operation {
    boolean rev; // Indicates if the operation is to reverse
    boolean front; // Indicates if the operation is to add at the front
    byte c; // Character to be added

    // Constructor for the operation
    public Operation(boolean rev, boolean front, byte c) {
        this.rev = rev;
        this.front = front;
        this.c = c;
    }
}

// <END-OF-CODE>
