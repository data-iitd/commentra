import java.util.*;
import java.io.*;

// Node represents a node in the priority queue with x-coordinate and damage
class Node {
    int x, h;

    Node(int x, int h) {
        this.x = x;
        this.h = h;
    }
}

// Main class
public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize a BufferedReader for input and a BufferedWriter for output
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read input values N, D, and A
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int A = Integer.parseInt(st.nextToken());

        // Initialize a list of Mon objects
        List<Mon> M = new ArrayList<>();

        // Read x and h values for each Mon and store them in the M list
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());
            M.add(new Mon(x, h));
        }

        // Sort the M list based on x-coordinates
        Collections.sort(M);

        // Initialize a priority queue for Nodes
        PriorityQueue<Node> q = new PriorityQueue<>(Comparator.comparingInt(node -> node.x));

        // Initialize answer variable ans to 0 and total variable total to 0
        long ans = 0;
        long total = 0;

        // Iterate through each Mon in the sorted M list
        for (Mon m : M) {
            // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
            while (!q.isEmpty() && q.peek().x < m.x) {
                // Pop the first Node from the priority queue
                total -= q.poll().h;
            }

            // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
            if (total < m.h) {
                long damage = m.h - total;
                ans += damage;
                q.add(new Node(m.x + 2 * D, (int) damage));
                total += damage;
            }
        }

        // Print the answer
        bw.write(ans + "\n");

        // Flush the writer to output the answer
        bw.flush();
    }
}

// Mon represents a monster with x-coordinate and height
class Mon implements Comparable<Mon> {
    int x, h;

    Mon(int x, int h) {
        this.x = x;
        this.h = h;
    }

    @Override
    public int compareTo(Mon other) {
        return Integer.compare(this.x, other.x);
    }
}

// <END-OF-CODE>
