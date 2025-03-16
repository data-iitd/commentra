
import java.io.* ; 
import java.util.* ; 

public class Main { 
    // This method calculates a result based on a given string and character.
    private int cal(String s, char c) { 
        int n = s.length(); 
        int m = n - 1; 
        int ans = 0; 
        for (int i = 0; i < n; i++) { 
            if (s.charAt(i) == c && (m & i) == i) { 
                ans ^= 1; 
            } 
        } 
        return ans; 
    } 

    // This method is responsible for solving the problem by processing the input and outputting the result.
    private void solve() { 
        int n = sc.nextInt(); 
        String s = sc.next(); 
        StringBuilder sb = new StringBuilder(); 
        for (int i = 1; i < n; i++) { 
            sb.append(Math.abs(s.charAt(i) - s.charAt(i - 1))); 
        } 
        if (n == 2) { 
            out.println(sb.charAt(0)); 
            return; 
        } 
        s = sb.toString(); 
        if (s.contains("1")) { 
            out.println(cal(s, '1')); 
        } else { 
            out.println(cal(s, '2') * 2); 
        } 
    } 

    // This nested class handles input operations.
    private static PrintWriter out; 
    private static MyScanner sc; 

    private static class MyScanner { 
        BufferedReader br; 
        StringTokenizer st; 

        private MyScanner() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 

        // Reads the next token from the input.
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

        // Reads the next integer from the input.
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 

        // Reads the next long from the input.
        long nextLong() { 
            return Long.parseLong(next()); 
        } 

        // Reads the next double from the input.
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
    } 

    // The entry point of the program where objects are created and the solve method is called.
    public static void main(String[] args) { 
        out = new PrintWriter(new BufferedOutputStream(System.out)); 
        sc = new MyScanner(); 
        new Main().solve(); 
        out.close(); 
    } 
}
