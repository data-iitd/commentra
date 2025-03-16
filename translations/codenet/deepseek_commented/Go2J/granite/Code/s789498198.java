
import java.util.*;

public class s789498198{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        if ((A + B) % 2 == 0) {
            System.out.println((A + B) / 2);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}

// s789498198 function of the program
public static void main(String[] args) {
    // Read two integers A and B from standard input
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If even, print the average of A and B
        System.out.println((A + B) / 2);
    } else {
        // If not even, print "IMPOSSIBLE"
        System.out.println("IMPOSSIBLE");
    }
}

// Initialize the scanner with default settings
private static Scanner sc = new Scanner(System.in);

// Scanner type for reading input efficiently
private static class Scanner {
    private BufferedReader br;
    private StringTokenizer st;

    public Scanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
        eat("");
    }

    private void eat(String s) {
        st = new StringTokenizer(s);
    }

    public String nextLine() {
        try {
            return br.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public boolean hasNext() {
        while (!st.hasMoreTokens()) {
            String s = nextLine();
            if (s == null)
                return false;
            eat(s);
        }
        return true;
    }

    public String next() {
        hasNext();
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
}

// Check if the current cursor position is beyond the buffer length
private static boolean isFull() {
    return cur == buf.length;
}

// Reset the cursor position to the beginning of the buffer
private static void resetCur() {
    cur = 0;
}

// Get the next token from the buffer
private static String next() {
    if (isFull()) {
        readln();
    }
    res = buf[cur];
    cur++;
    if (isFull()) {
        resetCur();
    }
    return res;
}

// Get all remaining tokens as a slice of strings
private static String[] nexts() {
    readln();
    resetCur();
    return buf;
}

// Get the next token as an integer
private static int nextInt() {
    if (isFull()) {
        readln();
    }
    res = Integer.parseInt(buf[cur]);
    cur++;
    if (isFull()) {
        resetCur();
    }
    return res;
}

// Get all remaining tokens as a slice of integers
private static int[] nextInts() {
    readln();
    res = new int[buf.length];
    for (int i = 0; i < buf.length; i++) {
        res[i] = Integer.parseInt(buf[i]);
    }
    resetCur();
    return res;
}

// Get the next token as a float
private static float nextFloat() {
    if (isFull()) {
        readln();
    }
    res = Float.parseFloat(buf[cur]);
    cur++;
    if (isFull()) {
        resetCur();
    }
    return res;
}

// Get all remaining tokens as a slice of floats
private static float[] nextFloats() {
    readln();
    res = new float[buf.length];
    for (int i = 0; i < buf.length; i++) {
        res[i] = Float.parseFloat(buf[i]);
    }
    resetCur();
    return res;
}

// Calculate the number of digits in an integer
private static int digits(int x) {
    return String.valueOf(x).length();
}

// Calculate x raised to the power of p
private static int powInt(int x, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= x;
    }
    return result;
}

// Return the maximum of two integers
private static int max(int x, int y) {
    return (int) Math.max(x, y);
}

// Return the minimum of two integers
private static int min(int x, int y) {
    return (int) Math.min(x, y);
}

// Return the absolute value of an integer
private static int abs(int x) {
    return (int) Math.abs(x);
}

// Print the variable in a debug-friendly format
private static void varDump(Object... value) {
    for (Object v : value) {
        System.err.printf("%s%n", v);
    }
}

// Print "Yes" to standard output
private static void yes() {
    System.out.println("Yes");
}

// Print "No" to standard output
private static void no() {
    System.out.println("No");
}

// Pair struct to hold two integers
private static class Pair {
    int first;
    int second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

// Queue struct to hold a slice of Pairs
private static class Queue {
    private Pair[] v;
    private int head;
    private int tail;

    public Queue(int capacity) {
        v = new Pair[capacity];
        head = 0;
        tail = 0;
    }

    public void push(Pair value) {
        v[tail] = value;
        tail = (tail + 1) % v.length;
    }

    public Pair pop() {
        Pair res = v[head];
        head = (head + 1) % v.length;
        return res;
    }

    public Pair front() {
        return v[head];
    }

    public boolean empty() {
        return head == tail;
    }
}

// Translate the above Java code to Python and end with comment "