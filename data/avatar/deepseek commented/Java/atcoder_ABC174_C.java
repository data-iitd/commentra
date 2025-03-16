import java.io.* ; 
import java.util.* ; 

public class Main { 
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    private static final PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
    private static StringTokenizer st; 

    // Reads an integer from the standard input using a StringTokenizer.
    private static int readInt() throws IOException { 
        while (st == null || !st.hasMoreTokens()) 
            st = new StringTokenizer(br.readLine()); 
        return Integer.parseInt(st.nextToken()); 
    } 

    // The main method is the entry point of the program.
    public static void main(String[] args) throws IOException { 
        pw.println(solve()); 
        pw.close(); 
    } 

    // This method contains the logic to solve the problem.
    private static int solve() throws IOException { 
        int K = readInt(); 

        // Check if K is divisible by 2 or 5, return -1 if true.
        if (K % 2 == 0 || K % 5 == 0) 
            return -1; 

        // If K is divisible by 7, divide K by 7.
        if (K % 7 == 0) 
            K /= 7; 

        // Multiply K by 9.
        K *= 9; 

        // Initialize the answer and the remainder.
        int ans = 1; 
        int remainder = 10 % K; 

        // Loop to find the number of digits required to form a number that is a multiple of K.
        while (remainder != 1) { 
            ans++; 
            remainder = remainder * 10 % K; 
        } 

        return ans; 
    } 
}
