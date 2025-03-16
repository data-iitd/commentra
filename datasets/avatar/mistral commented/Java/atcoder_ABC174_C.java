
import java.io.* ;  // Importing necessary Java packages for input and output
import java.util.* ;

public class Main {
    // Declaring static variables for BufferedReader and PrintWriter
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    private static StringTokenizer st;
    private static int readInt() throws IOException {
        // Function to read an integer from the standard input
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        // Main function to call the solve function and print the result
        pw.println(solve());
        pw.close();
    }

    private static int solve() throws IOException {
        // Function to find the answer
        int K = readInt(); // Reading the input value of K

        // Checking if K is even or multiple of 5, returning -1 if true
        if (K % 2 == 0 || K % 5 == 0) return -1;

        // If K is multiple of 7, dividing it by 7 and multiplying it by 9
        if (K % 7 == 0) K /= 7;
        K *= 9;

        // Initializing the answer variable and the remainder variable
        int ans = 1, remainder = 10 % K;

        // Using a while loop to find the answer
        while (remainder != 1) {
            ans++; // Incrementing the answer variable
            remainder = remainder * 10 % K; // Updating the remainder variable
        }

        // Returning the answer
        return ans;
    }
}

These comments should help make the code more readable and understandable for anyone who reads it.