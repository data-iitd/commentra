import java.util.*;

public class Main {
    // Constants
    static final int MOD = (int) 1e9 + 7;
    static final long INF = 1L << 60;

    // Monster class to represent a monster with position x and health h
    static class Mon {
        int x, h;

        Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    // Node class to represent a position and damage
    static class Node {
        int x, h;

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }
    }

    // Queue class to manage Nodes
    static class Queue {
        LinkedList<Node> arr = new LinkedList<>();

        void push(Node v) {
            arr.add(v);
        }

        Node first() {
            return arr.getFirst();
        }

        Node pop() {
            return arr.removeFirst();
        }

        boolean isEmpty() {
            return arr.isEmpty();
        }
    }

    // Function to calculate the ceiling of a/b
    static int ceil(int a, int b) {
        return (a % b == 0) ? a / b : a / b + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();
        Mon[] M = new Mon[N];

        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(M, Comparator.comparingInt(m -> m.x)); // Sort monsters by their position

        Queue q = new Queue(); // Initialize a queue to manage damage
        long ans = 0; // Variable to count the total number of attacks
        long total = 0; // Variable to track total damage dealt

        // Iterate through each monster
        for (int i = 0; i < N; i++) {
            Mon m = M[i]; // Get the current monster
            // Remove monsters from the queue that are out of range
            while (!q.isEmpty() && q.first().x < m.x) {
                total -= q.pop().h; // Decrease total damage by the damage of the popped monster
            }
            // If the total damage is less than the monster's health
            if (total < m.h) {
                m.h -= total; // Reduce the monster's health by total damage
                int count = ceil(m.h, A); // Calculate how many attacks are needed
                ans += count; // Increment the total attack count
                long damage = (long) count * A; // Calculate the total damage dealt to this monster
                q.push(new Node(m.x + 2 * D, (int) damage)); // Add the monster's damage to the queue
                total += damage; // Update the total damage
            }
        }

        System.out.println(ans); // Output the total number of attacks
    }
}
