import java.math.*;
import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
    // The main method is the entry point of the Java application.
    @Override
    public void run() {
        try {
            // Initialize the Solver object and call its solve method to start the problem solving process.
            new Solver().solve();
            // Exit the Java Virtual Machine with an exit code of 0 to indicate successful execution.
            System.exit(0);
        } catch (Exception | Error e) {
            // Print the stack trace of any exception or error that occurred during the execution.
            e.printStackTrace();
            // Exit the Java Virtual Machine with an exit code of 1 to indicate unsuccessful execution.
            System.exit(1);
        }
    }

    // The main method is the entry point of the Java application, but it is empty in this case.
    // Instead, we call the run method of the Main object to start the problem solving process.
    public static void main(String[] args) {
        // Create a new instance of the Main class and call its run method to start the problem solving process.
        new Main().run();
    }
}

class Solver {
    // Declare instance variables for Helper, maximum number limit, modulus, timer, and timer task.
    final Helper hp;
    final int MAXN = 1000_006;
    final long MOD = (long) 1e9 + 7;
    final Timer timer;
    final TimerTask task;

    // Initialize the Helper and timer-related objects in the constructor.
    Solver() {
        hp = new Helper(MOD, MAXN);
        hp.initIO(System.in, System.out);

        // Initialize the timer and timer task objects.
        timer = new Timer();
        task = new TimerTask() {
            // Implement the run method of the timer task to flush the output and exit the Java Virtual Machine.
            @Override
            public void run() {
                try {
                    hp.flush();
                    // Exit the Java Virtual Machine with an exit code of 0 to indicate successful execution.
                    System.exit(0);
                } catch (Exception e) {
                }
            }
        };
        // Schedule the timer task to run after a certain delay.
        //timer.schedule(task, 4700);
    }

    // Declare a boolean flag for test cases and a method to solve a single test case.
    boolean TESTCASES = false;

    // Solve all the test cases by calling the solve method for each test case.
    void solve() throws Exception {
        int tc = TESTCASES ? hp.nextInt() : 1;
        // Declare a loop variable for the number of test cases.
        for (int tce = 1; tce <= tc; ++tce) {
            // Solve a single test case by calling the solve method with the test case number as an argument.
            solve(tce);
        }
        // Cancel the timer task to avoid unnecessary output flushing and exit the Java Virtual Machine.
        timer.cancel();
        hp.flush();
    }

    // Solve a single test case by reading input and calling the appropriate method to compute the solution.
    void solve(int tc) throws Exception {
        int i, j, k;

        // Read the input for the number of elements and the sum of elements.
        int N = hp.nextInt();
        long K = hp.nextLong();
        // Read the input for the array elements.
        int[] A = hp.getIntArray(N);

        // Initialize empty ArrayLists for storing the elements in straight and cycle sequences.
        ArrayList<Integer> straight = new ArrayList<>(), cycle = new ArrayList<>();
        // Initialize a boolean array to keep track of visited elements.
        boolean[] vis = new boolean[N];
        // Initialize a variable to store the current element index.
        int curr = 0;

        // Find the first element in the straight sequence by traversing the array from the given index.
        while (!vis[curr]) {
            vis[curr] = true;
            curr = A[curr] - 1;
        }

        // Initialize the starting index of the straight sequence.
        int st = 0;
        // Traverse the array from the starting index to find the elements in the straight sequence.
        while (st != curr) {
            straight.add(st);
            st = A[st] - 1;
        }

        // Add the first element of the cycle sequence to the ArrayList.
        cycle.add(curr);
        // Set the current element index to the next element in the array.
        curr = A[curr] - 1;

        // Traverse the array to find the remaining elements in the cycle sequence.
        while (curr != cycle.get(0)) {
            cycle.add(curr);
            curr = A[curr] - 1;
        }

        // Print the solution based on the length of the straight and cycle sequences.
        if (K < straight.size()) {
            hp.println(straight.get((int) K) + 1);
        } else {
            K -= straight.size();
            hp.println(cycle.get((int) (K % cycle.size())) + 1);
        }
    }
}

class Helper {
    // Declare instance variables for modulus, maximum number limit, and a random number generator.
    final long MOD;
    final int MAXN;
    final Random rnd;

    // Initialize the Helper object in the constructor.
    public Helper(long mod, int maxn) {
        MOD = mod;
        MAXN = maxn;
        rnd = new Random();
    }

    // Initialize the sieve of Eratosthenes and the factorial array in the Helper class.
    public void setSieve() {
        primes = new ArrayList<>();
        sieve = new int[MAXN];
        int i, j;
        for (i = 2; i < MAXN; ++i)
            if (sieve[i] == 0) {
                primes.add(i);
                for (j = i; j < MAXN; j += i) {
                    sieve[j] = i;
                }
            }
    }

    // Initialize the factorial array in the Helper class.
    public void setFactorial() {
        factorial = new long[MAXN];
        factorial[0] = 1;
        for (int i = 1; i < MAXN; ++i) factorial[i] = factorial[i - 1] * i % MOD;
    }

    // Declare methods for generating various types of arrays and strings.
    public long[] getLongArray(int size) throws Exception {
        long[] ar = new long[size];
        for (int i = 0; i < size; ++i) ar[i] = nextLong();
        return ar;
    }

    public int[] getIntArray(int size) throws Exception {
        int[] ar = new int[size];
        for (int i = 0; i < size; ++i) ar[i] = nextInt();
        return ar;
    }

    public String[] getStringArray(int size) throws Exception {
        String[] ar = new String[size];
        for (int i = 0; i < size; ++i) ar[i] = next();
        return ar;
    }

    // Declare methods for joining elements of various types of arrays and strings.
    public String joinElements(long... ar) {
        StringBuilder sb = new StringBuilder();
        for (long itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(int... ar) {
        StringBuilder sb = new StringBuilder();
        for (int itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(String... ar) {
        StringBuilder sb = new StringBuilder();
        for (String itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    public String joinElements(Object... ar) {
        StringBuilder sb = new StringBuilder();
        for (Object itr : ar) sb.append(itr).append(" ");
        return sb.toString().trim();
    }

    // Declare methods for finding the greatest common divisor and calculating the factorial.
    public long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public long pow(long base, long exp, long MOD) {
        base %= MOD;
        long ret = 1;
        while (exp > 0) {
            if ((exp & 1) == 1) ret = ret * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return ret;
    }

    // Declare methods for reading input from the standard input stream.
    private int scan() throws Exception {
        if (index >= total) {
            index = 0;
            total = in.read(buf);
            if (total <= 0)
                return -1;
        }
        return buf[index++];
    }

    public String next() throws Exception {
        int c;
        for (c = scan(); c <= 32; c = scan()) ;
        StringBuilder sb = new StringBuilder();
        for (; c > 32; c = scan())
            sb.append((char) c);
        return sb.toString();
    }

    public int nextInt() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? (int) -val : (int) val;
    }

    public long nextLong() throws Exception {
        int c;
        long val = 0;
        for (c = scan(); c <= 32; c = scan()) ;
        boolean neg = c == '-';
        if (c == '-' || c == '+')
            c = scan();
        for (; c >= '0' && c <= '9'; c = scan())
            val = (val << 3) + (val << 1) + (c & 15);
        return neg ? -val : val;
    }

    // Declare methods for writing output to the standard output stream.
    public void print(Object a) throws Exception {
        bw.write(a.toString());
    }

    public void printsp(Object a) throws Exception {
        print(a);
        print(" ");
    }

    public void println() throws Exception {
        bw.write("\n");
    }

    public void println(Object a) throws Exception {
        print(a);
        println();
    }

    public void flush() throws Exception {
        bw.flush();
    }
}