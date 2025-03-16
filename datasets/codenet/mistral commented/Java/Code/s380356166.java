
import java.io.BufferedReader;
import java.util.Arrays;

// The main method is the entry point of the Java program.
// It initializes the input and output streams, creates an instance of the Solver class,
// and calls its solve method with the test number, input, and output as arguments.
public static void main(String[] args) {
    InputStream inputStream = System.in;
    OutputStream outputStream = System.out;
    MyInput in = new MyInput(inputStream);
    PrintWriter out = new PrintWriter(outputStream);
    
    Solver solver = new Solver();
    solver.solve(1, in, out);
    
    out.close();
}

// The Solver class contains a single method, solve, which will solve the problem.
static class Solver {
    
    // The solve method takes three arguments: the test number, input, and output.
    // It initializes some variables and then calls the solve method recursively with smaller values.
    public void solve(int testNumber, MyInput in, PrintWriter out) {
        int ans = 0;
        int K = in.nextInt();
        int S = in.nextInt();
        int wk = 0;
        
        // The outer loop iterates from 0 to K for x.
        for(int x=0; x <= K; x++) {
            // The inner loop iterates from 0 to K for y.
            for(int y=0; y <= K; y++) {
                // wk is calculated as S - x - y.
                wk = S - x - y;
                
                // If wk is within the range of K, increment the answer.
                if(wk >= 0 && wk <= K) {
                    ans++;
                }
            }
        }
        
        // Print the answer.
        out.println(ans);
    }
}

// The Pair class is an extension of AbstractMap.SimpleEntry and provides a getString method.
static class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {
    // The getString method returns a string representation of the pair.
    public String getString() {
        return "[" + getKey() + "] [" + getValue() + "]";
    }
}

// The MyInput class reads input from the given input stream and provides methods for reading different types of input.
static class MyInput {
    // The constructor takes an InputStream as an argument and initializes the input reader.
    public MyInput(InputStream is) {
        in = new BufferedReader(new InputStreamReader(is));
    }
    
    // The read method reads a single character from the input stream.
    public int read() {
        // Implementation of the read method goes here.
    }
    
    // The nextInt method reads an integer from the input stream.
    public int nextInt() {
        // Implementation of the nextInt method goes here.
    }
    
    // The nextLong method reads a long integer from the input stream.
    public long nextLong() {
        // Implementation of the nextLong method goes here.
    }
    
    // The nextString method reads a string from the input stream.
    public String nextString() {
        // Implementation of the nextString method goes here.
    }
    
    // The nextDChar method reads a delimiter-separated string from the input stream.
    public char[] nextDChar() {
        // Implementation of the nextDChar method goes here.
    }
    
    // The nextChar method reads a single character from the input stream.
    public char nextChar() {
        // Implementation of the nextChar method goes here.
    }
}