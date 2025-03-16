
// I/O
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

// Helper functions for reading different data types from the scanner
class Scanner {
    BufferedReader br;
    StringTokenizer st;

    public Scanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next() {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return str;
    }
}

// Arithmetic
class Arithmetic {
    public static int max(int... nums) {
        int m = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (m < nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }

    public static int min(int... nums) {
        int m = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (m > nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }

    public static int abs(int x) {
        if (x > 0) {
            return x;
        } else {
            return -x;
        }
    }

    public static int pow(int x, int y) {
        int res = 1;
        for (int i = 0; i < y; i++) {
            res *= x;
        }
        return res;
    }

    public static int ceil(int a, int b) {
        if (a % b == 0) {
            return a / b;
        } else {
            return a / b + 1;
        }
    }
}

// Sort
class RuneSlice implements Comparable<RuneSlice> {
    char[] arr;

    public RuneSlice(char[] arr) {
        this.arr = arr;
    }

    public int length() {
        return arr.length;
    }

    public char charAt(int i) {
        return arr[i];
    }

    public int compareTo(RuneSlice o) {
        return arr[0] - o.arr[0];
    }
}

// Main
class Mon {
    int x, h;

    public Mon(int x, int h) {
        this.x = x;
        this.h = h;
    }
}

class Mons implements Comparable<Mons> {
    Mon[] arr;

    public Mons(Mon[] arr) {
        this.arr = arr;
    }

    public int length() {
        return arr.length;
    }

    public Mon get(int i) {
        return arr[i];
    }

    public int compareTo(Mons o) {
        return arr[0].x - o.arr[0].x;
    }
}

class Node {
    int x, h;

    public Node(int x, int h) {
        this.x = x;
        this.h = h;
    }
}

class Queue {
    Node[] arr;
    int size;

    public Queue() {
        arr = new Node[100000];
        size = 0;
    }

    public void push(Node v) {
        arr[size++] = v;
    }

    public Node first() {
        return arr[0];
    }

    public Node pop() {
        Node res = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        return res;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}

public class Main {
    public static void main(String[] args) {
        // Initialize a new Scanner and a BufferedWriter for input/output
        Scanner sc = new Scanner();
        BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read input values N, D, and A from the scanner
        int N = sc.nextInt();
        int D = sc.nextInt();
        int A = sc.nextInt();

        // Initialize a slice of Mon structures called M
        Mon[] M = new Mon[N];

        // Read x and h values for each Mon and store them in the M slice
        for (int i = 0; i < N; i++) {
            M[i] = new Mon(sc.nextInt(), sc.nextInt());
        }

        // Sort the M slice based on x-coordinates
        Mons mons = new Mons(M);
        java.util.Arrays.sort(mons.arr);

        // Initialize an empty priority queue called q
        Queue q = new Queue();

        // Initialize answer variable ans to 0 and total variable total to 0
        int ans = 0;
        int total = 0;

        // Iterate through each Mon in the sorted M slice
        for (int i = 0; i < N; i++) {
            // Current Mon
            Mon m = mons.get(i);

            // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
            while (!q.isEmpty() && q.first().x < m.x) {
                // Pop the first Node from the priority queue
                total -= q.pop().h;
            }

            // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
            if (total < m.h) {
                int damage = m.h - total;
                ans += damage;
                q.push(new Node(m.x + 2 * D, damage));
                total += damage;
            }
        }

        // Print the answer
        try {
            wtr.write(String.valueOf(ans));
            wtr.newLine();
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Flush the writer to output the answer
        try {
            wtr.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

