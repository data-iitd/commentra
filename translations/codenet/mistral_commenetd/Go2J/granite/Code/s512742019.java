
import java.io.*;
import java.util.*;

public class s512742019{
    public static void main(String[] args) throws IOException {
        // Initialize a new Scanner and a PrintWriter for input/output
        Scanner sc = new Scanner(System.in);
        PrintWriter wtr = new PrintWriter(System.out);

        // Read input values N, D, and A from the scanner
        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();

        // Initialize a list of Mon objects called M
        List<Mon> M = new ArrayList<>();

        // Read x and h values for each Mon and store them in the M list
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int h = sc.nextInt();
            M.add(new Mon(x, h));
        }

        // Sort the M list based on x-coordinates
        Collections.sort(M);

        // Initialize a priority queue called q
        PriorityQueue<Node> q = new PriorityQueue<>();

        // Initialize answer variable ans to 0 and total variable total to 0
        int ans = 0;
        int total = 0;

        // Iterate through each Mon in the sorted M list
        for (Mon m : M) {
            // Current Mon
            int x = m.x;
            int h = m.h;

            // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
            while (!q.isEmpty() && q.peek().x < x) {
                // Pop the first Node from the priority queue
                total -= q.poll().h;
            }

            // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
            if (total < h) {
                int damage = h - total;
                ans += damage;
                q.add(new Node(x + 2 * D, damage));
                total += damage;
            }
        }

        // Print the answer
        wtr.println(ans);

        // Flush the writer to output the answer
        wtr.flush();
    }

    // Mon represents a monster with x-coordinate and height
    static class Mon implements Comparable<Mon> {
        int x, h;

        Mon(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Mon o) {
            return this.x - o.x;
        }
    }

    // Node represents a node in the priority queue with x-coordinate and damage
    static class Node implements Comparable<Node> {
        int x, h;

        Node(int x, int h) {
            this.x = x;
            this.h = h;
        }

        @Override
        public int compareTo(Node o) {
            return this.x - o.x;
        }
    }
}

