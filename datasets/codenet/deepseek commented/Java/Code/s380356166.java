// Importing necessary classes and static imports for comparator utilities
import java.io.BufferedReader;
import static java.util.Comparator.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.AbstractMap;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import static java.util.Comparator.*;

// Main class containing the main method which is the entry point of the program
public class Main {
    public static void main(String[] args) {
        // Setting up input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        MyInput in = new MyInput(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        // Creating an instance of Solver class to handle the problem-solving logic
        Solver solver = new Solver();
        solver.solve(1, in, out);
        
        // Closing the output stream
        out.close();
    }
}

// Solver class containing the solve method to solve the problem
static class Solver {
    // Solve method to find the number of ways to express S as the sum of three integers X, Y, and Z where each is <= K
    public void solve(int testNumber, MyInput in, PrintWriter out) {
        int ans = 0; // Variable to store the number of valid combinations
        int K = in.nextInt(); // Read the value of K
        int S = in.nextInt(); // Read the value of S
        int wk = 0; // Working variable to store intermediate results
        
        // Nested loops to iterate over possible values of X, Y, and Z
        for(int x=0; x <= K; x++) {
            for(int y=0; y <= K; y++) {
                wk = S - x - y; // Calculate the required value of Z
                if(wk >= 0 && wk <= K) { // Check if Z is within the valid range
                    ans++; // Increment the count of valid combinations
                }
            }
        }
        out.println(ans); // Output the result
    }
}

// Pair class extending AbstractMap.SimpleEntry to represent key-value pairs
static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
    /** serialVersionUID. */
    private static final long serialVersionUID = 6411527075103472113L;

    public Pair(final K key, final V value) {
        super(key, value);
    }
    
    // Method to get a string representation of the pair
    public String getString() {
        return "[" + getKey() + "] [" + getValue() + "]";
    }
}

// MyInput class for reading input from the standard input stream
static class MyInput {
    private final BufferedReader in;
    private static int pos;
    private static int readLen;
    private static final char[] buffer = new char[1024 * 8];
    private static char[] str = new char[500 * 8 * 2];
    private static boolean[] isDigit = new boolean[256];
    private static boolean[] isSpace = new boolean[256];
    private static boolean[] isLineSep = new boolean[256];

    static {
        for (int i = 0; i < 10; i++) {
            isDigit['0' + i] = true;
        }
        isDigit['-'] = true;
        isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
        isLineSep['\r'] = isLineSep['\n'] = true;
    }

    public MyInput(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
    }

    public int read() {
        if (pos >= readLen) {
            pos = 0;
            try {
                readLen = in.read(buffer);
            } catch (IOException e) {
                throw new RuntimeException();
            }
            if (readLen <= 0) {
                throw new MyInput.EndOfFileRuntimeException();
            }
        }
        return buffer[pos++];
    }

    public int nextInt() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        int ret = 0;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    public long nextLong() {
        int len = 0;
        str[len++] = nextChar();
        len = reads(len, isSpace);
        int i = 0;
        long ret = 0L;
        if (str[0] == '-') {
            i = 1;
        }
        for (; i < len; i++) ret = ret * 10 + str[i] - '0';
        if (str[0] == '-') {
            ret = -ret;
        }
        return ret;
    }

    public String nextString() {
        String ret = new String(nextDChar()).trim();
        return ret;
    }

    public char[] nextDChar() {
        int len = 0;
        len = reads(len, isSpace);
        char[] ret = new char[len + 1];
        for (int i=0; i < len; i++) ret[i] = str[i];
        ret[len] = 0x00;
        return ret;
    }

    public char nextChar() {
        while (true) {
            final int c = read();
            if (!isSpace[c]) {
                return (char) c;
            }
        }
    }

    int reads(int len, boolean[] accept) {
        try {
            while (true) {
                final int c = read();
                if (accept[c]) {
                    break;
                }
                if (str.length == len) {
                    char[] rep = new char[str.length * 3 / 2];
                    System.arraycopy(str, 0, rep, 0, str.length);
                    str = rep;
                }
                str[len++] = (char) c;
            }
        } catch (MyInput.EndOfFileRuntimeException e) {
        }
        return len;
    }

    static class EndOfFileRuntimeException extends RuntimeException {
    }
}