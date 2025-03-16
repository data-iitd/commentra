import java.util.*;
import java.io.*;

public class Main {

    // Constructor to initialize the solution with input and output streams and the test case number
    public Main(FastScanner in, PrintWriter out, int test) {
        // Read the number of elements N
        int N = in.nextInt();
        // Initialize the array A with size N
        int[] A = new int[N];
        // Read N elements into the array A
        for (int i = 0; i < N; i++)
            A[i] = in.nextInt();
        // Sort the array A
        Arrays.sort(A);

        // Initialize the result variable to store the final result
        long res = 0;

        // Initialize a priority queue to keep track of pairs of integers
        // The queue is ordered by the minimum value of the pairs in descending order
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt((int[] e) -> Math.min(e[0], e[1])).reversed());
        // Add the pair (A[N-1], A[N-1]) to the priority queue
        q.add(new int[]{A[N - 1], A[N - 1]});

        // Iterate through the array A in reverse order starting from the second last element
        for (int i = N - 2; i >= 0; i--) {
            int a = A[i];
            // Remove the pair with the largest minimum value from the priority queue
            int[] place = q.remove();
            // Add the minimum value of the removed pair to the result
            res += Math.min(place[0], place[1]);
            // Add new pairs to the priority queue
            q.add(new int[]{place[0], a});
            q.add(new int[]{a, place[1]});
        }
        // Print the final result
        out.println(res);
    }

    // Main method to run the solution
    public static void main(String[] args) {
        // Initialize the output stream
        PrintWriter out = new PrintWriter(System.out);
        // Initialize the fast input scanner
        FastScanner in = new FastScanner(System.in);

        // For a single test case, create and solve the solution
        for (int t = 1; t <= 1; t++) {
            Main sol = new Main(in, out, t);
        }

        // Close the output stream
        out.close();
    }
}

// FastScanner class to read input efficiently
class FastScanner{
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public FastScanner(InputStream stream)
    {
        this.stream = stream;
    }

    // Read the next character
    int read()
    {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars){
            curChar = 0;
            try{
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    // Check if the character is a whitespace character
    boolean isSpaceChar(int c)
    {
        return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
    }

    // Check if the character is an end-of-line character
    boolean isEndline(int c)
    {
        return c=='\n'||c=='\r'||c==-1;
    }

    // Read the next integer
    int nextInt()
    {
        return Integer.parseInt(next());
    }

    // Read the next long
    long nextLong()
    {
        return Long.parseLong(next());
    }

    // Read the next double
    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    // Read the next string
    String next(){
        int c = read();
        while (isSpaceChar(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.appendCodePoint(c);
            c = read();
        }while(!isSpaceChar(c));
        return res.toString();
    }

    // Read the next line
    String nextLine(){
        int c = read();
        while (isEndline(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do{
            res.appendCodePoint(c);
            c = read();
        }while(!isEndline(c));
        return res.toString();
    }
}
