import java.util.*; 
import java.io.*; 
import static java.lang.Math.*; 

public class Main { 
    // FastReader for efficient input reading
    public static FastReader in = new FastReader(); 
    public static PrintWriter out = new PrintWriter(System.out); 

    public static void main(String[] args) { 
        // Read the dimensions of the grid
        int n = in.nextInt(), m = in.nextInt(); 
        
        // Initialize sets to keep track of banned rows and columns
        Set<Integer> bannedRows, bannedCols; 
        bannedRows = new HashSet<>(); 
        bannedCols = new HashSet<>(); 
        
        // Read the banned rows and columns
        for (int i = 0; i < m; i++) { 
            int r = in.nextInt(); 
            // Add to bannedRows if the row is within valid range
            if (r > 1 && r < n) bannedRows.add(r); 
            int c = in.nextInt(); 
            // Add to bannedCols if the column is within valid range
            if (c > 1 && c < n) bannedCols.add(c); 
        } 
        
        // Calculate the initial answer based on the grid size
        int answer = (n - 2) * 2; 
        // Subtract the number of banned rows and columns from the answer
        answer -= bannedRows.size(); 
        answer -= bannedCols.size(); 
        
        // If n is odd, check the middle row and column
        if (n % 2 != 0) { 
            int mid = (n + 1) / 2; 
            // If the middle row and column are not banned, decrement the answer
            if (!bannedRows.contains(mid) && !bannedCols.contains(mid)) { 
                answer--; 
            } 
        } 
        
        // Output the final answer
        out.println(answer); 
        out.close(); 
    } 

    // FastReader class for efficient input handling
    public static class FastReader { 
        BufferedReader br; 
        StringTokenizer st; 
        
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        
        // Method to read the next token
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
        
        // Method to read the next integer
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read the next long
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        
        // Method to read the next double
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        
        // Method to read the next line
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
