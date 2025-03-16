import java.util.*;
import java.io.*;

public class Main {

    /**
     * Constructor to initialize input, output, and test number
     * @param in FastScanner for reading input
     * @param out PrintWriter for writing output
     * @param test test number for multiple test cases
     */
    public Main(FastScanner in, PrintWriter out, int test) {

        /** Read the number of elements in the array */
        int N = in.nextInt();

        /** Initialize an integer array A of size N */
        int[] A = new int[N];

        /** Read all elements of array A */
        for (int i = 0; i < N; i++)
            A[i] = in.nextInt();

        /** Sort the array A in ascending order */
        Arrays.sort(A);

        /** Initialize the result variable res to 0 */
        long res = 0;

        /** Create an empty PriorityQueue q */
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt((int[] e) -> Math.min(e[0], e[1])).reversed());

        /** Add the last element of array A and its index to the queue */
        q.add(new int[]{A[N - 1], A[N - 1]});

        /** Iterate through the array A from the second last element to the first */
        for (int i = N - 2; i >= 0; i--) {

            /** Read the current element a from the array A */
            int a = A[i];

            /** Remove the first element from the queue */
            int[] place = q.remove();

            /** Add the result of the minimum of the first and second elements of the removed element to the result */
            res += Math.min(place[0], place[1]);

            /** Add the current element a and its index to the queue */
            q.add(new int[]{place[0], a});

            /** Add the current element a and the index of the removed element to the queue */
            q.add(new int[]{a, place[1]});
        }

        /** Print the result */
        out.println(res);
    }

    /**
     * Main method to start the program
     * @param args command line arguments (not used in this program)
     */
    public static void main(String[] args) {

        /** Initialize the PrintWriter out and FastScanner in */
        PrintWriter out = new PrintWriter(System.out);
        // FastScanner in = new FastScanner(new BufferedReader(new InputStreamReader(System.in)));
        FastScanner in = new FastScanner(System.in);

        /** Run the program for a single test case */
        for (int t = 1; t <= 1; t++) {
            Main sol = new Main(in, out, t);
        }

        /** Close the output stream */
        out.close();
    }
}

class FastScanner{
    /**
     * Constructor to initialize the input stream
     * @param stream InputStream for reading input
     */
    public FastScanner(InputStream stream)
    {
        this.stream = stream;
    }

    /**
     * Read a single character from the input stream
     * @return the next character in the input stream
     */
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

    /**
     * Check if the current character is a whitespace character
     * @param c the current character
     * @return true if the character is a whitespace character, false otherwise
     */
    boolean isSpaceChar(int c)
    {
        return c==' '||c=='\n'||c=='\r'||c=='\t'||c==-1;
    }

    /**
     * Check if the current character is an endline character
     * @param c the current character
     * @return true if the character is an endline character, false otherwise
     */
    boolean isEndline(int c)
    {
        return c=='\n'||c=='\r'||c==-1;
    }

    /**
     * Read an integer from the input stream
     * @return the next integer in the input stream
     */
    int nextInt()
    {
        return Integer.parseInt(next());
    }

    /**
     * Read a long integer from the input stream
     * @return the next long integer in the input stream
     */
    long nextLong()
    {
        return Long.parseLong(next());
    }

    /**
     * Read a double from the input stream
     * @return the next double in the input stream
     */
    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    /**
     * Read a string from the input stream
     * @return the next string in the input stream
     */
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

    /**
     * Read a line from the input stream
     * @return the next line in the input stream
     */
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