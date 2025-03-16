import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastReader sc = new FastReader(); // Initialize FastReader to read input
        PrintWriter out = new PrintWriter(System.out); // Initialize PrintWriter to provide output
        
        int n = sc.nextInt(); // Read the number of elements
        int a[] = new int[33]; // Initialize an array to count occurrences of bits set to 1
        
        // Count the number of bits set to 1 for each input number and store in array a
        for (int i = 0; i < n; i++) {
            a[rec(sc.nextInt())]++;
        }
        
        double answer = 0; // Initialize the answer variable
        
        // Calculate the answer based on the given formula
        for (int i = 0; i < a.length; i++) {
            double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
            answer += summ;
        }
        
        // Print the final answer in the required format
        out.println((long) answer);
        out.close(); // Close the PrintWriter
    }
    
    // Helper method to count the number of bits set to 1 in a given number
    static int rec(long x) {
        int answer = 0; // Initialize the count of bits set to 1
        for (int k = 31; k >= 0; k--) { // Iterate through each bit position
            if ((x & (1 << k)) != 0) { // Check if the k-th bit is set to 1
                answer++; // Increment the count if the bit is set
            }
        }
        return answer; // Return the count of bits set to 1
    }
    
    // FastReader class for fast input operations
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
        
        double nextDouble() {
            return Double.parseDouble(next());
        }
        
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
